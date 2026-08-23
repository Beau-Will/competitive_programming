#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr double eps = 1E-10;
// constexpr double pi = std::numbers::pi;
// constexpr double e = std::numbers::e;

void solve(){
  int n;
  i64 k;
  std::cin >> n >> k;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  auto check = [&](int len){
    std::unordered_map<int, int> cnt;
    for(int i = 1; i <= len; i++){
      cnt[a[i]]++;
    }
    i64 max = 0, sum = 0;
    for(const auto& [u, v] : cnt){
      sum += 1LL * (v - 1) * v / 2;
    }
    max = std::max(max, sum);
    for(int r = len + 1, l = 1; r <= n; l++, r++){
      cnt[a[r]]++;
      int prev = cnt[a[r]] - 1;
      sum -= 1LL * (prev - 1) * prev / 2;
      sum += 1LL * (cnt[a[r]] - 1) * cnt[a[r]] / 2;
      cnt[a[l]]--;
      prev = cnt[a[l]] + 1;
      sum -= 1LL * (prev - 1) * prev / 2;
      sum += 1LL * (cnt[a[l]] - 1) * cnt[a[l]] / 2;
      
      max = std::max(max, sum);
    }
    return max >= k;
  };

  int l = 2, r = n;
  while(l < r){
    int mid = (l + r) / 2;
    if(check(mid)){
      r = mid;
    }else{
      l = mid + 1;
    }
  }

  if(l == n && !check(l)){
    std::cout << "-1\n";
    return;
  }
  std::cout << l << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}