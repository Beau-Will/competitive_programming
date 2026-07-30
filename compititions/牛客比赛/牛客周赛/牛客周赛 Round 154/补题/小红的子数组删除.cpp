#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/*
 * 对顶多重集合模板
 * 常用于解决区间求中位数的题目
 * 默认从小到大排序，左集合存较小的一半，右集合存较大的一半
 * 始终保持左集合大小 = (总元素数 + 1) / 2
**/

template <typename T, typename Compare = std::less<T>>
struct DualMultiset {
  std::multiset<T, Compare> L;
  std::multiset<T, Compare> R;
  Compare comp;

  // 平衡两个集合，保证 L.size() == (total + 1) / 2
  void balance() {
    std::size_t total = L.size() + R.size();
    while (L.size() > (total + 1) / 2) {
      auto it = std::prev(L.end());
      R.insert(*it);
      L.erase(it);
    }
    while (L.size() < (total + 1) / 2 && !R.empty()) {
      auto it = R.begin();
      L.insert(*it);
      R.erase(it);
    }
  }

  // 插入元素
  void insert(const T& x) {
    if (L.empty() || !comp(*std::prev(L.end()), x)) {
      L.insert(x);
    } else {
      R.insert(x);
    }
    balance();
  }

  // 删除一个元素，必须保证元素存在
  void erase(const T& x) {
    auto it = L.find(x);
    if (it != L.end()) {
      L.erase(it);
    } else {
      auto it2 = R.find(x);
      assert(it2 != R.end());
      R.erase(it2);
    }
    balance();
  }

  // 返回左中位数
  const T& median_left() const {
    assert(!L.empty());
    return *std::prev(L.end());
  }

  // 返回右中位数
  const T& median_right() const {
    assert(!R.empty());
    return *R.begin();
  }

  // 为兼容奇数场景保留 median() 接口，直接返回左中位数
  const T& median() const {
    return median_left();
  }

  // 总元素个数
  std::size_t size() const {
    return L.size() + R.size();
  }

  bool empty() const {
    return size() == 0;
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
    std::cout << (x == 0) << "\n";
    return;
  }

  DualMultiset<int> set;
  
  for(int i = k; i < n; i++){
    set.insert(a[i]);
  }
  
  int ans = 0;
  
  auto check = [&](){
    if(m & 1){
      ans += set.median() == x;
    }else{
      ans += (set.median_left() + set.median_right()) == 2 * x;
    }
  };
  
  check();
  for(int l = 0; l + k < n; l++){
    set.insert(a[l]);
    set.erase(a[l + k]);
    check();
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