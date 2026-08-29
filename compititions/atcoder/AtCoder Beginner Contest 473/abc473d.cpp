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
  int n, k;
  std::cin >> n >> k;

  std::vector dp(n + 1, std::vector<bool>(k + 1));
  dp[n][0] = true;
  for(int i = n - 1; i >= 0; i--){
    int j = i + 1;
    for(int x = 0; x <= k; x++){
      dp[i][x] = dp[i + 1][x];
      if(x >= j && dp[i][x - j]){
        dp[i][x] = true;
      }
    }
  }

  std::vector<std::vector<std::vector<int>>> t(n);
  for(int i = 0; i < n; i++){
    int j = i + 1;
    t[i].resize(j);
    for(int x = k; x >= 0; x--){
      if(dp[i + 1][x]){
        int r = x % j;
        t[i][r].push_back(x);
      }
    }
  }

  std::vector<int> a(n);
  auto dfs = [&](auto&& self, int u, int rest) -> void {
    if(u == n){
      if(rest != 0) return;

      for(int i = 0; i < n; i++){
        std::cout << a[i] << " \n"[i + 1 == n];
      }
      return;
    }

    int v = u + 1;
    const auto& tmp = t[u][rest % v];

    int l = 0, r = tmp.size() - 1;
    while(l < r){
      int mid = (l + r) / 2;
      if(tmp[mid] <= rest){
        r = mid;
      }else{
        l = mid + 1;
      }
    }

    for(int i = l; i < tmp.size(); i++){
      int x = tmp[i];
      a[u] = (rest - x) / v;
      self(self, u + 1, x);
    }
  };

  dfs(dfs, 0, k);
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}