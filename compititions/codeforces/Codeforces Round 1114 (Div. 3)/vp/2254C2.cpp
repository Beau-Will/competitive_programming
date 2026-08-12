#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

  std::vector<std::vector<int>> a(2), b(2);
  for(int i = 0; i < n; i++){
    a[i % 2].push_back(s[i] - '0');
    b[i % 2].push_back(t[i] - '0');
  }

  if(std::count(a[0].begin(), a[0].end(), 1) != std::count(b[0].begin(), b[0].end(), 1) || 
  std::count(a[1].begin(), a[1].end(), 1) != std::count(b[1].begin(), b[1].end(), 1)){
    std::cout << "-1\n";
    return;
  }

  i64 ans = 0;
  std::vector<std::vector<int>> ids(2), idt(2);
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < a[i].size(); j++){
      if(a[i][j] == 1) ids[i].push_back(j);
      if(b[i][j] == 1) idt[i].push_back(j);
    }
  }
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < ids[i].size(); j++){
      ans += std::abs(ids[i][j] - idt[i][j]);
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