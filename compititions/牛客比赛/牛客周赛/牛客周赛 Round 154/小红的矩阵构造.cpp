#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector ans(2, std::vector<int>(n));
  for(int i = 0; i < n; i++){
    ans[0][i] = i + 1;
    ans[1][i] = n - i;
  }

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      std::cout << ans[i][j] << " \n"[j + 1 == n];
    }
  }
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