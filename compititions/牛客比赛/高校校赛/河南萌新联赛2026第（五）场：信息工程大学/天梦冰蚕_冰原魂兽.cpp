#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr double eps = 1E-10;
// constexpr double pi = std::numbers::pi;
// constexpr double e = std::numbers::e;
constexpr int inf = inf1;

void solve(){
  std::string s;
  std::cin >> s;

  auto to_dec = [](char c){
    if(c <= '9') return static_cast<int>(c - '0');
    return static_cast<int>(c - 'A' + 10);
  };

  int sum = 0;
  for(const auto& si : s){
    sum = sum * 16 + to_dec(si);
  }

  int rest = sum;
  for(const auto& si : s){
    rest -= si;
  }
  
  constexpr std::array vals = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70};

  if(rest == 0){
    std::cout << s << "\n";
    return;
  }

  std::vector<int> dp(rest + 1, inf), pre(rest + 1, -1);
  dp[0] = 0;
  for(int i = 0; i <= rest; i++){
    if(dp[i] == inf) continue;

    for(const auto& v : vals){
      if(i + v > rest) break;
      int j = i + v;
      if(dp[i] + 1 < dp[j]){
        dp[j] = dp[i] + 1;
        pre[j] = v;
      }
    }
  }

  auto to_char = [](int x){
    if(x <= 57) return static_cast<char>('0' + (x - 48));
    return static_cast<char>('A' + (x - 65));
  };

  std::string ans = s;
  for(int cur = rest; cur > 0; ){
    int x = pre[cur];
    ans.push_back(to_char(x));
    cur -= x;
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}