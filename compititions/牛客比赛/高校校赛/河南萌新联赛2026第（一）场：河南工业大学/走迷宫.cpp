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
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> g(n);
  for(int i = 0; i < n; i++){
    std::cin >> g[i];
  }

  int sx = -1, sy = -1, tx = -1, ty = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == 'S'){
        sx = i, sy = j;
      }
      if(g[i][j] == 'T'){
        tx = i, ty = j;
      }
    }
  }

  constexpr std::array<std::array<int, 2>, 4> delta = {{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}};

  auto encode = [&](int x, int y, int used){
    return used * n * m + x * m + y;
  };

  std::vector<int> dist(2 * n * m, -1);
  
  std::queue<int> q;
  int st = encode(sx, sy, 0);
  q.push(st);
  dist[st] = 0;

  while(q.size()){
    auto t1 = q.front();
    q.pop();
    int x1 = (t1 % (n * m)) / m;
    int y1 = (t1 % (n * m)) % m;
    int used = t1 / (n * m);

    if(x1 == tx && y1 == ty){
      std::cout << dist[t1] << "\n";
      return;
    }

    for(const auto& [dx, dy] : delta){
      int x2 = x1 + dx, y2 = y1 + dy;
      if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m){
        continue;
      }
      if(g[x2][y2] == '#'){
        if(!used){
          int t2 = encode(x2, y2, 1);
          if(dist[t2] == -1){
            dist[t2] = dist[t1] + 1;
            q.push(t2);
          }
        }
      }else{
        int t2 = encode(x2, y2, used);
        if(dist[t2] == -1){
          dist[t2] = dist[t1] + 1;
          q.push(t2);
        }
      }
    }
  }

  std::cout << "-1\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}