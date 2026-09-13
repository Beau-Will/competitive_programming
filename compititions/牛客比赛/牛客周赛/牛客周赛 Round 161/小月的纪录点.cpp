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
constexpr int inf = 2 * inf1;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n ; i++){
    std::cin >> a[i];
  }

  int cnt = 0, ans = 0, prev = -1, max = -inf;
  for(int i = 1; i <= n; i++){
    if(i == 1){
      cnt++;
      prev = i;
      max = std::max(max, a[i]);
      continue;
    }

    if(a[i] > max){
      max = a[i];
      cnt++;
      if(~prev){
        ans = std::max(ans, i - prev);
        prev = i;
      }
    }
  }

  std::cout << cnt << " " << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}