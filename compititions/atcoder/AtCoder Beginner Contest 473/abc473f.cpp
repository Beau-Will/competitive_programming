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
    return rangeQuery(p * 2, l, m, x, y) + rangeQuery(p * 2 + 1, m + 1, r, x, y);
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
  int add = 0;
  void apply(const Tag& t)& {
    add += t.add;
  }
};

struct Info {
  int d = inf;
  void apply(const Tag& t)& {
    d += t.add;
  }
};

Info operator+(const Info& a, const Info& b) {
  return {std::min(a.d, b.d)};
}

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;
  s = " " + s;

  std::vector<Info> init(n + 1);
  init[0].d = 0;
  for(int i = 1; i <= n; i++){
    init[i].d = init[i - 1].d + (s[i] == 'A' ? 1 : -1);
  }

  LazySegmentTree<Info, Tag> seg(init);

  int q;
  std::cin >> q;

  for(int i = 0; i < q; i++){
    int op;
    std::cin >> op;

    if(op == 1){
      int i;
      char c;
      std::cin >> i >> c;

      if(s[i] != c){
        seg.rangeApply(i, n, {c == 'A' ? 2 : -2});
        s[i] = c;
      }
    }else{
      int l, r;
      std::cin >> l >> r;

      int left = l == 1 ? 0 : seg.rangeQuery(l - 1, l - 1).d;
      int d = seg.rangeQuery(l, r).d;

      std::cout << (d >= left ? "Yes\n" : "No\n");
    }
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}