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

template<typename T, typename Func>
struct SparseTable {
  int _n, _log;
  std::vector<std::vector<T>> _f;

  constexpr explicit SparseTable(const std::vector<T>& init) {
    build(init);
  }

  void build(const std::vector<T>& init) {
    _n = static_cast<int>(init.size());
    if (_n == 0) return;

    _log = 32 - __builtin_clz(_n);
    _f.assign(_n, std::vector<T>(_log));

    for (int i = 0; i < _n; ++i) {
      _f[i][0] = init[i];
    }

    for (int j = 1; j < _log; ++j) {
      int step = 1 << (j - 1);
      for (int i = 0; i + (1 << j) <= _n; ++i) {
        _f[i][j] = Func{}(_f[i][j - 1], _f[i + step][j - 1]);
      }
    }
  }

  T query(int l, int r) const {
    if (l > r) std::swap(l, r);
    int t = 31 - __builtin_clz(r - l + 1);
    return Func{}(_f[l][t], _f[r - (1 << t) + 1][t]);
  }
};

struct MinOp {
  template<typename T>
  constexpr T operator()(const T& a, const T& b) const {
    return a < b ? a : b;
  }
};

void solve(){
  int n, q;
  std::cin >> n >> q;
  
  std::vector<i64> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::string s;
  std::cin >> s;
  s = " " + s;

  std::vector<i64> pre(n + 1);
  for(int i = 1; i <= n; i++){
    if(s[i] == '+'){
      pre[i] = pre[i - 1] + a[i];
    }else{
      pre[i] = pre[i - 1] - a[i];
    }
  }
  SparseTable<i64, MinOp> st(pre);

  for(int i = 0; i < q; i++){
    int pos;
    char op;
    std::cin >> pos >> op;

    if(s[pos] == op){
      std::cout << (st.query(0, n) >= 0 ? "YES\n" : "NO\n");
    }else{
      if(op == '+'){
        if(st.query(0, pos - 1) < 0){
          std::cout << "NO\n";
        }else{
          std::cout << (st.query(pos, n) + 2 * a[pos] >= 0 ? "YES\n" : "NO\n");
        }
      }else{
        if(st.query(0, pos - 1) < 0){
          std::cout << "NO\n";
        }else{
          std::cout << (st.query(pos, n) - 2 * a[pos] >= 0 ? "YES\n" : "NO\n");
        }
      }
    }
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}