#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int k, q;
  std::cin >> k >> q;

  for(int i = 1; i <= q; i++){
    i64 l, r;
    int h;
    i64 z;
    std::cin >> l >> r >> h >> z;

    i64 pref = 0, cur = 0;
    for(int i = 0; i < h; i++){
      cur ^= (z >> i) & 1;
      pref = (pref << 1) | cur;
    }
    i64 len = 1LL << (k - h);
    i64 L = pref * len + 1;
    i64 R = (pref + 1) * len;

    std::cout << std::max(0LL, (std::min(r, R) - std::max(l, L) + 1)) << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}
