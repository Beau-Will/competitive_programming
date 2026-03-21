#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  int ans = 0, cnt = 0;
  for(int i = 0; i < n; i++){
    if(i == 0 || std::abs(a[i] - a[i - 1]) <= 1){
      cnt++;
    }else{
      ans = std::max(ans, cnt);
      cnt = 1;
    }
  }
  ans = std::max(ans, cnt);

  std::cout << ans << "\n";

  return 0;
}