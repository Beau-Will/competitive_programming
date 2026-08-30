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
constexpr int P = P1;

template<class T>
constexpr T power(T a, u64 b, T res = 1) {
  for (; b != 0; b /= 2, a *= a) {
    if (b & 1) {
      res *= a;
    }
  }
  return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
  return u64(a) * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
  u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
  res %= P;
  return res;
}

constexpr i64 safeMod(i64 x, i64 m) {
  x %= m;
  if (x < 0) {
    x += m;
  }
  return x;
}

constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
  a = safeMod(a, b);
  if (a == 0) {
    return {b, 0};
  }

  i64 s = b, t = a;
  i64 m0 = 0, m1 = 1;

  while (t) {
    i64 u = s / t;
    s -= t * u;
    m0 -= m1 * u;

    std::swap(s, t);
    std::swap(m0, m1);
  }

  if (m0 < 0) {
    m0 += b / s;
  }

  return {s, m0};
}

template<std::unsigned_integral U, U P>
struct ModIntBase {
 public:
  constexpr ModIntBase() : x(0) {}
  template<std::unsigned_integral T>
  constexpr ModIntBase(T x_) : x(x_ % mod()) {}
  template<std::signed_integral T>
  constexpr ModIntBase(T x_) {
    using S = std::make_signed_t<U>;
    S v = x_ % S(mod());
    if (v < 0) {
      v += mod();
    }
    x = v;
  }

  constexpr static U mod() {
    return P;
  }

  constexpr U val() const {
    return x;
  }

  constexpr ModIntBase operator-() const {
    ModIntBase res;
    res.x = (x == 0 ? 0 : mod() - x);
    return res;
  }

  constexpr ModIntBase inv() const {
    return power(*this, mod() - 2);
  }

  constexpr ModIntBase& operator*=(const ModIntBase& rhs)& {
    x = mulMod<mod()>(x, rhs.val());
    return *this;
  }
  constexpr ModIntBase& operator+=(const ModIntBase& rhs)& {
    x += rhs.val();
    if (x >= mod()) {
      x -= mod();
    }
    return *this;
  }
  constexpr ModIntBase& operator-=(const ModIntBase& rhs)& {
    x -= rhs.val();
    if (x >= mod()) {
      x += mod();
    }
    return *this;
  }
  constexpr ModIntBase& operator/=(const ModIntBase& rhs)& {
    return *this *= rhs.inv();
  }

  friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase& rhs) {
    lhs *= rhs;
    return lhs;
  }
  friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase& rhs) {
    lhs += rhs;
    return lhs;
  }
  friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase& rhs) {
    lhs -= rhs;
    return lhs;
  }
  friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase& rhs) {
    lhs /= rhs;
    return lhs;
  }

  friend constexpr std::istream& operator>>(std::istream& is, ModIntBase& a) {
    i64 i;
    is >> i;
    a = i;
    return is;
  }
  friend constexpr std::ostream& operator<<(std::ostream& os,
      const ModIntBase& a) {
    return os << a.val();
  }

  friend constexpr bool operator==(const ModIntBase& lhs, const ModIntBase& rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr std::strong_ordering operator<=> (const ModIntBase& lhs,
      const ModIntBase& rhs) {
    return lhs.val() <=> rhs.val();
  }

 private:
  U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;
template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

struct Barrett {
 public:
  Barrett(u32 m_) : m(m_), im((u64)(-1) / m_ + 1) {}

  constexpr u32 mod() const {
    return m;
  }

  constexpr u32 mul(u32 a, u32 b) const {
    u64 z = a;
    z *= b;

    u64 x = u64((u128(z) * im) >> 64);

    u32 v = u32(z - x * m);
    if (m <= v) {
      v += m;
    }
    return v;
  }

 private:
  u32 m;
  u64 im;
};

template<u32 Id>
struct DynModInt {
 public:
  constexpr DynModInt() : x(0) {}
  template<std::unsigned_integral T>
  constexpr DynModInt(T x_) : x(x_ % mod()) {}
  template<std::signed_integral T>
  constexpr DynModInt(T x_) {
    int v = x_ % int(mod());
    if (v < 0) {
      v += mod();
    }
    x = v;
  }

  constexpr static void setMod(u32 m) {
    bt = m;
  }

  static u32 mod() {
    return bt.mod();
  }

  constexpr u32 val() const {
    return x;
  }

  constexpr DynModInt operator-() const {
    DynModInt res;
    res.x = (x == 0 ? 0 : mod() - x);
    return res;
  }

  constexpr DynModInt inv() const {
    auto v = invGcd(x, mod());
    assert(v.first == 1);
    return v.second;
  }

  constexpr DynModInt& operator*=(const DynModInt& rhs)& {
    x = bt.mul(x, rhs.val());
    return *this;
  }
  constexpr DynModInt& operator+=(const DynModInt& rhs)& {
    x += rhs.val();
    if (x >= mod()) {
      x -= mod();
    }
    return *this;
  }
  constexpr DynModInt& operator-=(const DynModInt& rhs)& {
    x -= rhs.val();
    if (x >= mod()) {
      x += mod();
    }
    return *this;
  }
  constexpr DynModInt& operator/=(const DynModInt& rhs)& {
    return *this *= rhs.inv();
  }

  friend constexpr DynModInt operator*(DynModInt lhs, const DynModInt& rhs) {
    lhs *= rhs;
    return lhs;
  }
  friend constexpr DynModInt operator+(DynModInt lhs, const DynModInt& rhs) {
    lhs += rhs;
    return lhs;
  }
  friend constexpr DynModInt operator-(DynModInt lhs, const DynModInt& rhs) {
    lhs -= rhs;
    return lhs;
  }
  friend constexpr DynModInt operator/(DynModInt lhs, const DynModInt& rhs) {
    lhs /= rhs;
    return lhs;
  }

  friend constexpr std::istream& operator>>(std::istream& is, DynModInt& a) {
    i64 i;
    is >> i;
    a = i;
    return is;
  }
  friend constexpr std::ostream& operator<<(std::ostream& os,
      const DynModInt& a) {
    return os << a.val();
  }

  friend constexpr bool operator==(const DynModInt& lhs, const DynModInt& rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr std::strong_ordering operator<=> (const DynModInt& lhs,
      const DynModInt& rhs) {
    return lhs.val() <=> rhs.val();
  }

 private:
  u32 x;
  static Barrett bt;
};

template<u32 Id>
Barrett DynModInt<Id>::bt = 998244353;

using Z = ModInt<P>;

template<class T>
struct Fenwick{
  int _n;
  std::vector<T> _tr;

  Fenwick(int n): _n(n), _tr(n + 1){}

  static int lowbit(int x){
    return x & (-x);
  }
  void add(int idx, T v){
    for(; idx <= _n; idx += lowbit(idx)){
      _tr[idx] += v;
    }
  }

  T sum(int idx){
    T res {};
    for(; idx >= 1; idx -= lowbit(idx)){
      res += _tr[idx];
    }
    return res;
  }

  void range_add(int l, int r, T v){
    add(l, v);
    if(r + 1 <= _n){
      add(r + 1, -v);
    }
  }
};

using BIT = Fenwick<Z>;

/**
 * 树链剖分（HLD）模板 - 1-based版本
 * 节点编号从1开始
 */
struct HLD {
  int n;
  std::vector<int> siz, top, dep, parent, in, out, seq;
  std::vector<std::vector<int>> adj;
  int cur;

  HLD() {}
  HLD(int n) {
    init(n);
  }

  void init(int n) {
    this->n = n;
    siz.resize(n + 1);
    top.resize(n + 1);
    dep.resize(n + 1);
    parent.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    seq.resize(n + 1);
    cur = 1;
    adj.assign(n + 1, {});
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void work(int root = 1) {
    top[root] = root;
    dep[root] = 0;
    parent[root] = 0;
    dfs1(root);
    dfs2(root);
  }

  void dfs1(int u) {
    if (parent[u] != 0) {
      adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
    }

    siz[u] = 1;
    for (auto& v : adj[u]) {
      parent[v] = u;
      dep[v] = dep[u] + 1;
      dfs1(v);
      siz[u] += siz[v];
      if (siz[v] > siz[adj[u][0]]) {
        std::swap(v, adj[u][0]);
      }
    }
  }

  void dfs2(int u) {
    in[u] = cur++;
    seq[in[u]] = u;
    for (auto v : adj[u]) {
      top[v] = (v == adj[u][0]) ? top[u] : v;
      dfs2(v);
    }
    out[u] = cur;
  }

  int lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = parent[top[u]];
      } else {
        v = parent[top[v]];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

  int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int jump(int u, int k) {
    if (dep[u] < k) {
      return 0;
    }

    int d = dep[u] - k;
    while (dep[top[u]] > d) {
      u = parent[top[u]];
    }
    return seq[in[u] - dep[u] + d];
  }

  bool isAncestor(int u, int v) {
    return in[u] <= in[v] && in[v] < out[u];
  }

  int rootedParent(int u, int v) {
    std::swap(u, v);
    if (u == v) {
      return u;
    }
    if (!isAncestor(u, v)) {
      return parent[u];
    }
    auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v,
    [&](int x, int y) {
      return in[x] < in[y];
    }) - 1;
    return *it;
  }

  int rootedSize(int u, int v) {
    if (u == v) {
      return n;
    }
    if (!isAncestor(v, u)) {
      return siz[v];
    }
    return n - siz[rootedParent(u, v)];
  }

  int rootedLca(int a, int b, int c) {
    return lca(a, b) ^ lca(b, c) ^ lca(c, a);
  }
};

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::string s;
  std::cin >> s;
  s = " " + s;

  std::vector<Z> pow2(n + 1);
  pow2[0] = 1;
  for(int i = 1; i <= n; i++){
    pow2[i] = pow2[i - 1] * 2;
  }

  HLD hld(n);

  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;

    hld.addEdge(u, v);
  }

  hld.work(1);

  BIT bit(n);
  for(int i = 1; i <= n; i++){
    bit.add(hld.in[i], Z(s[i] ^ 48) * pow2[hld.dep[i]]);
  }

  for(int i = 0; i < q; i++){
    std::string op;
    int u;

    std::cin >> op >> u;

    if(op == "F"){
      int prev = s[u] ^ 48;
      s[u] = '1' - s[u] + '0';
      int cur = s[u] ^ 48;

      Z d = Z(cur - prev) * pow2[hld.dep[u]];

      bit.add(hld.in[u], d);
    }else{
      Z ans = 0;
      int cur = u;

      while(cur){
        int t = hld.top[cur];
        
        ans += bit.sum(hld.in[cur]) - bit.sum(hld.in[t] - 1);
        cur = hld.parent[t];
      }

      std::cout << ans << "\n";
    }
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}