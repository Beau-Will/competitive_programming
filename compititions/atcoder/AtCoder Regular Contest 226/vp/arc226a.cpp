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

#include <atcoder/modint>

using Z = atcoder::modint998244353;

void solve(){
  int n;
  std::cin >> n;
 
  std::vector<int> s(n), t(n); 
  for(int i = 0; i < n; i++){
    std::cin >> s[i] >> t[i];
  }

  std::vector<int> diff(2 * n + 2);
  auto update = [&](int l, int r, int x){
    diff[l] += x;
    diff[r + 1] -= x;
  };

  for(int i = 0; i < n; i++){
    update(s[i], t[i] - 1, 1);
  }

  std::vector<int> pre(2 * n + 2);
  std::partial_sum(diff.begin(), diff.end(), pre.begin());

  Z ans = 1;
  for(int i = 1; i <= 2 * n; i++){
    if(!pre[i]){
      ans *= 2;
    }else if(pre[i] > 2){
      ans = 0;
      break;
    }
  }

  std::cout << ans.val() << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}