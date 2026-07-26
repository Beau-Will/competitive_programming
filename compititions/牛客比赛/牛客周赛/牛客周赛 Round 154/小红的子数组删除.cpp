#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

struct Node {
  int val;
  int prio;
  int sz;
  Node* l, *r;
  Node(int v) : val(v), prio(rand()), sz(1), l(nullptr), r(nullptr) {}
};

inline int getSz(Node* t) {
  return t ? t->sz : 0;
}

inline void update(Node* t) {
  if (t) t->sz = 1 + getSz(t->l) + getSz(t->r);
}

Node* rotateRight(Node* t) {
  Node* newRoot = t->l;
  t->l = newRoot->r;
  newRoot->r = t;
  update(t);
  update(newRoot);
  return newRoot;
}

Node* rotateLeft(Node* t) {
  Node* newRoot = t->r;
  t->r = newRoot->l;
  newRoot->l = t;
  update(t);
  update(newRoot);
  return newRoot;
}

Node* insert(Node* t, int val) {
  if (!t) return new Node(val);
  if (val < t->val) {
    t->l = insert(t->l, val);
    if (t->l->prio < t->prio) t = rotateRight(t);
  } else {

    t->r = insert(t->r, val);
    if (t->r->prio < t->prio) t = rotateLeft(t);
  }
  update(t);
  return t;
}

Node* erase(Node* t, int val) {
  if (!t) return nullptr;
  if (val < t->val) {
    t->l = erase(t->l, val);
  } else if (val > t->val) {
    t->r = erase(t->r, val);
  } else {

    if (!t->l && !t->r) {
      delete t;
      return nullptr;
    }

    if (!t->l || (t->r && t->r->prio < t->l->prio)) {
      t = rotateLeft(t);
      t->l = erase(t->l, val);
    } else {
      t = rotateRight(t);
      t->r = erase(t->r, val);
    }
  }
  update(t);
  return t;
}

int kth(Node* t, int k) {
  int leftSz = getSz(t->l);
  if (k <= leftSz) return kth(t->l, k);
  if (k == leftSz + 1) return t->val;
  return kth(t->r, k - leftSz - 1);
}

void clear(Node* t) {
  if (!t) return;
  clear(t->l);
  clear(t->r);
  delete t;
}

struct Treap {
  Node* root = nullptr;

  void insert(int val) {
    root = ::insert(root, val);
  }
  void erase(int val)  {
    root = ::erase(root, val);
  }
  int kth(int k)       {
    return ::kth(root, k);
  }
  int size()           {
    return getSz(root);
  }

  ~Treap() {
    clear(root);
  }
};

void solve(){
  int n, k, x;
  std::cin >> n >> k >> x;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  int m = n - k;

  if(m == 0){
    std::cout << "0\n";
    return;
  }

  Treap tr;
  for(int i = k; i < n; i++){
    tr.insert(a[i]);
  }

  auto check = [&](){
    if(m & 1){
      int mid = tr.kth((m + 1) / 2);
      return mid == x;
    }else{
      int lmid = tr.kth(m / 2);
      int rmid = tr.kth(m / 2 + 1);
      return 1LL * lmid + rmid == 2LL * x;
    }
  };

  i64 ans = 0;

  if(check()){
    ans++;
  }

  for(int l = 0; l < n - k; l++){
    tr.insert(a[l]);
    tr.erase(a[l + k]);

    if(check()){
      ans++;
    }
  }

  std::cout << ans << "\n";
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