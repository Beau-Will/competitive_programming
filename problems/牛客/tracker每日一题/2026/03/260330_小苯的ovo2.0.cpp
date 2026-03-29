#include <iostream>
#include <vector>
#include <string>

using i64 = long long;

void solve(){
  std::string s;
  std::cin >> s;

  int n = s.size();
  int cnto = 0, cntx = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'o'){
      cnto++;
    }else if(s[i] == '?'){
      cntx++;
    }
  }

  i64 ans = 0;

  for(int t = cnto; t <= cnto + cntx; t++){
    std::vector<i64> dp(t + 1, -1);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
      char c = s[i];

      if(c == 'o'){
        for(int j = t; j >= 0; j--){
          if(j && dp[j - 1] != -1){
            dp[j] = dp[j - 1];
          }
        }
      }else if(c == 'v'){
        for(int j = t; j >= 0; j--){
          if(dp[j] != -1){
            dp[j] += 1LL * j * (t - j);
          }
        }
      }else{
        for(int j = t; j >= 0; j--){
          i64 tmpv = -1;
          i64 tmpo = -1;

          if(dp[j] != -1){
            tmpv = dp[j] + 1LL * j * (t - j);
          }
          if(j && dp[j - 1] != -1){
            tmpo = dp[j - 1];
          }

          dp[j] = std::max(tmpv, tmpo);
        }
      }
      if(dp[t] != -1){
        ans = std::max(ans, dp[t]);
      }
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int i = 0; i < T; i++){
    solve();
  }

  return 0;
}