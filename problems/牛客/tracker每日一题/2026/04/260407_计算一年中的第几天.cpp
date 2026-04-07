#include <iostream>
#include <array>
#include <numeric>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  auto isLeap = [](int year){
    if(year % 100 && year % 4 == 0){
      return true;
    }
    if(year % 100 == 0 && year % 400 == 0){
      return true;
    }
    return false;
  };

  constexpr std::array days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int y, m, d;
  while(std::cin >> y >> m >> d){
    int ans = std::accumulate(days.begin(), days.begin() + m, d);
    if(m > 2 && isLeap(y)){
      ans++;
    }
    std::cout << ans << "\n";
  }

  return 0;
}