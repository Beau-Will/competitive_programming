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
  i64 x;
  std::cin >> x;

  auto check = [&](i64 num){
    return x / num >= num;
  };

  i64 l = 0, r = x;
  while(l < r){
    i64 mid = (l + r + 1) / 2;
    if(check(mid)){
      l = mid;
    }else{
      r = mid - 1;
    }
  }

  std::cout << r << " " << x - r * r << " " << (r + 1) * (r + 1) - x << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}