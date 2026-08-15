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
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
    a[i] &= 1;
  }

  auto check = [&](){
    for(int i = 1; i + 2 <= n; i++){
      if(a[i] == 0 && a[i + 1] == 0 && a[i + 2] == 0){
        return false;
      }
      if(a[i] == 1 && a[i + 1] == 1 && a[i + 2] == 1){
        return false;
      }
    }

    int cnt = 0;
    for(int i = 1; i + 1 <= n; i++){
      if(a[i] == 0 && a[i + 1] == 0){
        cnt++;
      }else if(a[i] == 1 && a[i + 1] == 1){
        cnt++;
      }
    }

    return cnt <= 1;
  };

  if(!check()){
    std::cout << "0\n";
    return;
  }

  std::cout << (n == 1 ? 1 : 2) << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}