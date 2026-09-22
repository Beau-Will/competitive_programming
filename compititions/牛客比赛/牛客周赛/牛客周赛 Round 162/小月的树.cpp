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

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  s = ' ' + s;

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> par(n + 1), ord{1};
  for (int i = 0; i < n; i++) {
    int v = ord[i];
    for (int u : adj[v]) {
      if (u != par[v]) {
        par[u] = v;
        ord.push_back(u);
      }
    }
  }

  std::vector<int> b(n + 1), dp(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    int v = ord[i];
    dp[v] = 1;
    for (int u : adj[v]) {
      if (u != par[v]) {
        b[v] += b[u] + (s[u] != s[v]);
        if (b[u]) {
          dp[v] += dp[u];
        }
      }
    }
  }

  int ans = dp[1];
  for (int v = 2; v <= n; v++) {
    if (b[1] == b[v] + (s[v] != s[par[v]])) {
      ans = std::min(ans, dp[v]);
    }
  }
  
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for (int i = 1; i <= T; i++) solve();
}
