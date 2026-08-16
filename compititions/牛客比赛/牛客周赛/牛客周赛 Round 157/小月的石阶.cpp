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

  std::vector<i64> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> diff(n + 1);
  for(int i = 2; i <= n; i++){
    diff[i] = std::abs(a[i] - a[i - 1]);
  }
  std::vector<i64> pre(n + 1);
  std::partial_sum(diff.begin(), diff.end(), pre.begin());

  int ans = 1;
  for(int l = 1, r = 1; r <= n; r++){
    while(l < r && pre[r] - pre[l] > k){
      l++;
    }
    ans = std::max(ans, r - l + 1);
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}