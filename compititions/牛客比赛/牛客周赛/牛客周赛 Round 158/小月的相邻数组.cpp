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

template<typename T>
struct SqrtDecomposition {
  int n;
  int B;
  std::vector<T> a;
  std::vector<T> sum;
  std::vector<int> at;

  SqrtDecomposition(const std::vector<T>& init) {
    n = init.size() - 1;
    B = std::max(1, static_cast<int>(std::sqrt(n)));
    a = init;

    sum.assign(n / B + 2, 0);
    at.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      at[i] = (i - 1) / B + 1;
      sum[at[i]] += a[i];
    }
  }

  template<typename U>
  void modify(int pos, U x) {
    int p = at[pos];
    T nx = static_cast<T>(x);
    sum[p] += nx - a[pos];
    a[pos] = nx;
  }

  T rangeQuery(int l, int r) {
    if(l > r) return T{};

    int L = at[l], R = at[r];
    T res {};

    if(L == R){
      for(int i = l; i <= r; i++) res += a[i];
      return res;
    }

    for(int i = l; at[i] == L; i++){
      res += a[i];
    }
    for(int b = L + 1; b < R; b++){
      res += sum[b];
    }
    for(int i = r; at[i] == R; i--){
      res += a[i];
    }
    return res;
  }
};

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> diff(n + 1);
  for(int i = 1; i <= n; i++){
    diff[i] = a[i] - a[i - 1];
  }

  std::vector<int> init(n + 1);
  for(int i = 2; i + 1 <= n; i++){
    init[i] = (diff[i] < diff[i + 1]);
  }

  SqrtDecomposition<int> sd(init);

  auto work = [&](int pos){
    if(pos < 2 || pos > n - 1) return;
    int x = (diff[pos] < diff[pos + 1]);
    sd.modify(pos, x);
  };

  for(int i = 0; i < q; i++){
    int op;
    std::cin >> op;

    if(op == 1){
      int p, x;
      std::cin >> p >> x;

      a[p] = x;
      diff[p] = a[p] - a[p - 1];
      if(p + 1 <= n) diff[p + 1] = a[p + 1] - a[p];

      for(int i = std::max(2, p - 1); i <= std::min(n - 1, p + 1); i++){
        work(i);
      }
    }else{
      int l, r;
      std::cin >> l >> r;

      std::cout << sd.rangeQuery(l + 1, r - 1) << "\n";
    }
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}