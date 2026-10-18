#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9 + 7, P2 = 998'244'353;
constexpr double eps = 1E-10;
constexpr int inf = inf1;
// constexpr double pi = std::numbers::pi; // at least C++20
// constexpr double e = std::numbers::e; // at least C++20

void solve() {
  int n, m, a, b, s, t;
  std::cin >> n >> m >> a >> b >> s >> t;
  
  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  std::vector<int> dist1(n + 1, inf), dist2(n + 1, inf);
  
  auto bfs = [&](int start, std::vector<int>& dist) {
    std::vector<bool> vis(n + 1);
    std::queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    vis[start] = true;
    
    while (q.size()) {
      auto u = q.front();
      q.pop();
      
      for (const auto& v : adj[u]) {
        if (vis[v]) continue;
        dist[v] = dist[u] + 1;
        vis[v] = true;
        q.push(v);
      }
    }
  };
  
  bfs(a, dist1);
  bfs(b, dist2);
  
  std::vector<int> w(n + 1);
  for (int i = 1; i <= n; i++) {
    w[i] = std::abs(dist1[i] - dist2[i]);
  }
  
  std::vector<int> vis(n + 1, 0);
  int timer = 0;
  
  auto check = [&](int x) {
    if (w[s] > x || w[t] > x) return false;
    
    std::queue<int> q;
    q.push(s);
    timer++;
    vis[s] = timer;
    
    while (q.size()) {
      auto u = q.front();
      q.pop();
      
      if (u == t) return true;
      
      for (const auto& v : adj[u]) {
        if (w[v] > x || vis[v] == timer) continue;
        
        vis[v] = timer;
        q.push(v);
      }
    }
    
    return false;
  };
  
  int lo = 0, hi = n;
  
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  
  std::cout << lo << "\n";
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T; // multi cases

  for (int i = 1; i <= T; i++) solve();
}