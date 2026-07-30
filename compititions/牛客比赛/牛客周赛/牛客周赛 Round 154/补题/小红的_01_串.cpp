#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::string s;
  std::cin >> s;
  
  auto norm = [&](int idx){
    return (idx + n) % n;
  };
  
  std::vector<int> d(n);
  for(int i = 0; i < n; i++){
    d[i] = s[i] != s[norm(i + 1)];
  }
  
  int ans = std::accumulate(d.begin(), d.end(), 0);
  for(int i = 0; i < q; i++){
    int l, r;
    std::cin >> l >> r;
    
    ans += d[norm(l - 1)] ? -1 : 1;
    d[norm(l - 1)] ^= 1;
    
    ans += d[norm(r)] ? -1 : 1;
    d[norm(r)] ^= 1;
    
    std::cout << ans << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}