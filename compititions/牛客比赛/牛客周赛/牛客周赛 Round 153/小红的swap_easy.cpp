#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::string s, t;
  std::cin >> s >> t;

  std::vector<int> pos0, pos1;
  for(int i = 0; i < n; i++){
    if(s[i] != t[i]){
      if(s[i] == '1'){
        pos1.push_back(i + 1);
      }else{
        pos0.push_back(i + 1);
      }
    }
  }

  if(pos0.size() == 0 && pos1.size() == 0){
    std::cout << "0\n";
    return;
  }

  std::cout << pos0.size() + pos1.size() + 1 << "\n";
  int first = pos0.back();
  while(pos0.size() || pos1.size()){
    std::cout << pos0.back() << "\n";
    pos0.pop_back();
    std::cout << pos1.back() << "\n";
    pos1.pop_back();
  }
  std::cout << first << "\n";
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