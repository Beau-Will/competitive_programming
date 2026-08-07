#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr double eps = 1E-10;

void solve(){
  int n, k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;
  s = " " + s;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    a[i] = s[i] == 'o';
  }
  std::partial_sum(a.begin(), a.end(), a.begin());

  auto check = [&](double x){
    std::vector<double> b(n + 1);
    for(int i = 1; i <= n; i++){
      b[i] = a[i] - x * i;
    }

    double min = inf2;
    int l = 0;

    for(int r = 1; r <= n; r++){
      
      while(l < r && a[r] - a[l] >= k){
        if(b[l] < min){
          min = b[l];
        }
        l++;
      }

      if(b[r] - min >= 0){
        return true;
      }
    }
    return false;
  };

  double l = 0., r = 1.;
  for(int i = 0; i < 60; i++){
    double mid = (l + r) / 2;

    if(check(mid)){
      l = mid;
    }else{
      r = mid;
    }
  }

  std::cout << std::fixed << std::setprecision(15) << l << "\n";
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