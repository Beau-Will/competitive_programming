#include <bits/stdc++.h>
#include <bit>

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
  int x;
  i64 k;
  std::cin >> x >> k;

  int cur = x;
  std::vector<int> res;
  for(int i = 0; i < 4; i++){
    res.push_back(cur);

    int t = cur >> 3;
    cur <<= 1;
    cur |= t;
    cur &= 15;
  }

  std::cout << res[k % 4] << " " << std::popcount(static_cast<u32>(x)) << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}