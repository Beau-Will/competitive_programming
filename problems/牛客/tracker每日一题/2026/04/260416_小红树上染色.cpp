#include <iostream>
#include <vector>

constexpr int P = 1E9 + 7;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector dp(n + 1, std::vector<int>(2, 1));

  auto dfs = [&](auto&& self, int u, int f) -> void {
    for(const auto& v : adj[u]){
      if(v == f){
        continue;
      }
      self(self, v, u);
      dp[u][1] = 1LL * dp[u][1] * dp[v][0] % P;
      dp[u][0] = 1LL * dp[u][0] * (dp[v][1] + dp[v][0] % P) % P;
    }
  };

  dfs(dfs, 1, -1);

  std::cout << (dp[1][1] + dp[1][0]) % P << "\n";

  return 0;
}