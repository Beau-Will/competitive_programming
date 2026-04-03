#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  int ans = 0;
  for(int i = 2; i <= n / i; i++){
    while(n % i == 0){
      n /= i;
      ans += i;
    }
  }

  if(n > 1){
    ans += n;
  }

  std::cout << ans << "\n";

  return 0;
}