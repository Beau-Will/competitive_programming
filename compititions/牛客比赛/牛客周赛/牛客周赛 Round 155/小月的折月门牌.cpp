#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/*
WA 101.35/250
*/

void solve(){
  int k, q;
  std::cin >> k >> q;

  for(int i = 1; i <= q; i++){
    i64 l, r;
    std::cin >> l >> r;
    int h;
    i64 z;
    std::cin >> h >> z;

    if(h == 0){
      std::cout << (r - l + 1) << "\n";
      continue;
    }

    i64 L = (1LL << (k - h)) * z + 1;
    i64 R = (1LL << (k - h)) * (z + 1);

    if(std::max(l, L) <= std::min(r, R)){
      std::cout << (std::min(r, R) - std::max(l, L) + 1) << "\n";
    }else{
      std::cout << "0\n";
    }
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