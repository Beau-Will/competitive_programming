#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr double eps = 1E-10;
constexpr double pi = std::numbers::pi;
constexpr double e = std::numbers::e;

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::vector<int> p(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> p[i];
  }
  std::vector<int> at(n + 1);
  for(int i = 1; i <= n; i++){
    at[p[i]] = i;
  }

  for(int i = 1; i <= q; i++){
    int op, x, y;
    std::cin >> op;

    if(op == 1){
      std::cin >> x >> y;

      std::swap(at[p[x]], at[p[y]]);
      std::swap(p[x], p[y]);
    }else{
      p.swap(at);
    }
  }

  for(int i = 1; i <= n; i++){
    std::cout << p[i] << " \n"[i == n];
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++){
    solve();
  }

  return 0;
}