#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::array<i64, 2>> p(n);
  for(i64 i = 0; i < n; i++){
    std::cin >> p[i][0] >> p[i][1];
  }

  auto cross = [&](i64 x1, i64 y1, i64 x2, i64 y2, i64 x, i64 y){
    return (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
  };

  i64 ans = 0;
  for(i64 i = 0; i < n; i++){
    auto [x1, y1] = p[i];
    for(i64 j = i + 1; j < n; j++){
      auto [x2, y2] = p[j];
      i64 l = 0, r = 0;
      for(i64 k = 0; k < n; k++){
        if(k == i || k == j){
          continue;
        }
        auto [x, y] = p[k];

        if(cross(x1, y1, x2, y2, x, y) > 0){
          l++;
        }else if(cross(x1, y1, x2, y2, x, y) < 0){
          r++;
        }
      }
      if(l == r){
        ans++;
      }
    }
  }

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