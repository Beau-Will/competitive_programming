#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr double eps = 1E-10;
// constexpr double pi = std::numbers::pi;
// constexpr double e = std::numbers::e;

// #include <limits>
// constexpr int int_max = std::numeric_limits<int>::max();
// constexpr i64 i64_max = std::numeric_limits<i64>::max();

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::tuple<i64, int>> b(n);
  for(int i = 0; i < n; i++){
    auto& [bi, idx] = b[i];
    std::cin >> bi;
    idx = i;
  }

  std::map<i64, int> cnt;
  for(int i = 0; i < n; i++){
    const auto& [bi, idx] = b[i];
    cnt[bi]++;
  }

  if(!cnt[0]){
    std::cout << "-1\n";
    return;
  }

  std::vector<i64> a;
  i64 last_u = 0, last_v = 0, last = 0;
  for(const auto& [u, v] : cnt){
    if(u == 0){
      last_u = u;
      last_v = v;
      continue;
    }

    if((u - last_u) % last_v || (u - last_u) / last_v <= last){
      std::cout << "-1\n";
      return;
    }

    last = (u - last_u) / last_v;
    for(int i = 0; i < last_v; i++){
      a.push_back(last);
    }
    last_u = u;
    last_v = v;
  }
  for(int i = 0; i < last_v; i++){
    a.push_back(last + 1);
  }
  if(a.size() != n){
    std::cout << "-1\n";
    return;
  }

  std::sort(b.begin(), b.end());

  std::vector<i64> ans(n);
  for(int i = 0; i < n; i++){
    const auto& [bi, idx] = b[i];
    ans[idx] = a[i];
  }
  for(int i = 0; i < n; i++){
    std::cout << ans[i] << " \n"[i + 1 == n];
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) {
    solve();
  }

  return 0;
}