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

// constexpr int int_max = std::numeric_limits<int>::max();
// constexpr i64 i64_max = std::numeric_limits<i64>::max();

void solve(){
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  int sum1 = 2 * a + b, sum2 = 2 * c + d;
  if(sum1 < sum2){
    if(b & 1){
      std::cout << 2 * ((d >= 1) ? sum1 : sum1 - 1) << "\n";
    }else{
      std::cout << 2 * sum1 << "\n";
    }
  }else{
    if(d & 1){
      std::cout << 2 * ((b >= 1) ? sum2 : sum2 - 1) << "\n";
    }else{
      std::cout << 2 * sum2 << "\n";
    }
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}