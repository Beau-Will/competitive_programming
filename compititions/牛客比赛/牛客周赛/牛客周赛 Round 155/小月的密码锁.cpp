#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::string s, t;
  std::cin >> s >> t;

  std::vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){
    a[i] = s[i] - 'A';
    b[i] = t[i] - 'A';
  }

  int ans = inf1;
  for(int i = 0; i < n; i++){
    for(int d1 = 0; d1 < 5; d1++){
      for(int d2 = 0; d2 < 5; d2++){
        std::vector<int> c = a;
        for(int j = 0; j <= i; j++){
          c[j] = (c[j] + d1) % 5;
        }
        for(int j = i + 1; j < n; j++){
          c[j] = (c[j] + d2) % 5;
        }
        int diff = 0;
        for(int j = 0; j < n; j++){
          if(b[j] != c[j]){
            diff++;
          }
        }
        ans = std::min(ans, diff);
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