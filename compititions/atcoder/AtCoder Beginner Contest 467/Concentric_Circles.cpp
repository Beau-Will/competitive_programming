#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  i64 px, py, qx, qy, rx, ry, sx, sy;
  std::cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

  i64 dx1 = qx - px, dy1 = qy - py;
  i64 dx2 = sx - rx, dy2 = sy - ry;

  if(dx1 * dy2 != dy1 * dx2){
    std::cout << "Yes\n";
  }else{
    i64 diffx = (px + qx) - (rx + sx);
    i64 diffy = (py + qy) - (ry + sy);

    if(diffx * dx1 + diffy * dy1 == 0){
      std::cout << "Yes\n";
    }else{
      std::cout << "No\n";
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}