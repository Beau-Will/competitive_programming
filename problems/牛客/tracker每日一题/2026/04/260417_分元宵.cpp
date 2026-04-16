#include <iostream>
#include <string>
#include <algorithm>

using i64 = long long;
using i128 = __int128;

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

i128 toi128(const std::string& s) {
  i128 n = 0;
  for (auto c : s) {
    n = n * 10 + (c - '0');
  }
  return n;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string sa, sb, sc, sd, sp;
  std::cin >> sa >> sb >> sc >> sd >> sp;
  i128 a = toi128(sa), b = toi128(sb);
  i128 c = toi128(sc), d = toi128(sd);
  i128 p = toi128(sp);

  auto mul = [&](i128 x, i128 y){
    i128 res = 0;
    x %= p, y %= p;
    for(; y; x = (x + x) % p, y >>= 1){
      if(y & 1){
        res = (res + x) % p;
      }
    }
    return res;
  };

  auto power = [&](i128 x, i128 y){
    i128 res = 1 % p;
    for(; y; x = mul(x, x), y >>= 1){
      if(y & 1){
        res = mul(res, x);
      }
    }
    return res;
  };

  std::cout << power(mul(a, b), c * d) << "\n";

  return 0;
}