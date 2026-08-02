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
    a[i] = (s[i] == 'o' ? 1 : 0);
  }
  
  std::vector<int> prea(n + 1);
  std::partial_sum(a.begin(), a.end(), prea.begin());

  auto check = [&](double p){
    std::vector<double> b(n + 1);
    for(int i = 1; i <= n; i++){
      b[i] = a[i] - p;
    }
    
    std::vector<double> preb(n + 1);
    std::partial_sum(b.begin(), b.end(), preb.begin());

    double min = inf2;
    int l = 0;

    for(int r = 1; r <= n; r++){
      while(l < r && prea[l] <= prea[r] - k){
        if(preb[l] < min){
          min = preb[l];
        }
        l++;
      }

      if(min <= preb[r] + eps){
        return true;
      }
    }

    return false;
  };

  double lo = 0., hi = 1.;
  while(hi - lo > eps){
    double mid = (lo + hi) / 2;
    if(check(mid)){
      lo = mid;
    }else{
      hi = mid;
    }
  }

  std::cout << std::fixed << std::setprecision(15) << lo << "\n";
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