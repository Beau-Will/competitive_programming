#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9 + 7, P2 = 998'244'353;
constexpr double eps = 1E-10;
// constexpr double pi = std::numbers::pi; // at least C++20
// constexpr double e = std::numbers::e; // at least C++20

void solve() {
  std::vector<std::string> s(3);
  for (int i = 0; i < 3; i++) {
    std::cin >> s[i];
  }

  for (int i = 0; i < 3; i++) {
    int cnt1 = 0, cnt3 = 0;
    int x = -1, y = -1;
    for (int j = 0; j < 3; j++) {
      if (s[i][j] == '1') cnt1++;
      else if (s[i][j] == '*') {
        cnt3++;
        x = i + 1, y = j + 1;
      }
    }

    if (cnt1 == 2 and cnt3 == 1) {
      std::cout << "Yes\n";
      std::cout << x << " " << y << "\n";
      return;
    }
  }

  for (int i = 0; i < 3; i++) {
    int cnt1 = 0, cnt3 = 0;
    int x = -1, y = -1;
    for (int j = 0; j < 3; j++) {
      if (s[j][i] == '1') cnt1++;
      else if (s[j][i] == '*') {
        cnt3++;
        x = j + 1, y = i + 1;
      }
    }

    if (cnt1 == 2 and cnt3 == 1) {
      std::cout << "Yes\n";
      std::cout << x << " " << y << "\n";
      return;
    }
  }

  int cnt1 = 0, cnt3 = 0;
  int x = -1, y = -1;
  if (s[0][0] == '1') cnt1++;
  else if (s[0][0] == '*') {
    cnt3++;
    x = 1, y = 1;
  }
  if (s[1][1] == '1') cnt1++;
  else if (s[1][1] == '*') {
    cnt3++;
    x = 2, y = 2;
  }
  if (s[2][2] == '1') cnt1++;
  else if (s[2][2] == '*') {
    cnt3++;
    x = 3, y = 3;
  }

  if (cnt1 == 2 and cnt3 == 1) {
    std::cout << "Yes\n";
    std::cout << x << " " << y << "\n";
    return;
  }

  cnt1 = 0, cnt3 = 0;
  x = -1, y = -1;
  if (s[0][2] == '1') cnt1++;
  else if (s[0][2] == '*') {
    cnt3++;
    x = 1, y = 3;
  }
  if (s[1][1] == '1') cnt1++;
  else if (s[1][1] == '*') {
    cnt3++;
    x = 2, y = 2;
  }
  if (s[2][0] == '1') cnt1++;
  else if (s[2][0] == '*') {
    cnt3++;
    x = 3, y = 1;
  }

  if (cnt1 == 2 and cnt3 == 1) {
    std::cout << "Yes\n";
    std::cout << x << " " << y << "\n";
    return;
  }

  std::cout << "No\n";
}

int main() {
  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // std::cin >> T; // multi cases

  for (int i = 1; i <= T; i++) solve();
}