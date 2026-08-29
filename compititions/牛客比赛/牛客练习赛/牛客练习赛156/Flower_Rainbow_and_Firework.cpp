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
  int n, d, k;
  std::cin >> n >> d >> k;

  std::vector<std::array<int, 2>> ans;
  int next = 1;

  if(d & 1){
    int r = (d - 1) / 2;
    int a = next++;
    int b = next++;
    ans.push_back({a, b});

    std::vector<int> cur {a, b};
    for(int dep = 0; dep < r; dep++){
      std::vector<int> ncur;
      for(const auto& u : cur){
        int c = k - 1;
        for(int j = 0; j < c && next <= n; j++){
          int v = next++;
          ans.push_back({u, v});
          ncur.push_back(v);
        }

        if(next > n){
          break;
        }
      }

      cur.swap(ncur);
      if(next > n){
        break;
      }
    }
  }else{
    int r = d / 2;
    int rt = next++;
    std::vector<int> cur {rt};

    for(int dep = 0; dep < r; dep++){
      std::vector<int> ncur;
      for(const auto& u : cur){
        int c = k;
        if(dep) c--;

        for(int j = 0; j < c && next <= n; j++){
          int v = next++;
          ans.push_back({u, v});
          ncur.push_back(v);
        }

        if(next > n){
          break;
        }
      }

      cur.swap(ncur);
      if(next > n){
        break;
      }
    }
  }

  if(next <= n){
    std::cout << "-1\n";
    return;
  }

  for(const auto& [u, v] : ans){
    std::cout << u << " " << v << "\n";
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}