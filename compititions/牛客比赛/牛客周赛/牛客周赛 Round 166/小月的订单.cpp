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
constexpr i64 inf = inf2;
// constexpr double pi = std::numbers::pi; // at least C++20
// constexpr double e = std::numbers::e; // at least C++20

void solve() {
  int n;
  i64 s;
  std::cin >> n >> s;
  
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  
  std::vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  
  auto check = [&](int k) {
    if (k == 0) return true;
    if (2 * k > (n + 1) / 2) return false;
    
    std::vector<i64> dp(2 * k + 1, inf), prev1(2 * k + 1, inf), prev2(2 * k + 1, inf);
    
    prev2[0] = 0;
    prev1[0] = 0;
    
    if (2 * k >= 1) {
      prev1[1] = a[1];
    }
    
    for (int i = 2; i <= n; i++) {
      std::fill(dp.begin(), dp.end(), inf);
      dp[0] = 0;
      
      int t = std::min(2 * k, (i + 1) / 2);
      
      for (int j = 1; j <= t; j++) {
        i64 c = (j <= k ? a[i] : b[i]);
        
        i64 v1 = prev1[j];
        i64 v2 = inf;
        
        if (j >= 1 and j <= 2 * k + 1) {
          if (prev2[j - 1] != inf) {
            v2 = prev2[j - 1] + c;
          }
        }
        
        dp[j] = std::min(v1, v2);
      }
      
      prev2.swap(prev1);
      prev1.swap(dp);
    }
    
    return prev1[2 * k] <= s;
  };
  
  int lo = 0, hi = n / 2;
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  
  std::cout << lo << "\n";
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T; // multi cases

  for (int i = 1; i <= T; i++) solve();
}