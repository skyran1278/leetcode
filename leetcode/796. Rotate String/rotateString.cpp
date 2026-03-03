#include <string>

using namespace std;

/**
 * @brief 11m 5s
 * @brief 8m 0s
 * O(n)
 * O(n)
 */
class Solution {
 public:
  // s = "abcde", goal = "cdeab"
  // s = "aa", goal = "aaa"
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
      return false;
    }

    return (s + s).find(goal) != std::string::npos;
  }
};
