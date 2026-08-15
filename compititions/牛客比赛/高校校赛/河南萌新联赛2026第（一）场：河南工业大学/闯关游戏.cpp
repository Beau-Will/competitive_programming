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
  int n, m;
  std::cin >> n >> m;

  std::vector<std::set<int>> adj(n + 1);
  std::vector<int> in(n + 1);
  for(int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].insert(v);
    in[v]++;
  }

  std::vector<int> ans;
  auto topo_sort = [&](){
    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    for(int i = 1; i <= n; i++){
      if(in[i] == 0){
        q.push(i);
      }
    }
    while(q.size()){
      auto u = q.top();
      ans.push_back(u);
      q.pop();

      for(const auto& v : adj[u]){
        if(--in[v] == 0){
          q.push(v);
        }
      }
    }

    return ans.size() == n;
  };

  if(topo_sort()){
    std::cout << "Yes\n";
    for(int i = 0; i < ans.size(); i++){
      std::cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
  }else{
    std::cout << "No\n";
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}