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
  int n;
  std::cin >> n;

  std::string s, t;
  std::cin >> s >> t;

  std::map<std::array<char, 2>, int> cnt;
  for(int i = 0; i < n; i++){
    cnt[{s[i], t[i]}]++;
  }

  int Rainbow = 0, Flower = 0;
  for(int i = 0; i < n; i++){
    if(i & 1){
      if(cnt[{'1', 'B'}]){
        cnt[{'1', 'B'}]--;
        Flower++;
      }else if(cnt[{'0', 'R'}]){
        cnt[{'0', 'R'}]--;
        Flower++;
      }else if(cnt[{'1', 'R'}]){
        cnt[{'1', 'R'}]--;
        Flower++;
      }else{
        cnt[{'0', 'B'}]--;
      }
    }else{
      if(cnt[{'0', 'R'}]){
        cnt[{'0', 'R'}]--;
        Rainbow++;
      }else if(cnt[{'1', 'B'}]){
        cnt[{'1', 'B'}]--;
        Rainbow++;
      }else if(cnt[{'0', 'B'}]){
        cnt[{'0', 'B'}]--;
        Rainbow++;
      }else{
        cnt[{'1', 'R'}]--;
      }
    }
  }

  if(Rainbow == Flower){
    std::cout << "Draw\n";
  }else if(Rainbow > Flower){
    std::cout << "Rainbow\n";
  }else{
    std::cout << "Flower\n";
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}