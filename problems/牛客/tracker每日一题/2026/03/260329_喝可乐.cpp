#include <iostream>

void solve(){
  int n, a, b;
  std::cin >> n >> a >> b;

  int ans = 0;

  for(int i = 0; i <= n; i++){
    int j = i;
    int k = n - j;
    int res = j + k;

    while(j >= a || k >= b){
      if(j >= a){
        k += j / a;
        res += j / a;
        j %= a;
      }
      if(k >= b){
        j += k / b;
        res += k / b;
        k %= b;
      }
    }
    ans = std::max(ans, res);
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int i = 0; i < T; i++){
    solve();
  }

  return 0;
}