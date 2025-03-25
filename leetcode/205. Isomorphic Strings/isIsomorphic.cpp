#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief 28 m 20 s
 * O(n)
 */
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> stMapping;
    unordered_map<char, char> tsMapping;

    for (size_t i = 0; i < s.size(); i++) {
      char sChar = s[i];
      char tChar = t[i];

      if (stMapping.count(sChar) > 0 && stMapping[sChar] != tChar) {
        return false;
      }

      if (tsMapping.count(tChar) > 0 && tsMapping[tChar] != sChar) {
        return false;
      }

      stMapping[sChar] = tChar;
      tsMapping[tChar] = sChar;
    }

    return true;
  }
};

int main() {
  Solution s;
  s.isIsomorphic("egg", "add");
  s.isIsomorphic("paper", "title");
}
