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

#pragma once

/**
 * @file matrix.hpp
 * @brief 轻量级矩阵类模板，适用于算法竞赛场景。
 *
 * 提供基本的矩阵运算、快速幂、转置、高斯消元、求逆等功能。
 * 内部使用一维 std::vector 存储元素，行优先顺序。
 * 模板参数 T 需要支持 +, -, *, /, 默认构造以及 0/1 等运算。
 * 若 T 提供静态成员函数 id()，则将其返回值作为单位元；否则使用 T(1)。
 *
 * 注意：本实现为算法竞赛设计，未做完整的异常处理，
 * 必要的维度检查通过 assert 完成。
 */

#include <cassert>
#include <cmath>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

using i64 = long long;

namespace matrix_impl {

template <typename...>
using void_t = void;

// 用于检测类型 T 是否具有静态成员函数 id()
template <typename T, typename = void>
struct has_id : std::false_type {};

template <typename T>
struct has_id<T, void_t<decltype(T::id())>> : std::true_type {};

} // namespace matrix_impl

template <typename T>
struct matrix {
  int rows_;
  int cols_;
  std::vector<T> data;

  // ---------- 构造与基本访问 ----------

  constexpr matrix() : rows_(0), cols_(0), data() {}

  constexpr matrix(int r, int c)
      : rows_(r), cols_(c), data(r * c) {
    assert(r >= 0 && c >= 0);
  }

  constexpr matrix(int r, int c, const T &init)
      : rows_(r), cols_(c), data(r * c, init) {
    assert(r >= 0 && c >= 0);
  }

  // 从二维 vector 构造
  matrix(const std::vector<std::vector<T>> &grid)
      : rows_(static_cast<int>(grid.size())),
        cols_(rows_ ? static_cast<int>(grid[0].size()) : 0) {
    data.reserve(rows_ * cols_);
    for (const auto &row : grid) {
      assert(static_cast<int>(row.size()) == cols_);
      data.insert(data.end(), row.begin(), row.end());
    }
  }

  // 获取行数
  constexpr int row() const { return rows_; }
  // 获取列数
  constexpr int col() const { return cols_; }

  // 带边界检查的元素访问（推荐使用）
  constexpr T &operator()(int i, int j) {
    assert(i >= 0 && i < rows_ && j >= 0 && j < cols_);
    return data[i * cols_ + j];
  }

  constexpr const T &operator()(int i, int j) const {
    assert(i >= 0 && i < rows_ && j >= 0 && j < cols_);
    return data[i * cols_ + j];
  }

  constexpr T &at(int i, int j) { return (*this)(i, j); }
  constexpr const T &at(int i, int j) const { return (*this)(i, j); }

  // 返回行指针，支持 m[i][j] 形式
  constexpr T *operator[](int i) {
    assert(i >= 0 && i < rows_);
    return data.data() + i * cols_;
  }

  constexpr const T *operator[](int i) const {
    assert(i >= 0 && i < rows_);
    return data.data() + i * cols_;
  }

  // ---------- 单位元与单位矩阵 ----------

  // 返回乘法单位元（若 T::id() 存在则调用，否则返回 T(1)）
  static constexpr T identity_element() {
    if constexpr (matrix_impl::has_id<T>::value) {
      return T::id();
    } else {
      return T(1);
    }
  }

  // 返回 n x n 单位矩阵
  static constexpr matrix identity(int n) {
    assert(n >= 0);
    matrix result(n, n);
    for (int i = 0; i < n; ++i) {
      result(i, i) = identity_element();
    }
    return result;
  }

  // 转换为二维 vector
  std::vector<std::vector<T>> to_vector2d() const {
    std::vector<std::vector<T>> result(rows_);
    for (int i = 0; i < rows_; ++i) {
      result[i].assign(data.begin() + i * cols_, data.begin() + (i + 1) * cols_);
    }
    return result;
  }

  // ---------- 算术运算符 ----------

  constexpr matrix operator-() const {
    matrix result = *this;
    for (auto &x : result.data) x = -x;
    return result;
  }

  constexpr matrix operator+(const matrix &other) const {
    assert(rows_ == other.rows_ && cols_ == other.cols_);
    matrix result(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
      result.data[i] = data[i] + other.data[i];
    }
    return result;
  }

