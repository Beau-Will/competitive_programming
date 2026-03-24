#include <iostream>
#include <vector>

void solve(){
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  auto get = [&](int x){
    int res = 1E9;
    for(int i = 0; i < x; i++){
      int cur = 0;
      for(int j = i; j < n; j += x){
        if(a[j] ^ k){
          cur++;
        }
      }
      res = std::min(res, cur);
    }
    return res;
  };

  int ans = 1E9;
  for(int i = m; i > 0 && m - i < ans; i--){
    ans = std::min(ans, m - i + get(i));
  }

  for(int i = m + 1; i - m < ans; i++){
    ans = std::min(ans, i - m + get(i));
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int i = 0; i < T; i++){
    solve();
  }

  return 0;
}