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
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n + 1);
  auto dfs = [&](auto&& self, int u, int sum) -> void {
    if(u == n){
      if((k - sum) % u) return;

      a[n] = (k - sum) / u;
      for(int i = 1; i <= n; i++){
        std::cout << a[i] << " \n"[i == n];
      }
      return;
    }

    for(int i = 0; i <= (k - sum) / u; i++){
      a[u] = i;
      self(self, u + 1, sum + i * u);
    }
  };

  dfs(dfs, 1, 0);
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}