#include <iostream>
#include <string>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr double eps = 1E-10;
// constexpr double pi = std::numbers::pi;
// constexpr double e = std::numbers::e;

// #include <limits>
// constexpr int int_max = std::numeric_limits<int>::max();
// constexpr i64 i64_max = std::numeric_limits<i64>::max();

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  bool isok = false;
  for(int i = 1; i < s.size() - 1; i++){
    if(s[i] != s[i - 1] && s[i] != s[i + 1] && s[i - 1] == s[i + 1]){
      s.erase(s.begin() + i);
      isok = true;
      break;
    }
  }

  if(!isok){
    for(int i = 1; i < s.size() - 1; i++){
      if(s[i] != s[i - 1] && s[i] != s[i + 1]){
        s.erase(s.begin() + i);
        isok = true;
        break;
      }
    }
  }

  if(!isok){
    s.erase(s.begin() + 1);
  }

  int ans = 0;
  char last = '?';
  for(int i = 0; i < s.size(); i++){
    if(s[i] != last){
      ans++;
      last = s[i];
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) {
    solve();
  }

  return 0;
}