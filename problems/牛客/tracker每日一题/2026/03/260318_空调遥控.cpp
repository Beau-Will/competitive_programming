#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, p;
  std::cin >> n >> p;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0; i < n; i++){
    int cnt = std::upper_bound(a.begin() + i, a.end(), a[i] + p * 2) - a.begin() - i;
    ans = std::max(ans, cnt);
  }

  std::cout << ans << "\n";

  return 0;
}