#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  int ans = 0;
  for(int i = 0; i < s.size(); i++){
    int cnt = 0;
    for(int d = 0; i - d >= 0 && i + d < s.size(); d++){
      if(s[i - d] == s[i + d]){
        
      }else{
        cnt++;
        if(cnt > 1){
          break;
        }
      }
      ans++;
    }
  }

  for(int i = 0; i + 1 < s.size(); i++){
    int cnt = 0;
    for(int d = 0; i - d >= 0 && i + 1 + d < s.size(); d++){
      if(s[i - d] == s[i + 1 + d]){

      }else{
        cnt++;
        if(cnt > 1){
          break;
        }
      }
      ans++;
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