#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> c(n, std::string(m, '?'));
  for(int i = 0; i < n; i++){
    std::cin >> c[i];
  }

  int red = 0, blue = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(c[i][j] == '#'){
        red++;
      }else{
        blue++;
      }
    }
  }

  if(!red){
    std::cout << "Blue\n";
    return;
  }

  if(!blue){
    std::cout << "Red\n";
    return;
  }

  std::vector vis(n, std::vector<bool>(m));
  constexpr std::array dx = {0, 0, -1, 1};
  constexpr std::array dy = {-1, 1, 0, 0};
  auto bfs = [&](int sx, int sy){
    int res = 0;
    std::vector vis2(n, std::vector<bool>(m));
    std::queue<std::array<int, 2>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    vis2[sx][sy] = true;

    while(q.size()){
      auto [x, y] = q.front();
      q.pop();

      for(int i = 0; i < 4; i++){
        int u = x + dx[i], v = y + dy[i];
        if(u < 0 || u >= n || v < 0 || v >= m || vis2[u][v]){
          continue;
        }
        vis2[u][v] = true;
        if(c[u][v] == '.'){
          res++;
        }else{
          vis[u][v] = true;
          q.push({u, v});
        }
      }
    }

    return res;
  };

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!vis[i][j] && c[i][j] == '#'){
        auto t = bfs(i, j);
        if(t == blue){
          std::cout << "Red\n";
          return;
        }
      }
    }
  }

  std::cout << "Draw\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}