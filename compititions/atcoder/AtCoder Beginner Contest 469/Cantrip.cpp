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
  s = " " + s;

  std::vector<int> cnto(n + 1);
  for(int i = 1; i <= n; i++){
    cnto[i] = cnto[i - 1];
    if(s[i] == 'o'){
      cnto[i]++;
    }
  }

  int ans = 2, last = -1;
  for(int k = 1; k <= n; k++){
    int t;
    if(last == -1){
      t = (s[k] == 'o' ? 1 : 0);
    }else{
      t = last + 1;
    }
    while(t && ans <= n){
      t--;
      if(s[ans] == 'o'){
        t++;
      }
      ans++;
    }

    last = t;

    std::cout << ans - 1 << "\n";
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