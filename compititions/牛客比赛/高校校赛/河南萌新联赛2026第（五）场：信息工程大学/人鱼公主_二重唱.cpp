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
constexpr int inf = inf1;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

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
  // constexpr ModIntBase& operator-=(const ModIntBase& rhs)& {
  //   x -= rhs.val();
  //   if (x >= mod()) {
  //     x += mod();
  //   }
  //   return *this;
  // }
  constexpr ModIntBase& operator-=(const ModIntBase& rhs)& {
    x = (x >= rhs.val() ? x - rhs.val() : x + mod() - rhs.val());
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

constexpr int P = P2;
using Z = ModInt<P2>;

/*
 * 修改后的懒标记线段树是1-based的，用于构造的init_数组也是1-based
 * 区间查询和区间修改的区间[l,r]皆为左闭右闭，为1-based
 */
template<class Info, class Tag>
struct LazySegmentTree {
  int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree() : n(0) {}
  LazySegmentTree(int n_, Info v_ = Info()) {
    init(n_, v_);
  }
  template<class T>
  LazySegmentTree(std::vector<T> init_) {
    init(init_);
  }
  void init(int n_, Info v_ = Info()) {
    init(std::vector<Info>(n_ + 1, v_));
  }
  template<class T>
  void init(std::vector<T> init_) {
    n = init_.size() - 1;
    info.assign(4 * (n + 5), Info());
    tag.assign(4 * (n + 5), Tag());
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (l == r) {
        info[p] = init_[l];
        return;
      }
      int m = (l + r) / 2;
      build(p * 2, l, m);
      build(p * 2 + 1, m + 1, r);
      pull(p);
    };
    build(1, 1, n);
  }
  void pull(int p) {
    info[p] = info[p * 2] + info[p * 2 + 1];
  }
  void apply(int p, const Tag& v) {
    info[p].apply(v);
    tag[p].apply(v);
  }
  void push(int p) {
    apply(p * 2, tag[p]);
    apply(p * 2 + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info& v) {
    if (l == r) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x <= m) {
      modify(p * 2, l, m, x, v);
    } else {
      modify(p * 2 + 1, m + 1, r, x, v);
    }
    pull(p);
  }
  void modify(int x, const Info& v) {
    modify(1, 1, n, x, v);
  }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l > y || r < x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    push(p);
    return rangeQuery(p * 2, l, m, x, y) + rangeQuery(p * 2 + 1, m + 1, r, x, y);  // 修改：右子区间从m+1开始
  }
  Info rangeQuery(int l, int r) {
    return rangeQuery(1, 1, n, l, r);
  }
  void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
    if (l > y || r < x) {
      return;
    }
    if (l >= x && r <= y) {
      apply(p, v);
      return;
    }
    int m = (l + r) / 2;
    push(p);
    rangeApply(p * 2, l, m, x, y, v);
    rangeApply(p * 2 + 1, m + 1, r, x, y, v);
    pull(p);
  }
  void rangeApply(int l, int r, const Tag& v) {
    return rangeApply(1, 1, n, l, r, v);
  }
  void half(int p, int l, int r) {
    if (info[p].act == 0) {
      return;
    }
    if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
      apply(p, {-(info[p].min + 1) / 2});
      return;
    }
    int m = (l + r) / 2;
    push(p);
    half(p * 2, l, m);
    half(p * 2 + 1, m + 1, r);
    pull(p);
  }
  void half() {
    half(1, 1, n);
  }

  template<class F>
  int findFirst(int p, int l, int r, int x, int y, F&& pred) {
    if (l > y || r < x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (l == r) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findFirst(p * 2, l, m, x, y, pred);
    if (res == -1) {
      res = findFirst(p * 2 + 1, m + 1, r, x, y, pred);
    }
    return res;
  }
  template<class F>
  int findFirst(int l, int r, F&& pred) {
    return findFirst(1, 1, n, l, r, pred);
  }
  template<class F>
  int findLast(int p, int l, int r, int x, int y, F&& pred) {
    if (l > y || r < x) {
      return -1;
    }
    if (l >= x && r <= y && !pred(info[p])) {
      return -1;
    }
    if (l == r) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findLast(p * 2 + 1, m + 1, r, x, y, pred);
    if (res == -1) {
      res = findLast(p * 2, l, m, x, y, pred);
    }
    return res;
  }
  template<class F>
  int findLast(int l, int r, F&& pred) {
    return findLast(1, 1, n, l, r, pred);
  }

  void maintainL(int p, int l, int r, int pre) {
    if (info[p].difl > 0 && info[p].maxlowl < pre) {
      return;
    }
    if (l == r) {
      info[p].max = info[p].maxlowl;
      info[p].maxl = info[p].maxr = l;
      info[p].maxlowl = info[p].maxlowr = -inf;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    maintainL(p * 2, l, m, pre);
    pre = std::max(pre, info[p * 2].max);
    maintainL(p * 2 + 1, m + 1, r, pre);
    pull(p);
  }
  void maintainL() {
    maintainL(1, 1, n, -1);
  }
  void maintainR(int p, int l, int r, int suf) {
    if (info[p].difr > 0 && info[p].maxlowr < suf) {
      return;
    }
    if (l == r) {
      info[p].max = info[p].maxlowl;
      info[p].maxl = info[p].maxr = l;
      info[p].maxlowl = info[p].maxlowr = -inf;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    maintainR(p * 2 + 1, m + 1, r, suf);
    suf = std::max(suf, info[p * 2 + 1].max);
    maintainR(p * 2, l, m, suf);
    pull(p);
  }
  void maintainR() {
    maintainR(1, 1, n, -1);
  }
};

struct Tag {
  bool vis;
  Z add, set;

  Tag(): vis(false), set(0), add(0) {}
  Tag(bool _vis, Z _set, Z _add): add(_add), set(_set), vis(_vis) {}

  static Tag Add(Z x) {return Tag(false, Z(0), x);}
  static Tag Set(Z x) {return Tag(true, x, Z(0));}

  void apply(const Tag& t)& {
    if(t.vis){
      vis = true;
      set = t.set;
      add = t.add;
    }else{
      add += t.add;
    }
  }
};

struct Info {
  Z len = 0, s1 = 0, s2 = 0, s3 = 0;

  Info() = default;
  Info(Z x): len(1), s1(x), s2(x * x), s3(x * x * x) {}
  
  void apply(const Tag& t)& {
    if(t.vis){
      Z x = t.set + t.add;
      s1 = len * x;
      s2 = len * x * x;
      s3 = len * x * x * x;
    }else if(t.add.val() != 0){
      Z x = t.add;
      s3 += 3 * x * s2 + 3 * x * x * s1 + len * x * x * x;
      s2 += 2 * x * s1 + len * x * x;
      s1 += len * x;
    }
  }
};

Info operator+(const Info& a, const Info& b) {
  Info c;
  c.len = a.len + b.len;
  c.s1 = a.s1 + b.s1;
  c.s2 = a.s2 + b.s2;
  c.s3 = a.s3 + b.s3;
  return c;
}

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<Info> init(n + 1);
  for(int i = 1; i <= n; i++){
    i64 x;
    std::cin >> x;
    init[i] = Info(Z(x));
  }

  LazySegmentTree<Info, Tag> lsgt(init);

  for(int i = 0; i < m; i++){
    int op, l, r;
    std::cin >> op >> l >> r;

    if(op == 1){
      i64 x;
      std::cin >> x;

      lsgt.rangeApply(l, r, Tag::Add(Z(x)));
    }else if(op == 2){
      i64 x;
      std::cin >> x;

      lsgt.rangeApply(l, r, Tag::Set(Z(x)));
    }else{
      Info res = lsgt.rangeQuery(l, r);
      Z n = res.len;
      Z inv = n.inv();
      Z t = res.s1 * inv;

      if(op == 3){
        Z ans = res.s2 * inv - t * t;

        std::cout << ans << "\n";
      }else{
        Z t2 = res.s2 * inv;
        Z t3 = res.s3 * inv;
        Z ans = t3 - 3 * t * t2 + 2 * t * t * t;

        std::cout << ans << "\n";
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