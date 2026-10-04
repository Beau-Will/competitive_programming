#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9 + 7, P2 = 998'244'353;
constexpr double eps = 1E-10;
// constexpr double pi = std::numbers::pi; // at least C++20
// constexpr double e = std::numbers::e; // at least C++20

i64 pow(i64 a, i64 b) {
  i64 res = 1;
  for (; b; a *= a, b >>= 1) {
    if (b & 1) res *= a;
  }
  return res;
}

void solve() {
  i64 x, y;
  std::cin >> x >> y;
  
  std::map<i64, int> fac;

  auto div_fac = [&](i64 t) {
    for (i64 i = 2; i <= t / i; i++) {
      if (t % i == 0) {
        while (t % i == 0) {
          fac[i]++;
          t /= i;
        }
      }
    }
    if (t >= 1) {
      fac[t]++;
    }
  };
  
  div_fac(x);
  div_fac(y);

  i64 g = 1;

  for (const auto& [u, v] : fac) {
    g *= pow(u, v / 2);
  }

  i64 a = g;
  i64 b = x * y / g;

  std::cout << a << " " << b << "\n";
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T; // multi cases

  for (int i = 1; i <= T; i++) solve();
}