  constexpr matrix operator-(const matrix &other) const {
    assert(rows_ == other.rows_ && cols_ == other.cols_);
    matrix result(rows_, cols_);
    for (int i = 0; i < rows_ * cols_; ++i) {
      result.data[i] = data[i] - other.data[i];
    }
    return result;
  }

  // 矩阵乘法（朴素 O(n^3)）
  constexpr matrix operator*(const matrix &other) const {
    assert(cols_ == other.rows_);
    matrix result(rows_, other.cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int k = 0; k < cols_; ++k) {
        for (int j = 0; j < other.cols_; ++j) {
          result(i, j) += (*this)(i, k) * other(k, j);
        }
      }
    }
    return result;
  }

  constexpr matrix operator*(const T &scalar) const {
    matrix result = *this;
    for (auto &x : result.data) x *= scalar;
    return result;
  }

  constexpr matrix operator/(const T &scalar) const {
    assert(scalar != T(0));
    matrix result = *this;
    T inv = identity_element() / scalar;
    for (auto &x : result.data) x *= inv;
    return result;
  }

  // 复合赋值
  constexpr matrix &operator*=(const T &scalar) { return *this = *this * scalar; }
  constexpr matrix &operator/=(const T &scalar) { return *this = *this / scalar; }
  constexpr matrix &operator+=(const matrix &other) { return *this = *this + other; }
  constexpr matrix &operator-=(const matrix &other) { return *this = *this - other; }
  constexpr matrix &operator*=(const matrix &other) { return *this = *this * other; }

  // 比较运算符
  constexpr bool operator==(const matrix &other) const {
    return rows_ == other.rows_ && cols_ == other.cols_ && data == other.data;
  }
  constexpr bool operator!=(const matrix &other) const { return !(*this == other); }

  // ---------- 命名的运算封装 ----------

  constexpr matrix add(const matrix &other) const { return *this + other; }
  constexpr matrix sub(const matrix &other) const { return *this - other; }
  constexpr matrix mul(const matrix &other) const { return *this * other; }

  // ---------- 转置 ----------

  constexpr matrix transpose() const {
    matrix result(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        result(j, i) = (*this)(i, j);
      }
    }
    return result;
  }

  // ---------- 快速幂 ----------

  // 矩阵快速幂，返回 I * A^n，即 A 的 n 次幂
  constexpr matrix power(i64 n) const {
    assert(n >= 0);
    assert(rows_ == cols_);
    matrix result = identity(rows_);
    matrix base = *this;
    while (n > 0) {
      if (n & 1) result = result * base;
      base = base * base;
      n >>= 1;
    }
    return result;
  }

  // ---------- 矩阵与向量乘法 ----------

  friend constexpr std::vector<T> operator*(const matrix &m, const std::vector<T> &v) {
    assert(m.cols_ == static_cast<int>(v.size()));
    std::vector<T> result(m.rows_);
    for (int i = 0; i < m.rows_; ++i) {
      for (int j = 0; j < m.cols_; ++j) {
        result[i] += m(i, j) * v[j];
      }
    }
    return result;
  }

  friend constexpr std::vector<T> operator*(const std::vector<T> &v, const matrix &m) {
    assert(static_cast<int>(v.size()) == m.rows_);
    std::vector<T> result(m.cols_);
    for (int i = 0; i < m.rows_; ++i) {
      for (int j = 0; j < m.cols_; ++j) {
        result[j] += v[i] * m(i, j);
      }
    }
    return result;
  }

  // ---------- 高斯消元 ----------

  // 选择主元：浮点类型选择绝对值最大者，其他类型选择第一个非零元素
  static int choose_pivot(const matrix &m, int h, int c) noexcept {
    if constexpr (std::is_floating_point_v<T>) {
      int piv = -1;
      for (int i = h; i < m.rows_; ++i) {
        if (m(i, c) != T(0) &&
            (piv == -1 || std::abs(m(i, c)) > std::abs(m(piv, c)))) {
          piv = i;
        }
      }
      return piv;
    } else {
      for (int i = h; i < m.rows_; ++i) {
        if (m(i, c) != T(0)) return i;
      }
      return -1;
    }
  }

  // Gauss-Jordan 消元，返回简化阶梯形矩阵。
  // 注意：消元过程中保留行列式符号（交换行并乘 -1）。
  matrix gauss_jordan() const {
    matrix mtr(*this);
    int c = 0;
    for (int h = 0; h < rows_; ++h) {
      if (c == cols_) break;
      int piv = choose_pivot(mtr, h, c);
      if (piv == -1) {
        ++c;
        --h; // 当前列无主元，继续下一列但保持 h 不变
        continue;
      }
      if (h != piv) {
        for (int w = 0; w < cols_; ++w) {
          std::swap(mtr(piv, w), mtr(h, w));
          mtr(piv, w) *= -identity_element(); // 保持行列式符号
        }
      }
      // 收集主元行从 c 开始的非零列，用于后续消元
      std::vector<int> nonzero_cols;
      for (int w = c; w < cols_; ++w) {
        if (mtr(h, w) != T(0)) nonzero_cols.push_back(w);
      }
      if (mtr(h, c) == T(0)) continue; // 理论上不会发生
      T inv_pivot = identity_element() / mtr(h, c);
      for (int hh = 0; hh < rows_; ++hh) {
        if (hh == h) continue;
        T coeff = mtr(hh, c) * inv_pivot;
        for (int w : nonzero_cols) {
          mtr(hh, w) -= mtr(h, w) * coeff;
        }
        mtr(hh, c) = T(0);
      }
      ++c;
    }
    return mtr;
  }

  // 计算上三角矩阵的行列式（对角线元素乘积），要求方阵
  constexpr T determinant_of_upper_triangle() const {
    assert(rows_ == cols_);
    T result = identity_element();
    for (int i = 0; i < rows_; ++i) result *= (*this)(i, i);
    return result;
  }

  // 在 gauss_jordan 结果上求秩：从后往前找第一个非零元素，其行号 + 1 即为秩
  int rank_of_gauss_jordan() const {
    for (int i = rows_ * cols_ - 1; i >= 0; --i) {
      if (data[i] != T(0)) return i / cols_ + 1;
    }
    return 0;
  }

  // 求矩阵的秩
  int rank() const {
    return gauss_jordan().rank_of_gauss_jordan();
  }

  // 求方阵的行列式
  T determinant() const {
    assert(rows_ == cols_);
    return gauss_jordan().determinant_of_upper_triangle();
  }

  // 就地求逆，返回矩阵的秩。
  // 若矩阵不可逆（秩 < 行数），则当前矩阵内容会被部分修改为消元结果。
  int inverse() {
    assert(rows_ == cols_);
    matrix aug = identity(rows_);
    matrix tmp = *this;
    int rank = 0;
    for (int i = 0; i < rows_; ++i) {
      int pivot = i;
      while (pivot < rows_ && tmp(pivot, i) == T(0)) ++pivot;
      if (pivot == rows_) continue;
      ++rank;
      // 交换 tmp 与 aug 的第 i 行和第 pivot 行
      for (int j = 0; j < cols_; ++j) {
        std::swap(tmp(i, j), tmp(pivot, j));
        std::swap(aug(i, j), aug(pivot, j));
      }
      T inv_pivot = identity_element() / tmp(i, i);
      for (int j = 0; j < cols_; ++j) {
        tmp(i, j) *= inv_pivot;
        aug(i, j) *= inv_pivot;
      }
      // 消去其他行主元列
      for (int h = 0; h < rows_; ++h) {
        if (h == i) continue;
        T coeff = tmp(h, i);
        for (int j = 0; j < cols_; ++j) {
          tmp(h, j) -= tmp(i, j) * coeff;
          aug(h, j) -= aug(i, j) * coeff;
        }
      }
    }
    *this = aug;
    return rank;
  }

  // ---------- 输入输出 ----------

  template <class OStream>
  friend OStream &operator<<(OStream &os, const matrix &x) {
    os << "matrix(" << x.rows_ << " x " << x.cols_ << ")\n";
    for (int i = 0; i < x.rows_; ++i) {
      for (int j = 0; j < x.cols_; ++j) {
        os << x(i, j) << (j + 1 == x.cols_ ? '\n' : ' ');
      }
    }
    return os;
  }

  template <class IStream>
  friend IStream &operator>>(IStream &is, matrix &x) {
    for (auto &v : x.data) is >> v;
    return is;
  }
};

void solve(){
  i64 n;
  int r;
  std::cin >> n >> r;

  matrix<Z> f(4, 4);
  for(int i = 0; i < 4; i++){
    f[i][i] += 1;
    f[i][(i + 1) % 4] += 1;
    f[i][(i + 3) % 4] += 1;
  }

  std::cout << f.power(n)[0][r] << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}