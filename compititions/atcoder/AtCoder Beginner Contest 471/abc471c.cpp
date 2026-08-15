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

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  
  std::set<i64> set;
  for(int i = 0; i < n; i++){
    set.insert(a[i]);
  }

  i64 ans = 0, cur = 0;
  for(int i = 0; i < n; i++){
    auto it1 = set.lower_bound(cur);
    auto it2 = set.upper_bound(cur);
    i64 l = -inf2, r = -inf2;
    if(it1 != set.end()){
      r = *it1;
    }
    if(it2 != set.begin()){
      it2 = std::prev(it2);
      l = *it2;
    }

    if(l == -inf2){
      ans += r - cur;
      cur = r;
    }else if(r == -inf2){
      ans += cur - l;
      cur = l;
    }else{
      if(cur - l <= r - cur){
        ans += cur - l;
        cur = l;
      }else{
        ans += r - cur;
        cur = r;
      }
    }
    set.erase(cur);
  }

  std::cout << ans << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}