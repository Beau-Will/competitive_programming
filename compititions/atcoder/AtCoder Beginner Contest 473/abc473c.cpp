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
  int n, k;
  std::cin >> n >> k;

  std::unordered_map<int, std::vector<int>> map;
  for(int i = 1; i <= n; i++){
    int f;
    std::cin >> f;

    map[f].push_back(i);
  }

  int max = 0;
  for(const auto& [u, v] : map){
    if(v.size() > max){
      max = v.size();
    }
  }
  int ans = 0;
  for(const auto& [u, v] : map){
    if(v.size() + 1 >= max){
      ans++;
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}