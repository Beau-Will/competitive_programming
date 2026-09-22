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
constexpr int inf = inf1;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (auto& ai : a) std::cin >> ai;

  int max = -1, pos = -1;
  std::vector<int> ma(n);
  for (int i = 0; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
      pos = i;
    }
    ma[i] = pos;
  }

  int min = inf;
  pos = n;
  std::vector<int> mi(n);
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] < min) {
      min = a[i];
      pos = i;
    }
    mi[i] = pos;
  }

  i64 ans = 0;
  int l = 0;
  for (int r = 0; r < n; r++) {
    while (l < n and mi[l] <= r) {
      l++;
    }

    int t = std::min(ma[r], l - 1);
    if (t >= 0) {
      ans += t + 1;
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}