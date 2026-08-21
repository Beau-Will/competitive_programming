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
constexpr int inf = inf1;

struct TwoSat {
  int n;
  std::vector<std::vector<int>> e;
  std::vector<bool> ans;
  TwoSat(int n) : n(n), e(2 * n), ans(n) {}
  void addClause(int u, bool f, int v, bool g) {
    e[2 * u + !f].push_back(2 * v + g);
    e[2 * v + !g].push_back(2 * u + f);
  }
  bool satisfiable() {
    std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
    std::vector<int> stk;
    int now = 0, cnt = 0;
    std::function<void(int)> tarjan = [&](int u) {
      stk.push_back(u);
      dfn[u] = low[u] = now++;
      for (auto v : e[u]) {
        if (dfn[v] == -1) {
          tarjan(v);
          low[u] = std::min(low[u], low[v]);
        } else if (id[v] == -1) {
          low[u] = std::min(low[u], dfn[v]);
        }
      }
      if (dfn[u] == low[u]) {
        int v;
        do {
          v = stk.back();
          stk.pop_back();
          id[v] = cnt;
        } while (v != u);
        ++cnt;
      }
    };
    for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
    for (int i = 0; i < n; ++i) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      ans[i] = id[2 * i] > id[2 * i + 1];
    }
    return true;
  }
  std::vector<bool> answer() {
    return ans;
  }
};

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> x1(n + 1), y1(n + 1), x2(n + 1), y2(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }

  std::vector dist1(n + 1, std::vector<int>(n + 1));
  std::vector dist2(n + 1, std::vector<int>(n + 1));
  std::vector dist3(n + 1, std::vector<int>(n + 1));
  std::vector dist4(n + 1, std::vector<int>(n + 1));

  auto dis = [](int x, int y, int a, int b){
    return (x - a) * (x - a) + (y - b) * (y - b);
  };

  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      dist1[i][j] = dis(x1[i], y1[i], x1[j], y1[j]);
      dist2[i][j] = dis(x1[i], y1[i], x2[j], y2[j]);
      dist3[i][j] = dis(x2[i], y2[i], x1[j], y1[j]);
      dist4[i][j] = dis(x2[i], y2[i], x2[j], y2[j]);
    }
  }

  auto check = [&](int x){
    TwoSat twosat(n);
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= n; j++){
        if(dist1[i][j] < x) twosat.addClause(i - 1, 1, j - 1, 1);
        if(dist2[i][j] < x) twosat.addClause(i - 1, 1, j - 1, 0);
        if(dist3[i][j] < x) twosat.addClause(i - 1, 0, j - 1, 1);
        if(dist4[i][j] < x) twosat.addClause(i - 1, 0, j - 1, 0);
      }
    }
    return twosat.satisfiable();
  };

  int l = 0, r = inf;
  while(l < r){
    int mid = (l + r + 1) / 2;
    if(check(mid)){
      l = mid;
    }else{
      r = mid - 1;
    }
  }

  std::cout << l << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}