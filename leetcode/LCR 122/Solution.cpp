#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 1 m 42 s
 * O(n)
 */
class Solution {
 public:
  string pathEncryption(string path) {
    string s;

    for (auto &&c : path) {
      if (c == '.') {
        s += ' ';
      } else {
        s += c;
      }
    }

    return s;
  }
};
