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
  int n, m;
  std::cin >> n >> m;

  using Node = std::array<int, 3>;
  std::vector<std::vector<Node>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int u, v, d, r;
    std::cin >> u >> v >> d >> r;

    adj[u].push_back({v, d, r});
  }

  std::vector<i64> dist(n + 1, inf), risk(n + 1, inf);
  auto dijkstra = [&](){
    using Info = std::tuple<i64, i64, int>;
    std::priority_queue<Info, std::vector<Info>, std::greater<>> heap;
    heap.push({0LL, 0LL, 1});
    dist[1] = 0LL;
    risk[1] = 0LL;

    while(heap.size()){
      auto [dis, ris, u] = heap.top();
      heap.pop();
      if(dis != dist[u] || ris != risk[u]) continue;

      for(const auto& [v, d, r] : adj[u]){
        i64 nd = dis + d, nr = ris + r;
        if(nd < dist[v] || (nd == dist[v] && nr < risk[v])){
          dist[v] = nd;
          risk[v] = nr;
          heap.push({nd, nr, v});
        }
      }
    }
  };

  dijkstra();

  if(dist[n] > inf / 2){
    std::cout << "-1 -1\n";
    return;
  }

  std::cout << dist[n] << " " << risk[n] << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}