#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    std::cin >> b[i];
  }

  int m = 0;
  bool hasd = false;
  for(int i = 0; i < n; i++){
    if(a[i] != b[i]){
      hasd = true;
      if(a[i]){
        m++;
      }
    }
  }

  if(!hasd){
    std::cout << "0\n";
    return;
  }

  if(std::count(a.begin(), a.end(), 0) == n){
    std::cout << "-1\n";
    return;
  }

  if(std::count(b.begin(), b.end(), 1) == n){
    std::cout << "-1\n";
    return;
  }

  std::cout << ((m & 1) ? 1 : 2) << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}