#include <iostream>
#include <vector>

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

#include <limits>
constexpr int int_max = std::numeric_limits<int>::max();
// constexpr i64 i64_max = std::numeric_limits<i64>::max();

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T>
using MBT = __gnu_pbds::tree<
  std::pair<T, int>,
  __gnu_pbds::null_type,
  std::less<std::pair<T, int>>,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;
static int timer = 0;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> b(n);
  for(int i = 0; i < n; i++){
    std::cin >> b[i];
  }

  MBT<i64> tree;
  timer = 0;
  for(int i = 0; i < n; i++){
    tree.insert({b[i], timer++});
  }

  i64 cur = 0;
  std::vector<i64> ans;
  ans.reserve(n);
  for(int i = 0; i < n; i++){
    auto it = tree.upper_bound({-cur, int_max});
    if(it == tree.end()){
      std::cout << "-1\n";
      return;
    }
    auto [v, _] = *it;
    cur += v;
    ans.push_back(cur);
    tree.erase(it);
  }

  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
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