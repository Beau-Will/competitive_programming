#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int a;
  std::cin >> a;

  std::vector g(a + 1, std::vector(a + 1, std::vector<int>(a + 1)));
  for(int i = 0; i < a + 1; i++){
    for(int j = 0; j < a + 1; j++){
      for(int k = 0; k < a + 1; k++){
        std::cin >> g[i][j][k];
      }
    }
  }

  i64 ans = 0;
  for(int i = 0; i < a + 1; i++){
    ans += g[i][i][i];
    ans += g[a - i][i][i];
    ans += g[i][a - i][i];
    ans += g[a - i][a - i][i];
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