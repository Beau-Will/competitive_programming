#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<int> A(m), B(m);
  std::vector<int> cnt(n + 1);
  for(int i = 0; i < m; i++){
    std::cin >> A[i] >> B[i];

    cnt[A[i]]++;
    cnt[B[i]]++;
  }

  std::vector<bool> isok(n + 1);
  int cntok = 0;
  for(int i = 1; i <= n; i++){
    if(cnt[i] == m){
      isok[i] = true;
      cntok++;
    }
  }

  i64 ans = 0;
  ans += 1LL * cntok * (n - cntok);
  ans += 1LL * (cntok - 1) * cntok / 2;

  std::set<std::array<int, 2>> set;
  std::vector<int> t;
  if(!isok[A[0]]){
    t.push_back(A[0]);
  }
  if(!isok[B[0]]){
    t.push_back(B[0]);
  }

  for(int u : t){
    std::vector<int> c1;
    bool st = true;

    for(int i = 0; i < m; i++){
      int a = A[i], b = B[i];
      if(u != a && u != b){
        if(st){
          c1 = {a, b};
          st = false;
        }else{
          std::vector<int> c2;
          for(int x : c1){
            if(x == a || x == b){
              c2.push_back(x);
            }
          }
          c1 = std::move(c2);
          if(c1.empty()){
            break;
          }
        }
      }
    }

    for(int v : c1){
      if(isok[v] || u == v){
        continue;
      }
      set.insert({std::min(u, v), std::max(u, v)});
    }
  }

  ans += set.size();
  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}