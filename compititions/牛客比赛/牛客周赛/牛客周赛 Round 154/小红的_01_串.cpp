#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/*
下标1base
*/
template<typename T>
struct Fenwick {
  int n;
  std::vector<T> tr;

  Fenwick(int n) : n(n), tr(n + 1, 0) {}

  int lowbit(int x) {
    return x & -x;
  }

  void modify(int x, T c) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] ^= c;
  }

  T query(int x) {
    T res = T{};
    for (int i = x; i; i -= lowbit(i)) res ^= tr[i];
    return res;
  }
};

using BIT = Fenwick<int>;

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::string s;
  std::cin >> s;
  
  if(n == 1){
    for(int i = 0; i < q; i++){
      int l, r;
      std::cin >> l >> r;

      std::cout << "0\n";
    }
    return;
  }

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    a[i] = s[i] - '0';
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += (a[i] != a[(i + 1) % n]);
  }

  BIT bit(n + 5);

  auto get = [&](int idx) -> int {
    return a[idx] ^ bit.query(idx + 1);
  };

  for(int i = 0; i < q; i++){
    int l, r;
    std::cin >> l >> r;

    int len = ((l <= r) ? (r - l + 1) : (n - l + r + 1));

    if(len == n){
      bit.modify(1, 1);
      std::cout << ans << "\n";
      continue;
    }

    int l_1 = (l - 1 + n) % n;
    int r_1 = (r + 1) % n;

    int t1 = ((get(l_1) != get(l)) ? 1 : 0);
    int t2 = ((get(r) != get(r_1)) ? 1 : 0);

    ans -= t1 + t2;

    int L = l + 1, R = r + 1;
    if(L <= R){
      bit.modify(L, 1);
      bit.modify(R + 1, 1);
    }else{
      bit.modify(1, 1);
      bit.modify(R + 1, 1);
      bit.modify(L, 1);
    }

    ans += (1 - t1) + (1 - t2);

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