#include <bitset>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

void e(int n) {
  if (n > 0) {
    e(--n);
    cout << n << ' ';
    e(--n);
  }
}

int main() {
  int n = 3;
  e(n);
}
