#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector a(n + 1, std::vector<i64>(m + 1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      std::cin >> a[i][j];
    }
  }

  std::vector c(n + 1, std::vector<i64>(m + 1, inf));
  std::vector dp(n + 1, std::vector<i64>(m + 1, -inf));

  int t;
  std::cin >> t;
  for(int i = 0; i < t; i++){
    int x, y, v;
    std::cin >> x >> y >> v;

    c[x][y] = v;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(c[i][j] <= i + j - 2){
        a[i][j] = -inf * 2;
      }
    }
  }

  dp[1][0] = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    }
  }

  i64 ans = -1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      ans = std::max(ans, dp[i][j]);
    }
  }

  std::cout << ans << "\n";

  return 0;
}