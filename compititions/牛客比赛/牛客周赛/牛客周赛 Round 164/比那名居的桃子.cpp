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
  i64 x, y, s, m, k, n;
  std::cin >> x >> y >> s >> m >> k >> n;

  std::vector<i64> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];

  std::vector<int> b(n);
  for (int i = 0; i < n; i++) std::cin >> b[i];

  std::vector<i64> v0, v1;
  for (int i = 0; i < n; i++) {
    if (b[i] == 0) v0.push_back(a[i]);
    else v1.push_back(a[i]);
  }

  std::sort(v0.begin(), v0.end(), std::greater());
  std::sort(v1.begin(), v1.end(), std::greater());

  std::vector<i64> pre0(v0.size() + 1), pre1(v1.size() + 1);
  std::partial_sum(v0.begin(), v0.end(), pre0.begin() + 1);
  std::partial_sum(v1.begin(), v1.end(), pre1.begin() + 1);

  int C = std::min<i64>({i64(n), m / k, s / (k * x)});

  i64 ans = 0;
  for (int c = 0; c <= C; c++) {
    i64 base = i64(c) * k * x;
    i64 rem = s - base;
    i64 d = rem / y;

    int L = std::max<int>(0, c - v0.size());
    int R = std::min<i64>({i64(v1.size()), i64(c), d});

    if (L > R) continue;

    auto check = [&](int x) {
      return pre1[x] + pre0[c - x] < pre1[x + 1] + pre0[c - x - 1];
    };

    int l = L, r = R;
    while (l < r) {
      int mid = (l + r) / 2;

      if (check(mid)) l = mid + 1;
      else r = mid;
    }

    ans = std::max(ans, pre1[l] + pre0[c - l]);
  }

  std::cout << ans << "\n";
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T; // multi cases

  for (int i = 1; i <= T; i++) solve();
}