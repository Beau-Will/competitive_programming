#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;
  
  std::string s;
  std::cin >> s;
  s = "?" + s;

  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(s[i] == '.'){
      bool isok = true;
      for(int j = std::max(1, i - m); j <= std::min(n, i + m); j++){
        if(s[j] == 'G'){
          isok = false;
          break;
        }
      }
      if(isok){
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