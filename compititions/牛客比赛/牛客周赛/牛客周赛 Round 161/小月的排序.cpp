#include <bits/stdc++.h>
#include <bit>

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
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin() + 1, a.end(), [](const int& t1, const int& t2){
    u32 u1 = t1, u2 = t2;
    int cnt1 = std::popcount(u1), cnt2 = std::popcount(u2);
    if(cnt1 != cnt2){
      return cnt1 < cnt2;
    }
    cnt1 = std::countr_zero(u1), cnt2 = std::countr_zero(u2);
    if(cnt1 != cnt2){
      return cnt1 < cnt2;
    }
    return u1 < u2;
  });

  std::cout << a[k] << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}