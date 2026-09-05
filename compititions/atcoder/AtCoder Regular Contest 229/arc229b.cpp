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
  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  bool isok = true;
  for(int i = 0; i < n; i++){
    if(a[i]){
      isok = false;
      break;
    }
  }

  if(isok){
    std::cout << "0\n";
    return;
  }

  i64 ans = 0;
  for(int i = 0; i < n - 1; i++){
    i64 d = a[i] - 2 * a[i + 1];
    if(d < 0){
      std::cout << "-1\n";
      return;
    }
    ans = std::max(ans, d);
  }

  std::cout << std::max(1LL, ans) << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}