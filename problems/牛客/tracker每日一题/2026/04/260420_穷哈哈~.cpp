#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<int> dp(n);
  for(int i = 0; i < n; i++){
    if(i == 0){
      if(s[i] == 'a' || s[i] == 'h'){
        dp[i] = 1;
      }
    }else{
      if(s[i - 1] == 'a' && s[i] == 'h' || s[i - 1] == 'h' && s[i] == 'a'){
        dp[i] = dp[i - 1] + 1;
      }else{
        if(s[i] == 'a' || s[i] == 'h'){
          dp[i] = 1;
        }
      }
    }
  }

  std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";

  return 0;
}