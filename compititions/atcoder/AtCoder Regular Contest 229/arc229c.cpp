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

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  for(int i = 0; i < n; i++) std::cin >> a[i];

  std::vector<i64> odd, even;
  for(int i = 0; i < n; i++){
    if(a[i] & 1){
      odd.push_back(a[i]);
    }else{
      even.push_back(a[i]);
    }
  }

  i64 sum = std::accumulate(a.begin(), a.end(), 0LL);

  std::sort(odd.begin(), odd.end(), std::greater());
  std::sort(even.begin(), even.end(), std::greater());

  int cnto = odd.size();
  int cnte = even.size();
  i64 N = n;

  auto get = [&](int s, int t){
    i64 cntx = (s == 1 ? cnto : cnte);
    i64 cnty = (s == 1 ? cnte : cnto);

    if(s == t){
      i64 t1 = 2 * cntx - 1;
      i64 t2 = 2 * cnty + 1;

      i64 max = std::min({N, t1, t2});
      if(!(max & 1)){
        max--;
      }
      return static_cast<int>(max);
    }else{
      i64 t1 = 2 * cntx;
      i64 t2 = 2 * cnty;

      i64 max = std::min({N, t1, t2});

      if(max & 1){
        max--;
      }
      return static_cast<int>(max);
    }
  };

  i64 res = -1;

  if(cnto >= 2){
    res = std::max(res, odd[0] + odd[1] + get(1, 1) - 1);
  }

  if(cnte >= 2){
    res = std::max(res, even[0] + even[1] + get(0, 0) - 1);
  }

  if(cnto >= 1 && cnte >= 1){
    res = std::max(res, odd[0] + even[0] + get(1, 0) - 1);
  }

  i64 ans = sum - res / 2;

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}