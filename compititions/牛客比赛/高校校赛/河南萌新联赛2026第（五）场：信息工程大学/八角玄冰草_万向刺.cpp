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
  int n, m, l;
  std::cin >> n >> m >> l;

  std::vector g(n, std::vector<std::string>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      std::cin >> g[i][j];
    }
  }

  int sx = -1, sy = -1, sz = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < l; k++){
        if(g[i][j][k] == 'H'){
          sx = i, sy = j, sz = k;
        }
      }
    }
  }

  int ans = 0;
  using Node = std::array<int, 3>;
  std::set<Node> set;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < l; k++){
        if(g[i][j][k] != 'T') continue;

        int dx = sx - i, dy = sy - j, dz = sz - k;
        int gcd = std::gcd(std::gcd(dx, dy), dz);
        dx /= gcd, dy /= gcd, dz /= gcd;
        Node t = {dx, dy, dz};

        if(!set.count(t)){
          set.insert(t);
          ans++;
        }
      }
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}