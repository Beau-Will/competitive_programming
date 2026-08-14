#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr double eps = 1E-10;
constexpr double pi = std::numbers::pi;
constexpr double e = std::numbers::e;

void solve(){
  int n, q, x;
  std::cin >> n >> q >> x;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> b(n + 1);
  for(int i = 1; i <= n; i++){
    b[i] = std::abs(a[i] - x);
  }
  std::sort(b.begin() + 1, b.end(), std::greater());
  std::partial_sum(b.begin() + 1, b.end(), b.begin() + 1);

  for(int i = 1; i <= q; i++){
    i64 k;
    std::cin >> k;

    std::cout << std::lower_bound(b.begin(), b.end(), b[n] - k) - b.begin() << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++){
    solve();
  }

  return 0;
}