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

/*
0 -> 0
1 -> 1
2 -> 3
3 -> 4
4 -> 7
5 -> 8
6 -> 10
7 -> 11
8 -> 15
9 -> 16
10 -> 18
*/

void solve(){
  i64 n;
  std::cin >> n;

  // 打表
  // for(int i = 0; i <= 30; i++){
  //   int cnt = 0;
  //   int cur = 0;
  //   for(int j = 0; j < i; j++){
  //     int ncur = cur + 1;
  //     cnt += std::popcount(static_cast<u32>(cur ^ ncur));
  //     cur = ncur;
  //   }

  //   std::cout << cnt << " \n"[i % 5 == 0];
  // }

  std::cout << 2 * n - std::popcount(static_cast<u64>(n)) << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}