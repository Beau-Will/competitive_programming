#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  std::vector<i64> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  int b = std::max<int>(1, std::sqrt(n));
  int siz = (n + b - 1) / b;
  std::vector<int> l(siz + 1), r(siz + 1), id(n + 1);
  for(int i = 1; i <= siz; i++){
    l[i] = (i - 1) * b + 1;
    r[i] = std::min(n, i * b);
    for(int j = l[i]; j <= r[i]; j++){
      id[j] = i;
    }
  }

  std::vector<i64> tag(siz + 1);
  std::vector<std::vector<i64>> ord(siz + 1);

  auto rebuild = [&](int x){
    ord[x].clear();
    ord[x].reserve(r[x] - l[x] + 1);
    for(int i = l[x]; i <= r[x]; i++){
      ord[x].push_back(a[i]);
    }
    std::sort(ord[x].begin(), ord[x].end());
  };

  for(int i = 1; i <= siz; i++){
    rebuild(i);
  }

  auto range_add = [&](int left, int right, i64 x){
    int bl = id[left], br = id[right];
    if(bl == br){
      for(int i = left; i <= right; i++){
        a[i] += x;
      }
      rebuild(bl);
      return;
    }

    for(int i = left; i <= r[bl]; i++){
      a[i] += x;
    }
    rebuild(bl);

    for(int i = l[br]; i <= right; i++){
      a[i] += x;
    }
    rebuild(br);

    for(int i = bl + 1; i <= br - 1; i++){
      tag[i] += x;
    }
  };

  auto count = [&](int left, int right, i64 x){
    i64 ans = 0;
    int bl = id[left], br = id[right];
    if(bl == br){
      for(int i = left; i <= right; i++){
        if(a[i] + tag[bl] < x){
          ans++;
        }
      }
      return ans;
    }

    for(int i = left ; i <= r[bl]; i++){
      if(a[i] + tag[bl] < x){
        ans++;
      }
    }
    for(int i = l[br]; i <= right; i++){
      if(a[i] + tag[br] < x){
        ans++;
      }
    }
    for(int i = bl + 1; i <= br - 1; i++){
      i64 t = x - tag[i];
      ans += std::lower_bound(ord[i].begin(), ord[i].end(), t) - ord[i].begin();
    }
    return ans;
  };

  for(int qi = 0; qi < q; qi++){
    int op, left, right, x;
    std::cin >> op >> left >> right >> x;

    if(op == 1){
      range_add(left, right, x);
    }else{
      std::cout << count(left, right, x) << "\n";
    }
  }

  return 0;
}