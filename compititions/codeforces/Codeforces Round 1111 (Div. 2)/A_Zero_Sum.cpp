#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  if(n & 1){
    std::cout << "NO\n";
    return;
  }

  if(n == 2){
    if(a[0] + a[1] == 0){
      std::cout << "YES\n";
    }else{
      std::cout << "NO\n";
    }
    return;
  }

  int cnt1 = std::count(a.begin(), a.end(), 1);

  if((cnt1 & 1) != ((n / 2) & 1)){
    std::cout << "NO\n";
  }else{
    std::cout << "YES\n";
  }
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