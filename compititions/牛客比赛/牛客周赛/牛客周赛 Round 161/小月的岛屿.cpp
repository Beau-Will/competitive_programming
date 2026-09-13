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
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> g(n);
  for(int i = 0; i < n; i++){
    std::cin >> g[i];
  }

  std::vector vis(n, std::vector<bool>(m));
  using Node = std::array<int, 2>;
  std::queue<Node> q;
  constexpr std::array<std::array<int, 2>, 8> delta = {{{0, -1}, {0, 1}, {-1, 0}, {1, 0},
   {-1, 1}, {-1, -1}, {1, -1}, {1, 1}}};
  
  auto bfs = [&](int x, int y, int type){
    int siz = 0;
    vis[x][y] = true;
    q.push({x, y});

    while(q.size()){
      auto [x, y] = q.front();
      q.pop();
      siz++;

      for(int i = 0; i < type; i++){
        const auto& [dx, dy] = delta[i];
        int u = x + dx, v = y + dy;

        if(u < 0 || u >= n || v < 0 || v >= m || vis[u][v] || g[u][v] == '0') continue;

        vis[u][v] = true;
        q.push({u, v});
      }
      
    }

    return siz;
  };

  auto bfs4 = [&](){
    int cnt = 0, s = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(!vis[i][j] && g[i][j] == '1'){
          cnt++;
          s = std::max(s, bfs(i, j, 4));
        }
      }
    }
    return std::array{cnt, s};
  };

  auto bfs8 = [&](){
    for(int i = 0; i < n; i++){
      std::fill(vis[i].begin(), vis[i].end(), false);
    }
    while(q.size()) q.pop();

    int cnt = 0, s = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(!vis[i][j] && g[i][j] == '1'){
          cnt++;
          s = std::max(s, bfs(i, j, 8));
        }
      }
    }
    return std::array{cnt, s};
  };

  const auto& [c4, s4] = bfs4();
  const auto& [c8, s8] = bfs8();

  std::cout << c4 - c8 << " " << s4 << " " << s8 << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}