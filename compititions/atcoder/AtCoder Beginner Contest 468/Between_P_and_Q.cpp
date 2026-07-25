#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> p(n), q(n);
  for(int i = 0; i < n; i++){
    std::cin >> p[i];
  }
  for(int i = 0; i < n; i++){
    std::cin >> q[i];
  }

  std::vector<int> per(n);
  std::iota(per.begin(), per.end(), 1);

  int cur = 0, cntp = -1, cntq = -1;
  do{
    cur++;
    bool isp = true;
    bool isq = true;
    for(int i = 0; i < n; i++){
      if(per[i] != p[i]){
        isp = false;
      }
      if(per[i] != q[i]){
        isq = false;
      }
    }
    if(isp){
      cntp = cur;
    }
    if(isq){
      cntq = cur;
    }
  }while(std::next_permutation(per.begin(), per.end()));

  std::cout << (cntq - cntp - 1 < 0 ? 0 : cntq - cntp - 1) << "\n";
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