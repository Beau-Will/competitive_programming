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

#include <atcoder/modint>
#include <atcoder/convolution>

using Z = atcoder::modint998244353;

void solve(){
  int n, k;
  std::cin >> n >> k;

  if(k < n || k >= 2 * n){
    std::cout << "0\n";
    return;
  }

  k = 2 * n - k;
  std::vector<Z> h(n + 1), v(n + 1);
  h[0] = 0;
  v[0] = 1;

  for(int i = 1; i <= n; i++){
    h[i] = Z(1) / i;
  }

  auto work = [&](const std::vector<Z>& v1, const std::vector<Z>& v2){
    return atcoder::convolution<Z>(v1, v2);
  };

  for(int i = 0; i < 20; i++){
    if(k >> i & 1) v = work(v, h);
    h = work(h, h);

    while(v.size() > n + 1) v.pop_back();
    while(h.size() > n + 1) h.pop_back();
  }

  for(int i = 1; i <= k; i++) v[n] /= i;

  std::cout << v[n].val() << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}