#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr double eps = 1E-10;
constexpr double pi = std::numbers::pi;
constexpr double e = std::numbers::e;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  int ans = 0;
  for(char c = 'a'; c <= 'z'; c++){
    std::string t;
    for(int i = 0; i < n; i++){
      if(s[i] == c){
        continue;
      }
      t.push_back(s[i]);
    }
    std::string rev_t = t;
    std::reverse(rev_t.begin(), rev_t.end());

    ans += (rev_t == t && t != s);
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++){
    solve();
  }

  return 0;
}