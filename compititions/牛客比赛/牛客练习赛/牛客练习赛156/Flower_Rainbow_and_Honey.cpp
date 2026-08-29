#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr double eps = 1E-10;
// constexpr double pi = std::numbers::pi;
// constexpr double e = std::numbers::e;

void solve(){
  std::string s, t;
  std::cin >> s >> t;

  std::unordered_map<char, int> dx;
  dx['L'] = -1;
  dx['R'] = 1;

  for(int ans = -10; ans <= 10; ans++){
    int cur = ans;
    int dis1 = std::abs(cur);
    bool isok = true;
    for(int i = 0; i < s.size(); i++){
      cur += dx[s[i]];
      int dis2 = std::abs(cur);
      if(dis1 < dis2){
        if(t[i] != 'F'){
          isok = false;
          break;
        }
      }else{
        if(t[i] != 'C'){
          isok = false;
          break;
        }
      }
      dis1 = dis2;
    }

    if(isok){
      std::cout << ans << "\n";
      return;
    }
  }

  std::cout << "T_T\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}