#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr double eps = 1E-10;
constexpr double pi = std::numbers::pi;
constexpr double e = std::numbers::e;

using Matrix = std::vector<std::vector<i64>>;

Matrix mul(const Matrix& a, const Matrix& b, int mod){
  Matrix res(a.size(), std::vector<i64>(b[0].size()));

  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < a[0].size(); j++){
      for(int k = 0; k < b[0].size(); k++){
        res[i][k] = (res[i][k] + a[i][j] * b[j][k]) % mod;
      }
    }
  }

  return res;
}

Matrix power(Matrix a, i64 b, int mod){
  Matrix res(a.size(), std::vector<i64>(a.size()));
  for(int i = 0; i < a.size(); i++){
    res[i][i] = 1 % mod;
  }

  for(; b; a = mul(a, a, mod), b >>= 1){
    if(b & 1){
      res = mul(res, a, mod);
    }
  }

  return res;
}

void solve(){
  int k;
  std::cin >> k;
  
  std::vector<i64> d(k + 1), tag(k + 1);
  std::string s;
  for(int i = 0; i < k; i++){
    tag[i] = 1;
    std::cin >> s;
    for(int j = 0; j < s.size(); j++){
      if(s[j] == 'a'){
        d[i] += tag[i];
      }else{
        tag[i] *= -1;
      }
    }
  }

  i64 n;
  std::cin >> n >> s;
  n--;
  int m = s.size();

  for(int i = 0; i < k; i++){
    d[i] = (d[i] % m + m) % m;
  }
  tag[k] = 1;
  for(int i = 0; i < k; i++){
    tag[k] *= tag[i];
  }

  std::vector<i64> cur(k + 1);
  Matrix a(k + 1, std::vector<i64>(k + 1));
  for(int i = 0; i < k; i++){
    for(int j = 0; j < k; j++){
      cur[j] = 0;
    }
    cur[i] = 1;
    for(int t = 0; t < k + 1; t++){
      int x = 1, c = 0;
      for(int j = k - 1; j >= 0; j--){
        c = (c + x * cur[j] % m + m) % m;
        x *= tag[(t + j) % (k + 1)];
      }
      for(int j = 1; j < k; j++){
        cur[j - 1] = cur[j];
      }
      cur[k - 1] = c;
    }
    for(int j = 0; j < k; j++){
      a[i][j] = cur[j];
    }
  }

  a = power(a, n / (k + 1), m);
  for(int i = 0; i < k; i++){
    cur[i] = 0;
  }
  for(int i = 0; i < k; i++){
    for(int j = 0; j < k; j++){
      cur[j] = (cur[j] + d[i] * a[i][j]) % m;
    }
  }
  n %= (k + 1);

  std::string ans;
  if(n < k){
    for(int i = 0; i < m; i++){
      ans.push_back(s[(i + cur[n]) % m]);
    }
    if(tag[n] == 1){
      for(int i = 0; i < m; i++){
        std::cout << ans[i];
      }
    }else{
      for(int i = m - 1; i >= 0; i--){
        std::cout << ans[i];
      }
    }
  }else{
    int x = 1, c = 0;
    for(int j = k - 1; j >= 0; j--){
      c = (c + x * cur[j] % m + m) % m;
      x *= tag[j];
    }
    for(int i = 0; i < m; i++){
      ans.push_back(s[(i + c) % m]);
    }
    if(x == 1){
      for(int i = 0; i < m; i++){
        std::cout << ans[i];
      }
    }else{
      for(int i = m - 1; i >= 0; i--){
        std::cout << ans[i];
      }
    }
  }
  std::cout << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int i = 1; i <= T; i++){
    solve();
  }

  return 0;
}