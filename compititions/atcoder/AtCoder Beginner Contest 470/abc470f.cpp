#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr double eps = 1E-10;
constexpr double pi = std::numbers::pi;
constexpr double e = std::numbers::e;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

template<class T1, class T2>
using hash_map = __gnu_pbds::gp_hash_table<T1, T2>;

template<class T1, class T2>
struct std::tr1::hash<std::pair<T1, T2>> {
  std::size_t operator()(std::pair<T1, T2> x) const {
    std::tr1::hash<T1> h1;
    std::tr1::hash<T2> h2;
    return h1(x.first) ^ h2(x.second); // 自定义hash函数
  }
};

/**
 *    自动取模类
 *    一般定义模数为P
 *    P必须为质数，否则不满足费马小定理，在处理逆元时会出错
**/
template<class T>
constexpr T power(T a, i64 b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

template<int P>
struct MInt {
  int x;
  constexpr MInt() : x{} {}
  constexpr MInt(i64 x) : x{norm(x % getMod())} {}

  static int Mod;
  constexpr static int getMod() {
    if (P > 0) {
      return P;
    } else {
      return Mod;
    }
  }
  constexpr static void setMod(int Mod_) {
    Mod = Mod_;
  }
  constexpr int norm(int x) const {
    if (x < 0) {
      x += getMod();
    }
    if (x >= getMod()) {
      x -= getMod();
    }
    return x;
  }
  constexpr int val() const {
    return x;
  }
  explicit constexpr operator int() const {
    return x;
  }
  constexpr MInt operator-() const {
    MInt res;
    res.x = norm(getMod() - x);
    return res;
  }
  constexpr MInt inv() const {
    assert(x != 0);
    return power(*this, getMod() - 2);
  }
  constexpr MInt& operator*=(MInt rhs)& {
    x = 1LL * x * rhs.x % getMod();
    return *this;
  }
  constexpr MInt& operator+=(MInt rhs)& {
    x = norm(x + rhs.x);
    return *this;
  }
  constexpr MInt& operator-=(MInt rhs)& {
    x = norm(x - rhs.x);
    return *this;
  }
  constexpr MInt& operator/=(MInt rhs)& {
    return *this *= rhs.inv();
  }
  friend constexpr MInt operator*(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res *= rhs;
    return res;
  }
  friend constexpr MInt operator+(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res += rhs;
    return res;
  }
  friend constexpr MInt operator-(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res -= rhs;
    return res;
  }
  friend constexpr MInt operator/(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res /= rhs;
    return res;
  }
  friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
    i64 v;
    is >> v;
    a = MInt(v);
    return is;
  }
  friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) {
    return os << a.val();
  }
  friend constexpr bool operator==(MInt lhs, MInt rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr bool operator!=(MInt lhs, MInt rhs) {
    return lhs.val() != rhs.val();
  }
};

/**
 *    模板全特化
 *    使用动态模数（运行时确定）
 *    using Z2 = MInt<0>;       // 模数在运行时设置
 *    Z2::setMod(1000000007);   // 重新设置模数为1000000007
**/
template<>
int MInt<0>::Mod = 998244353;

/**
 *    用于编译期就计算好逆元，可以用于不同的模数
 *    如求2在模数1000000007下的逆元
 *    constexpr auto inv2 = CInv<2, 1000000007>;
**/
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = P2;
using Z = MInt<P>;

/**
 *    组合数
 *    需要搭配自动取模类Z一起食用
**/
struct Comb {
  int n;
  std::vector<Z> _fac;
  std::vector<Z> _invfac;
  std::vector<Z> _inv;

  Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
  Comb(int n) : Comb() {
    init(n);
  }

  void init(int m) {
    if (m <= n) return;
    _fac.resize(m + 1);
    _invfac.resize(m + 1);
    _inv.resize(m + 1);

    for (int i = n + 1; i <= m; i++) {
      _fac[i] = _fac[i - 1] * i;
    }
    _invfac[m] = _fac[m].inv();
    for (int i = m; i > n; i--) {
      _invfac[i - 1] = _invfac[i] * i;
      _inv[i] = _invfac[i] * _fac[i - 1];
    }
    n = m;
  }

  Z fac(int m) {
    if (m > n) init(2 * m);
    return _fac[m];
  }
  Z invfac(int m) {
    if (m > n) init(2 * m);
    return _invfac[m];
  }
  Z inv(int m) {
    if (m > n) init(2 * m);
    return _inv[m];
  }
  Z binom(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac(n) * invfac(m) * invfac(n - m);
  }
  Z permu(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac(n) * invfac(n - m);
  }
} comb;

struct DSU {
  int _n;
  std::vector<int> _fa, _size;
  DSU() {}
  DSU(int n) {
    init(n);
  }
  void init(int n) {
    _fa.resize(n);
    std::iota(_fa.begin(), _fa.end(), 0);
    _size.assign(n, 1);
  }
  int find(int x) {
    if (x != _fa[x]) {
      _fa[x] = find(_fa[x]);
    }
    return _fa[x];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      _size[fx] += _size[fy];
      _fa[fy] = fx;
      return true;
    }
    return false;
  }
};

/*
2 4 5

===>
5 4 2
5 2 4
4 2 5
2 5 4
4 5 2
2 4 5
*/

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::string s;
  std::cin >> s;
  s = " " + s;

  DSU dsu(n + 1);
  for(int i = 0; i < m; i++){
    int a, b;
    std::cin >> a >> b;

    dsu.merge(a, b);
  }

  hash_map<int, std::vector<int>> map;
  for(int i = 1; i <= n; i++){
    int f = dsu.find(i);
    // std::cout << f << " \n"[i == n];
    map[f].push_back(s[i] - 'a');
  }

  Z ans = 1;
  bool chk = true;
  for(const auto& [u, v] : map){
    std::vector<int> cnt(26);
    for(const auto& vi : v){
      cnt[vi]++;
    }

    int sum = v.size();
    if(std::count_if(cnt.begin(), cnt.end(), [&](int x){return x > 1;}) > 0){
      chk = false;
    }
    ans *= comb.fac(sum);
    for(int i = 0; i < 26; i++){
      if(cnt[i]){
        ans *= comb.invfac(cnt[i]);
      }
    }
  }

  std::cout << (chk ? ans * Z(2).inv() : ans) << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++){
    solve();
  }

  return 0;
}