#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  int cntU = std::count(s.begin(), s.end(), 'U');
  int cntD = std::count(s.begin(), s.end(), 'D');
  int cntL = std::count(s.begin(), s.end(), 'L');
  int cntR = std::count(s.begin(), s.end(), 'R');

  std::string ans;
  if(cntU > cntD){
    if(cntL > cntR){
      for(int i = 0; i < n; i++){
        if(s[i] == 'D'){
          if(k){
            k--;
            continue;
          }
        }else if(s[i] == 'R'){
          if(k){
            k--;
            continue;
          }
        }
        ans.push_back(s[i]);
      }
    }else{
      for(int i = 0; i < n; i++){
        if(s[i] == 'D'){
          if(k){
            k--;
            continue;
          }
        }else if(s[i] == 'L'){
          if(k){
            k--;
            continue;
          }
        }
        ans.push_back(s[i]);
      }
    }
  }else{
    if(cntL > cntR){
      for(int i = 0; i < n; i++){
        if(s[i] == 'U'){
          if(k){
            k--;
            continue;
          }
        }else if(s[i] == 'R'){
          if(k){
            k--;
            continue;
          }
        }
        ans.push_back(s[i]);
      }
    }else{
      for(int i = 0; i < n; i++){
        if(s[i] == 'U'){
          if(k){
            k--;
            continue;
          }
        }else if(s[i] == 'L'){
          if(k){
            k--;
            continue;
          }
        }
        ans.push_back(s[i]);
      }
    }
  }

  while(k){
    ans.pop_back();
    k--;
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