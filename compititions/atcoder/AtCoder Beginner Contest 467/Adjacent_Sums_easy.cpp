#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  for(int i = 1; i < n; i++){
    std::cin >> b[i];
  }

  std::vector dp(n + 1, std::vector<int>(2, inf1));
  if((a[1] + a[1 + 1]) % m != b[1]){
    dp[1][0] = 1;
    dp[1][1] = 1;
  }else{
    dp[1][0] = 0;
    dp[1][1] = 2;
  }

  for(int i = 2; i < n; i++){
    if((a[i] + a[i + 1]) % m != b[i]){
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] + 1;
    }else{
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1] + 1;
    }
  }

  int ans = std::min(dp[n - 1][0], dp[n - 1][1]);
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