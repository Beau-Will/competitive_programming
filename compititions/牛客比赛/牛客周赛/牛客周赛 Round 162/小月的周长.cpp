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
  int n, m, x, y;
  std::cin >> n >> m >> x >> y;

  auto get = [&](int x1, int y1, int x2, int y2){
    if(x2 < x1 or y2 < y1) return 0;
    return 2 * ((x2 - x1 + 1) + (y2 - y1 + 1));
  };

  std::cout << get(1, 1, x - 1, y - 1) + get(x + 1, 1, n, y - 1)
   + get(1, y + 1, x - 1, m) + get(x + 1, y + 1, n, m) << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}