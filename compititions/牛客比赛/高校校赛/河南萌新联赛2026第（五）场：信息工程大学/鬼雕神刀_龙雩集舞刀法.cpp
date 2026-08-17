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
  int l, r;
  std::cin >> l >> r;
  
  std::vector<double> sigma(r + 1);
  for(int i = 1; i <= r; i++){
    for(int j = i; j <= r; j += i){
      sigma[j] += i;
    }
  }

  double ans = 0.;
  for(int i = l; i <= r; i++){
    ans = std::max(ans, sigma[i] / i);
  }

  std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}