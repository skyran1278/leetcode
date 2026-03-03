#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief 28m 20s
 * @brief 21m 53s
 * O(n)
 */
class Solution {
 public:
  // s = "foo", t = "bar"
  // s = "bar", t = "foo"
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> stMap;
    unordered_map<char, char> tsMap;

    for (size_t i = 0; i < s.size(); i++) {
      char sChar = s[i];
      char tChar = t[i];

      if (stMap.count(sChar) > 0 && stMap[sChar] != tChar) {
        return false;
      }

      if (tsMap.count(tChar) > 0 && tsMap[tChar] != sChar) {
        return false;
      }

      // stMap = b: f
      // stMap = b: f, a: o
      stMap[sChar] = tChar;
      // tsMap = f: b
      // tsMap = f: b, o: a
      tsMap[tChar] = sChar;
    }

    return true;
  }
};

int main() {
  Solution s;
  s.isIsomorphic("egg", "add");
  s.isIsomorphic("paper", "title");
}
