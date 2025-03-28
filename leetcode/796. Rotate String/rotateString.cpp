#include <string>

using namespace std;

/**
 * @brief 11 m 5 s
 * O(n)
 */
class Solution {
 public:
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
      return false;
    }

    return (s + s).find(goal) != std::string::npos;
  }
};
