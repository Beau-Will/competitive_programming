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

  std::vector<int> b;
  int max = 0, cnt = 0;
  for(int i = 0; i < n; i++){
    if(a[i] > max){
      max = a[i];
      cnt++;
    }else{
      b.push_back(a[i]);
    }
  }

  int lis = 0;
  std::vector<int> q(b.size() + 1);
  q[0] = -(inf1 + 1);
  for(int i = 0; i < b.size(); i++){
    int idx = std::lower_bound(q.begin(), q.begin() + lis + 1, b[i]) - q.begin() - 1;
    lis = std::max(lis, idx + 1);
    q[idx + 1] = b[i];
  }

  std::cout << cnt + lis << "\n";
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