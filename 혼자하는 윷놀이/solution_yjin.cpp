#include <iostream>
#include <string>

int p;
std::string s;
bool f[4];

bool win() {
   if (f[0] && f[2]) {         // 1
      if (p > 11) return 1;
   }
   else if (!f[0] && f[1]) {   // 2
      if (p > 16) return 1;
   }
   else if (f[0] && !f[2]) {   // 3
      if (p > 16) return 1;
   }
   else {                  // 4
      if (p > 20) return 1;
   }
   return 0;
}

int main() {
   int n = 10;
   for (int i = 0; i < n; ++i) {
      std::cin >> s;
      int cnt = 0;
      for (int j = 0; j < 4; ++j) {
         if (s[j] == '0') {
            ++cnt;
         }
      }

      if (cnt == 1) {
         p += 1;
      }
      else if (cnt == 2) {
         p += 2;
      }
      else if (cnt == 3) {
         p += 3;
      }
      else if (cnt == 4) {
         p += 4;
         ++n;
      }
      else {
         p += 5;
         ++n;
      }

      if (win()) {
         std::cout << "WIN\n";
         return 0;
      }

      if (p == 5) {            // 1, 3 vs 2, 4
         f[0] = 1;
      }
      else if (f[0] && p == 8) {   // 1 vs 3
         f[2] = 1;
      }
      else if (!f[0] && p == 10) {// 2 vs 4
         f[1] = 1;
      }
   }
   std::cout << "LOSE\n";
   return 0;
}