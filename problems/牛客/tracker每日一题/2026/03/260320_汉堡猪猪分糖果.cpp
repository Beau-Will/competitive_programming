#include <iostream>
#include <vector>

using i64 = long long;

void solve(){
  int n, m;
  std::cin >> n >> m;

  i64 tmp = n, ans = 0;
  for(int i = 31; i >= 0; i--){
    i64 t = 1LL << i;
    if(tmp >= t * m){
      tmp -= t * m;
      ans |= t;
    }else if(tmp > t * m - m){
      tmp -= (tmp - t * m + m + t - 1) / t * t;
    }
  }

  std::cout << ans << "\n";
}

int main() {
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