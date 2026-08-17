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
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  std::unordered_map<std::string, int> at;
  for(int i = 0; i < n; i++){
    std::string s;
    std::cin >> s >> a[i];

    at[s] = i;
  }

  std::vector b(m, std::vector<int>(6));
  for(int i = 0; i < m; i++){
    int t;
    std::cin >> t;

    for(int j = 0; j < t; j++){
      std::string s;
      int l;
      std::cin >> s >> l;

      b[i][at[s]] = l;
    }
  }

  std::vector<int> siz(6), base(6);
  int sum = 1;
  base[0] = 1;
  for(int i = 0; i < n; i++){
    siz[i] = a[i] + 1;
    if(i){
      base[i] = base[i - 1] * siz[i - 1];
    }
    sum *= siz[i];
  }

  std::vector map(sum, std::vector<int>(6));
  for(int state = 0; state < sum; state++){
    int tmp = state;

    for(int d = 0; d < n; d++){
      map[state][d] = tmp % siz[d];
      tmp /= siz[d];
    }
  }

  std::vector<int> dp(sum, inf);
  dp[0] = 0;

  for(int i = 0; i < m; i++){
    int t = 0;
    for(int d = 0; d < n; d++){
      t += b[i][d] * base[d];
    }

    if(t == 0) continue;

    for(int j = 0; j < sum; j++){
      if(dp[j] == inf) continue;

      bool isok = true;

      for(int d = 0; d < n; d++){
        if(map[j][d] + b[i][d] > a[d]){
          isok = false;
          break;
        }
      }

      if(!isok) continue;

      int next = j + t;
      dp[next] = std::min(dp[next], dp[j] + 1);
    }
  }

  int end = 0;
  for(int d = 0; d < n; d++){
    end += a[d] * base[d];
  }

  std::cout << (dp[end] == inf ? -1 : dp[end]) << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}