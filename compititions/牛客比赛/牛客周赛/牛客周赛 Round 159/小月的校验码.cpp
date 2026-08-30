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
  int n, b;
  std::cin >> n >> b;

  std::vector<bool> vis(1 << b);
  std::vector<int> a;
  for(int i = 0; i < n; i++){
    std::string s;
    std::cin >> s;

    int x = 0;
    for(int j = 0; j < b; j++){
      x |= ((s[j] ^ 48) << (b - 1 - j));
    }

    if(!vis[x]){
      vis[x] = true;
      a.push_back(x);
    }
  }

  i64 ans = 0;
  std::vector<i64> cnt(b);
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < b; j++){
      int t = a[i] ^ (1 << j);

      if(vis[t]){
        ans++;
        cnt[j]++;
      }
    }
  }

  std::cout << ans / 2 << "\n";
  for(int i = 0; i < b; i++){
    std::cout << cnt[b - 1 - i] / 2 << " \n"[i + 1 == b];
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}