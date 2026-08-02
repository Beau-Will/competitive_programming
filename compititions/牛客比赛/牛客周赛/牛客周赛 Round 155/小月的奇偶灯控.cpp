#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::vector<int> a(3);
  for(int i = 0; i < 3; i++){
    std::cin >> a[i];
  }

  std::cout << (std::accumulate(a.begin(), a.end(), 0, std::bit_xor()) ? "ON\n" : "OFF\n");
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