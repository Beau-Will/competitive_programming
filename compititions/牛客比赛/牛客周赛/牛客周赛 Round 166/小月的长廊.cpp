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

void solve() {
  int n, p;
  std::cin >> n >> p;

  std::vector<std::array<int, 2>> a(n);
  std::vector<int> alls;
  for (auto& [l, r] : a) {
    std::cin >> l >> r;

    alls.push_back(l);
    alls.push_back(r);
  }

  std::sort(alls.begin(), alls.end());
  alls.erase(std::unique(alls.begin(), alls.end()), alls.end());

  auto query = [&](int x) {
    return std::lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
  };
  
  int m = alls.size();
  std::vector<int> diff(m + 2);
  auto update = [&](int l, int r, int c) {
    diff[l] += c;
    diff[r + 1] -= c;
  };
  for (const auto& [l, r] : a) {
    update(query(l), query(r), 1);
  }

  std::vector<int> b(m + 1);
  for (int i = 1; i <= m; i++) {
    b[i] = b[i - 1] + diff[i];
  }

  i64 ans = 0;
  for (const auto& [l, r] : a) {
    if (std::abs(b[query(l)] - b[query(r)]) >= p) {
      ans++;
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T; // multi cases

  for (int i = 1; i <= T; i++) solve();
}