#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

struct DSU{
  std::vector<int> f;

  DSU(int n){
    f.resize(n + 1);
    std::iota(f.begin(), f.end(), 0);
  }

  int find(int x){
    if(x != f[x]){
      f[x] = find(f[x]);
    }
    return f[x];
  }

  bool merge(int x, int y){
    int fx = find(x);
    int fy = find(y);

    if(fx == fy){
      return false;
    }
    f[fy] = fx;
    return true;
  }
};

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  int maxv = *std::max_element(a.begin() + 1, a.end());

  std::vector<int> at(maxv + 1, -1);
  for(int i = 1; i <= n; i++){
    at[a[i]] = i;
  }

  i64 ans = 0;
  DSU dsu(n);
  for(int d = maxv; d >= 1; d--){
    std::vector<int> b;
    for(int i = d; i <= maxv; i += d){
      if(~at[i]){
        b.push_back(at[i]);
      }
    }

    for(int i = 1; i < b.size(); i++){
      if(dsu.merge(b[0], b[i])){
        ans += d;
      }
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}