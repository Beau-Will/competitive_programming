#include <iostream>
#include <vector>
#include <numeric>

struct DSU{
  std::vector<int> f, siz;

  DSU(int n){
    f.resize(n + 1);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n + 1, 1);
  }

  int find(int x){
    if(x != f[x]){
      f[x] = find(f[x]);
    }
    return f[x];
  }

  bool same(int u, int v){
    return find(u) == find(v);
  }

  bool merge(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu == fv){
      return false;
    }
    f[fv] = fu;
    siz[fu] += siz[fv];
    return true;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  DSU dsu(n);
  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;

    if(a[u] == a[v]){
      dsu.merge(u, v);
    }
  }

  int maxsiz = 0;
  for(int i = 1; i <= n; i++){
    if(dsu.siz[dsu.find(i)] > maxsiz){
      maxsiz = dsu.siz[i];
    }
  }

  std::vector<int> ans;
  for(int i = 1; i <= n; i++){
    if(dsu.siz[dsu.find(i)] == maxsiz){
      ans.push_back(i);
    }
  }

  std::cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }

  return 0;
}