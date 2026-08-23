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
constexpr int P = P2;

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

template<typename Coef = i64>
struct OGF {
  using value_type = Coef;
  using size_type = std::size_t;

  std::vector<Coef> coeffs;

  OGF() = default;
  explicit OGF(size_type n) : coeffs(n, Coef(0)) {}
  OGF(std::initializer_list<Coef> list) : coeffs(list) {}
  OGF(const std::vector<Coef>& v) : coeffs(v) {}
  OGF(std::vector<Coef>&& v) : coeffs(std::move(v)) {}

  OGF(int low, int high, Coef val = Coef(1)) {
    if (low > high) return;
    coeffs.resize(high + 1, Coef(0));
    for (int i = low; i <= high; ++i)
      coeffs[i] = val;
  }

  static OGF constant(Coef c) {
    OGF p(1);
    p.coeffs[0] = c;
    return p;
  }
  static OGF one() {
    return constant(Coef(1));
  }
  static OGF zero() {
    return OGF();
  }

  Coef at(size_type i) const {
    return i < coeffs.size() ? coeffs[i] : Coef(0);
  }

  void set(size_type i, Coef c) {
    if (i >= coeffs.size())
      coeffs.resize(i + 1, Coef(0));
    coeffs[i] = c;
  }

  size_type size() const {
    return coeffs.size();
  }
  bool empty() const {
    return coeffs.empty();
  }

  int degree() const {
    if (coeffs.empty()) return -1;
    int d = static_cast<int>(coeffs.size()) - 1;
    while (d >= 0 && coeffs[d] == Coef(0)) d--;
    return d;
  }

  OGF& trim() {
    while (!coeffs.empty() && coeffs.back() == Coef(0))
      coeffs.pop_back();
    return *this;
  }

  OGF operator+(const OGF& other) const {
    size_type n = std::max(coeffs.size(), other.coeffs.size());
    OGF res(n);
    for (size_type i = 0; i < n; ++i)
      res.coeffs[i] = this->at(i) + other.at(i);
    res.trim();
    return res;
  }

  OGF mul(const OGF& other, int max_degree = -1) const {
    if (coeffs.empty() || other.coeffs.empty())
      return OGF();

    size_type n1 = coeffs.size();
    size_type n2 = other.coeffs.size();
    size_type res_size = n1 + n2 - 1;
    if (max_degree >= 0)
      res_size = std::min<size_type>(res_size, max_degree + 1);

    OGF res(res_size);
    for (size_type i = 0; i < n1; ++i) {
      if (coeffs[i] == Coef(0)) continue;
      for (size_type j = 0; j < n2; ++j) {
        if (i + j >= res_size) break;
        if (other.coeffs[j] == Coef(0)) continue;
        res.coeffs[i + j] += coeffs[i] * other.coeffs[j];
      }
    }
    return res;
  }

  OGF operator*(const OGF& other) const {
    return mul(other);
  }

  void print(std::ostream& os = std::cout) const {
    bool first = true;
    for (size_type i = 0; i < coeffs.size(); ++i) {
      if (coeffs[i] != Coef(0)) {
        if (!first) os << " + ";
        os << coeffs[i] << "x^" << i;
        first = false;
      }
    }
    if (first) os << "0";
  }

  friend std::ostream& operator<<(std::ostream& os, const OGF& p) {
    p.print(os);
    return os;
  }
};

using Poly = OGF<Z>;

void solve(){
  i64 n;
  int r;
  std::cin >> n >> r;

  auto work = [&](const Poly& a, const Poly& b){
    Poly prod = a.mul(b);

    Poly res(4);
    for(int i = 0; i < prod.coeffs.size(); i++){
      res.coeffs[i & 3] += prod.coeffs[i];
    }
    return res;
  };

  Poly ans = Poly::one();
  Poly base {Z(1), Z(1), Z(0), Z(1)};

  while(n){
    if(n & 1){
      ans = work(ans, base);
    }
    base = work(base, base);
    n >>= 1;
  }

  std::cout << ans.at(r) << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}