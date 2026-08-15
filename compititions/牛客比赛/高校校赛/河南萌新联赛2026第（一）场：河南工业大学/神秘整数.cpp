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

// constexpr int int_max = std::numeric_limits<int>::max();
// constexpr i64 i64_max = std::numeric_limits<i64>::max();

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  std::set<int> set;
  for(int i = 0; i + 1 < n; i++){
    set.insert(a[i + 1] - a[i]);
  }

  auto check = [&](int x){
    for(const auto& ele : set){
      if(ele % x) return false;
    }
    return true;
  };

  int max = *set.rbegin();
  std::vector<int> ans;
  for(int i = 2; i <= max / i; i++){
    if(max % i == 0){
      if(check(i)){
        ans.push_back(i);
      }
      if(check(max / i)){
        ans.push_back(max / i);
      }
    }
  }
  if(max > 1 && check(max)){
    ans.push_back(max);
  }

  if(ans.empty()){
    std::cout << "-1\n";
    return;
  }

  std::sort(ans.begin(), ans.end());
  ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}