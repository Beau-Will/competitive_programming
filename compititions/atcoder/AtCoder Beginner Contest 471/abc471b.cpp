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

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::string> words(n);
  for(int i = 0; i < n; i++){
    std::cin >> words[i];
    for(int j = 0; j < words[i].size(); j++){
      words[i][j] = std::tolower(words[i][j]);
    }
  }

  std::map<std::string, int> cnt;
  for(int i = 0; i < n; i++){
    cnt[words[i]]++;
  }

  std::cout << std::max_element(cnt.begin(), cnt.end(), [&](const auto& t1, const auto& t2){
    return t1.second < t2.second;
  }) -> second << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}