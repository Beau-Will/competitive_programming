#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 1; i <= n; i++){
    int k;
    std::cin >> k;

    for(int j = 1; j <= k; j++){
      int x;
      std::cin >> x;

      adj[x].push_back(i);
    }
  }

  int cnt = 0;
  std::vector<int> ans(n + 1);
  std::vector<bool> vis(n + 1);

  auto dfs = [&](auto&& self, int u) -> bool {
    for(const auto& v : adj[u]){
      if(vis[v]){
        continue;
      }
      vis[v] = true;
      if(!ans[v] || self(self, ans[v])){
        ans[v] = u;
        return true;
      }
    }
    return false;
  };

  for(int i = 1; i <= n; i++){
    vis.assign(n + 1, false);
    if(dfs(dfs, i)){
      cnt++;
    }
  }

  if(cnt ^ n){
    std::cout << "kou is angry\n";
    return 0;
  }

  for(int i = 1; i <= n; i++){
    std::cout << ans[i] << " \n"[i == n];
  }

  return 0;
}