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

std::ostream& operator<<(std::ostream& os, i128 n) {
  if (n == 0) {
    return os << 0;
  }
  std::string s;
  while (n > 0) {
    s += char('0' + n % 10);
    n /= 10;
  }
  std::reverse(s.begin(), s.end());
  return os << s;
}

void solve(){
  int n;
  char c0;
  std::cin >> n >> c0;

  std::vector<char> c(n);
  for (auto& ci : c) std::cin >> ci;

  auto work = [&]() {

  };

  char left_front = c0, left_back = c0;
  char right_front = c0, right_back = c0;
  i128 cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt = 2 * cnt + (left_back == c[i]) + (c[i] == right_front);

    left_back = right_back;
    right_front = left_back;
    right_back = left_front;
  }

  std::cout << cnt << "\n";
}

int main(){
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++) solve();
}