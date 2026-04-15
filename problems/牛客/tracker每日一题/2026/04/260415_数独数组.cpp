#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> cnt(9);
  for(int i = 0; i < n; i++){
    int x;
    std::cin >> x;
    cnt[x - 1]++;
  }

  std::sort(cnt.begin(), cnt.end());
  cnt.erase(std::unique(cnt.begin(), cnt.end()), cnt.end());

  if(cnt.size() > 2){
    std::cout << "NO\n";
    return 0;
  }

  if(cnt.size() == 2 && std::abs(cnt.front() - cnt.back()) > 1){
    std::cout << "NO\n";
    return 0;
  }

  std::cout << "YES\n";

  return 0;
}