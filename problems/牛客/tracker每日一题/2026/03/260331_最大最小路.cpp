#include <iostream>
#include <vector>
#include <array>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, a, b;
  std::cin >> n >> a >> b;

  std::vector<int> w(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> w[i];
  }

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  i64 ans = 0;

  auto get = [&](int x){
    if(w[x] <= a){
      return 1;
    }
    if(w[x] >= b){
      return 2;
    }
    return 0;
  };

  auto dfs = [&](auto&& self, int u, int f) -> std::array<int, 4> {
    std::array<int, 4> res = {};
    int st = get(u);
    res[st]++;
    for(const auto& v : adj[u]){
      if(v == f){
        continue;
      }
      auto&& tmp = self(self, v, u);
      ans += 1LL * res[0] * tmp[3] + 1LL * res[1] * (tmp[2] + tmp[3]) + 1LL * res[2] * (tmp[1] + tmp[3]) + 1LL * res[3] * (tmp[0] + tmp[1] + tmp[2] + tmp[3]);

      for(int i = 0; i < 4; i++){
        res[i | st] += tmp[i];
      }
    }
    return res;
  };

  dfs(dfs, 1, 0);

  std::cout << ans << "\n";

  return 0;
}