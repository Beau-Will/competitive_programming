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

struct Trie{
  std::vector<std::array<int, 2>> next;
  std::vector<int> pass, cnt;
  int siz, ans;

  Trie(): siz(0), ans(0){
    next.push_back({0, 0});
    pass.push_back(0);
    cnt.push_back(0);
  }

  int new_node(){
    next.push_back({0, 0});
    pass.push_back(0);
    cnt.push_back(0);
    return ++siz;
  }

  void insert(const std::string& s){
    int ptr = 0;
    for(int i = 0; i < s.size(); i++){
      int c = s[i] ^ 48;
      if(!next[ptr][c]){
        next[ptr][c] = new_node();
      }
      ptr = next[ptr][c];
      if(pass[ptr] == 0) ans++;
      pass[ptr]++;
    }
    cnt[ptr]++;
  }

  void erase(const std::string& s){
    int ptr = 0;
    for(int i = 0; i < s.size(); i++){
      int c = s[i] ^ 48;
      ptr = next[ptr][c];
      pass[ptr]--;
      if(pass[ptr] == 0) ans--;
    }
    cnt[ptr]--;
  }
};

void solve(){
  int q;
  std::cin >> q;

  Trie trie;
  for(int i = 0; i < q; i++){
    std::string op, s;
    std::cin >> op >> s;

    if(op == "+"){
      trie.insert(s);
    }else{
      trie.erase(s);
    }

    std::cout << trie.ans << "\n";
  }
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}