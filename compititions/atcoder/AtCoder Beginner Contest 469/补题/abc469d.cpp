#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  using Node = std::array<int, 2>;
  std::vector<Node> a(m);
  for(int i = 0; i < m; i++){
    std::cin >> a[i][0] >> a[i][1];
  }

  auto check = [&](int u1, int v1){
    for(int i = 0; i < m; i++){
      const auto& [u2, v2] = a[i];
      if(u1 != u2 && u1 != v2 && v1 != u2 && v1 != v2){
        return 0;
      }
    }
    return 1;
  };

  auto count = [&](int x){
    for(int i = 0; i < m; i++){
      const auto& [u, v] = a[i];
      if(x != u && x != v){
        return check(x, u) + check(x, v);
      }
    }
    return n - 1;
  };

  std::cout << count(a[0][0]) + count(a[0][1]) - check(a[0][0], a[0][1]) << "\n";
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