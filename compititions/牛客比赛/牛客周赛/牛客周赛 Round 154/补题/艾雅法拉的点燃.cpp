#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  i64 x, y;
  std::cin >> n >> x >> y;
  
  std::vector<int> a(n + 2);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  
  std::vector dp(51, std::vector<i64>(51, inf2));
  std::vector ndp(51, std::vector<i64>(51, inf2));
  dp[0][0] = 0;
  
  for(int i = 1; i <= n + 1; i++){
    for(int j = 0; j <= 50; j++){
      std::fill(ndp[j].begin(), ndp[j].end(), inf2);
    }
    
    for(int p = 0; p <= 50; p++){
      for(int q = 0; q <= 50; q++){
        if(dp[p][q] == inf2){
          continue;
        }
        
        for(int r = 0; r <= a[i]; r++){
          int t = std::max<int>(0, a[i - 1] - p - 2 * q - r);
          ndp[q][r] = std::min(ndp[q][r], dp[p][q] + t * x + r * y);
        }
      }
    }
    
    dp.swap(ndp);
  }
  
  i64 ans = inf2;
  for(int i = 0; i <= 50; i++){
    ans = std::min(ans, dp[i][0]);
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