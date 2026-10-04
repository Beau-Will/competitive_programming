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
  int n, k;
  std::cin >> n >> k;

  if (k > (n + 1) / 2) {
    std::cout << "No\n";
    return;
  }

  std::vector<int> ans;
  for (int i = 0; i < k; i++) {
    ans.push_back(n - 2 * i);
  }

  for (int x = 1; x <= n; x++) {
    if ((x & 1) != (n & 1)) {
      ans.push_back(x);
    }
  }

  for (int x = n - 2 * k; x >= 1; x -= 2) {
    ans.push_back(x);
  }

  std::cout << "Yes\n";
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T; // multi cases

  for (int i = 1; i <= T; i++) solve();
}