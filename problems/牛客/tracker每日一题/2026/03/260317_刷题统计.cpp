#include <iostream>

void solve(){
  int n, a, b, c, d;
  std::cin >> n >> a >> b >> c >> d;

  std::cout << (1LL * a + b + c - n - d) / 2 << "\n";
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