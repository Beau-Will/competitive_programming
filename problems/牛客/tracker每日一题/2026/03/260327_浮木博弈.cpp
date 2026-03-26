#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  a.insert(a.end(), {1, 2});

  int idx = std::find_if(a.begin(), a.end(), [&](int x){return x > 1;}) - a.begin();
  std::cout << (idx & 1 ? "Bob\n" : "Alice\n");
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