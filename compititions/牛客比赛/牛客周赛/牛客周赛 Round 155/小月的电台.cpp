#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<i64> cnt((1 << m));
  for(int i = 0; i < n; i++){
    std::string s;
    std::cin >> s;

    int cur = 0;
    for(int j = m - 1; j >= 0; j--){
      if(s[j] == '1'){
        cur |= (1 << (m - 1 - j));
      }
    }
    cnt[cur]++;
  }

  i64 ans = static_cast<i64>(n - 1) * n / 2;
  for(int i = 0; i < (1 << m); i++){
    if(cnt[i] == 0){
      continue;
    }
    for(int j = i; j < (1 << m); j++){
      if(cnt[j] == 0){
        continue;
      }
      if((i & j) == 0){
        if(i == j){
          ans -= static_cast<i64>(cnt[i] - 1) * cnt[i] / 2;
        }else{
          ans -= static_cast<i64>(cnt[i]) * cnt[j];
        }
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