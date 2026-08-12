#include <iostream>
#include <vector>

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
  std::vector<int> a(3);
  std::cin >> a[0] >> a[1] >> a[2];
 
  int ans = 0;
  while(a[0] != a[1] && a[0] != a[2] && a[1] != a[2]){
    std::sort(a.begin(), a.end());
    a[2] -= 1;
    a[0] += 1;
    ans++;
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