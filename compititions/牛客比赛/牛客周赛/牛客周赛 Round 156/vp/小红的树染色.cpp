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

struct HLD {
  int n;
  std::vector<int> siz, top, dep, parent, in, out, seq;
  std::vector<std::vector<int>> adj;
  int cur;

  HLD() {}
  HLD(int n) {
    init(n);
  }

  void init(int n) {
    this->n = n;
    siz.resize(n + 1);
    top.resize(n + 1);
    dep.resize(n + 1);
    parent.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    seq.resize(n + 1);
    cur = 1;
    adj.assign(n + 1, {});
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void work(int root = 1) {
    top[root] = root;
    dep[root] = 0;
    parent[root] = 0;
    dfs1(root);
    dfs2(root);
  }

  void dfs1(int u) {
    if (parent[u] != 0) {
      adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
    }

    siz[u] = 1;
    for (auto& v : adj[u]) {
      parent[v] = u;
      dep[v] = dep[u] + 1;
      dfs1(v);
      siz[u] += siz[v];
      if (siz[v] > siz[adj[u][0]]) {
        std::swap(v, adj[u][0]);
      }
    }
  }

  void dfs2(int u) {
    in[u] = cur++;
    seq[in[u]] = u;
    for (auto v : adj[u]) {
      top[v] = (v == adj[u][0]) ? top[u] : v;
      dfs2(v);
    }
    out[u] = cur;
  }

  int lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = parent[top[u]];
      } else {
        v = parent[top[v]];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

  int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int jump(int u, int k) {
    if (dep[u] < k) {
      return 0;
    }

    int d = dep[u] - k;
    while (dep[top[u]] > d) {
      u = parent[top[u]];
    }
    return seq[in[u] - dep[u] + d];
  }

  bool isAncestor(int u, int v) {
    return in[u] <= in[v] && in[v] < out[u];
  }

  int rootedParent(int u, int v) {
    std::swap(u, v);
    if (u == v) {
      return u;
    }
    if (!isAncestor(u, v)) {
      return parent[u];
    }
    auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v,
    [&](int x, int y) {
      return in[x] < in[y];
    }) - 1;
    return *it;
  }

  int rootedSize(int u, int v) {
    if (u == v) {
      return n;
    }
    if (!isAncestor(v, u)) {
      return siz[v];
    }
    return n - siz[rootedParent(u, v)];
  }

  int rootedLca(int a, int b, int c) {
    return lca(a, b) ^ lca(b, c) ^ lca(c, a);
  }
};

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  HLD hld(n);
  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;

    hld.addEdge(u, v);
  }
  hld.work();

  std::vector<int> red;
  for(int i = 0; i < n; i++){
    if(s[i] == '1'){
      red.push_back(i + 1);
    }
  }

  int a = red[0], b = red[0], d = 0;
  for(int i = 0; i < red.size(); i++){
    int cur = red[i];
    int da = hld.dist(cur, a);
    int db = hld.dist(cur, b);

    if(da < d && db < d){
      continue;
    }

    if(da >= db){
      b = cur;
      d = da;
    }else{
      a = cur;
      d = db;
    }
  }

  for(int i = 1; i <= n; i++){
    std::cout << std::max({d, hld.dist(i, a), hld.dist(i, b)}) << "\n";
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}