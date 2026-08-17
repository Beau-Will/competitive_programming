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

std::vector<std::string> split(const std::string& s, char c) {
   std::vector<std::string> res;
   std::istringstream is(s);
   std::string t;
   while (std::getline(is, t, c)) {
       res.push_back(t);
   }
   return res;
}

void solve(){
  std::string s;
  std::cin >> s;

  auto res = split(s, ',');
  std::map<std::string, int> cnt;
  for(const auto& si : res){
    auto t = split(si, ':');
    cnt[t.front()] += std::stoi(t.back());
  }

  std::cout << cnt.size() << "\n";
  std::cout << std::max_element(cnt.begin(), cnt.end(), [](const auto& t1, const auto& t2){
    return t1.second < t2.second;
  }) -> first << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}