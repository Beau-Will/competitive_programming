#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'x'){
      if((!i || s[i - 1] == 'x') && (i + 1 == n || s[i + 1] == 'x')){
        ans++;
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