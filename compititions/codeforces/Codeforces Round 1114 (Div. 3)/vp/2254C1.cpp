#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

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

  std::string s, t;
  std::cin >> s >> t;

  std::vector<int> cnts(2), cntt(2);
  for(int i = 0; i < n; i++){
    cnts[i % 2] += s[i] == '1';
    cntt[i % 2] += t[i] == '1';
  }

  std::cout << (cnts[0] == cntt[0] && cnts[1] == cntt[1] ? "YES\n" : "NO\n");
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