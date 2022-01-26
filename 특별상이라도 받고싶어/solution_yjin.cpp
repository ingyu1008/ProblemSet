#include <iostream>
#include <algorithm>

int n;
int mat[2000][2000];
int f(int x, int y, int l) {
   if (l == 1) return mat[x][y];

   int a[4];
   a[0] = f(x, y, l / 2);
   a[1] = f(x + l / 2, y, l / 2);
   a[2] = f(x, y + l / 2, l / 2);
   a[3] = f(x + l / 2, y + l / 2, l / 2);
   std::sort(a, a + 4);
   return a[1];
}
int main() {
   std::cin >> n;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         std::cin >> mat[i][j];
      }
   }
   std::cout << f(0, 0, n) << "\n";
   return 0;
}