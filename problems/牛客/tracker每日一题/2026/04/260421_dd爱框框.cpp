#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, x;
  std::cin >> n >> x;

  std::vector<i64> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> pre(n);
  std::partial_sum(a.begin(), a.end(), pre.begin());

  int len = 1E9;
  int l = 0, r = n - 1;

  for(int i = 0; i < n; i++){
    int lo = i, hi = n - 1;
    while(lo < hi){
      int mid = (lo + hi) >> 1;
      i64 sum = pre[mid] - (i ? pre[i - 1] : 0);
      if(sum >= x){
        hi = mid;
      }else{
        lo = mid + 1;
      }
    }

    i64 sum = pre[lo] - (i ? pre[i - 1] : 0);
    if(sum >= x){
      if(lo - i + 1 < len){
        len = lo - i + 1;
        l = i;
        r = l + len - 1;
      }
    }
  }

  std::cout << l + 1 << " " << r + 1 << "\n";

  return 0;
}