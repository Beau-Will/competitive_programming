#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int X, Y, Z, N;
  std::cin >> X >> Y >> Z >> N;

  std::vector<std::string> a(Y, std::string(X, '.'));
  std::vector<std::string> b(Y, std::string(Z, '.'));
  std::vector<std::string> c(Z, std::string(X, '.'));
  for(int i = 0; i < N; i++){
    int x, y, z;
    std::cin >> x >> y >> z;

    a[Y - y][x - 1] = 'x';
    b[Y - y][z - 1] = 'x';
    c[z - 1][x - 1] = 'x';
  }

  for(int i = 0; i < Y; i++){
    std::cout << a[i] << " " << b[i] << "\n";
  }
  std::cout << "\n";

  for(int i = 0; i < Z; i++){
    std::cout << c[i] << "\n";
  }

  return 0;
}