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
  int n;
  std::cin >> n;
  
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  
  std::vector<int> pre(n + 1);
  std::partial_sum(a.begin(), a.end(), pre.begin());
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = std::max(1, i - 901); j <= i - 2; j++) {
      if (pre[i - 1] - pre[j] == a[i] * a[j]) {
        ans++;
      }
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