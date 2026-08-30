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
  int m, q, b;
  std::cin >> m >> q >> b;

  std::vector<i64> a(m + 1);
  for(int i = 1; i <= m; i++){
    std::cin >> a[i];
  }

  std::vector<i64> pre(m + 1);
  std::partial_sum(a.begin(), a.end(), pre.begin());

  for(int i = 0; i < q; i++){
    i64 x;
    std::cin >> x;

    int idx = std::lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    std::cout << ((idx & 1) ^ (1 & 1) ? 1 - b : b) << " " << idx << " " << x - pre[idx - 1] << "\n";
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}