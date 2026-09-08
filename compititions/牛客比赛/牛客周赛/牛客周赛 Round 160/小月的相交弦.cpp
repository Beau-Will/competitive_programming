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
constexpr i64 inf = inf2;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::array<i64, 2>> map(2 * n + 1, {0, 0});
  for(int i = 0; i < n; i++){
    int l, r, w;
    std::cin >> l >> r >> w;

    map[l] = {r, w};
  }

  std::vector dp(2 * n + 2, std::vector<i64>(2 * n + 2));
  for(int len = 1; len <= 2 * n; len++){
    for(int l = 1; l + len - 1 <= 2 * n; l++){
      int r = l + len - 1;

      i64 cur = 0;
      if(l < r){
        cur = dp[l + 1][r];
      }

      if(map[l][0]){
        auto [t, w] = map[l];
        if(t <= r){
          i64 tmp = w;
          if(l + 1 <= t - 1){
            tmp += dp[l + 1][t - 1];
          }
          if(t + 1 <= r){
            tmp += dp[t + 1][r];
          }
          if(tmp > cur){
            cur = tmp;
          }
        }
      }
      dp[l][r] = cur;
    }
  }

  std::cout << dp[1][2 * n] << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}