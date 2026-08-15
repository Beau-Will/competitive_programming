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
  int q, V;
  std::cin >> q >> V;

  std::priority_queue<int> pq;
  for(int i = 0; i < q; i++){
    int op, tq, wq;
    std::cin >> op >> tq;

    if(op == 1){
      std::cin >> wq;

      pq.push(wq - tq);
    }else{
      if(pq.empty()){
        std::cout << "-1\n";
        continue;
      }

      auto t = pq.top();
      pq.pop();
      std::cout << std::min(V, t + tq) << "\n";
    }
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}