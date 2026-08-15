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

// constexpr int int_max = std::numeric_limits<int>::max();
// constexpr i64 i64_max = std::numeric_limits<i64>::max();

/*
1 5 9 13 17
 4 4 4 4

3 10 17 31 38
 7  7  14 7

1 6 13 22
 5 7 9
*/

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  // std::sort(a.begin(), a.end());

  std::set<int> set;
  for(int i = 0; i < n - 1; i++){
    set.insert(a[i + 1] - a[i]);
  }
  if(set.size() == 1){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> d(n - 1);
  for(int i = 0; i < n - 1; i++){
    d[i] = a[i + 1] - a[i];
  }
  int ans = 0;
  for(int i = 0; i < n - 2; i++){
    ans = std::gcd(ans, std::abs(d[i + 1] - d[i]));
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}