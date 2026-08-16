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
  int add = 0;
  void apply(const Tag& t)& {
    add = (add + t.add) % 3;
  }
};

using Node = std::array<int, 3>;

struct Info {
  int left, right;
  Node cnt{};

  Info(int color = -1): left(color), right(color){
    cnt.fill(0);
    if(color >= 0 && color < 3){
      cnt[color] = 1;
    }
  }
  void apply(const Tag& t)& {
    if(t.add == 0 || left == -1){
      return;
    }

    Node ncnt{};
    for(int i = 0; i < 3; i++){
      ncnt[(i + t.add) % 3] = cnt[i];
    }
    cnt = ncnt;
    left = (left + t.add) % 3;
    right = (right + t.add) % 3;
  }
};

Info operator+(const Info& a, const Info& b) {
  if(a.left == -1) return b;
  if(b.left == -1) return a;

  Info c;
  c.left = a.left;
  c.right = b.right;

  for(int i = 0; i < 3; i++){
    c.cnt[i] = a.cnt[i] + b.cnt[i];
  }

  if(a.right == b.left){
    c.cnt[a.right]--;
  }

  return c;
}

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::string s;
  std::cin >> s;
  s = " " + s;

  std::vector<Info> init(n + 1);
  for(int i = 1; i <= n; i++){
    init[i] = Info(s[i] - 'A');
  }

  LazySegmentTree<Info, Tag> lsgt(init);

  for(int i = 0; i < q; i++){
    int op;
    std::cin >> op;

    if(op == 1){
      int l, r;
      std::cin >> l >> r;

      lsgt.rangeApply(l, r, Tag{1});
    }else{
      std::cout << lsgt.rangeQuery(1, n).cnt[0] << "\n";
    }
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}