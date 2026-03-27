#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> minp, primes;

void sieve(int n){
  minp.assign(n + 1, 0);
  primes.clear();

  for(int i = 2; i <= n; i++){
    if(!minp[i]){
      minp[i] = i;
      primes.push_back(i);
    }

    for(const auto& p : primes){
      if(p * i > n){
        break;
      }
      minp[p * i] = p;
      if(p == minp[i]){
        break;
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  sieve(n);

  std::cout << std::accumulate(minp.begin(), minp.end(), 0LL) << "\n";

  return 0;
}