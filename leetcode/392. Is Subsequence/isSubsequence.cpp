#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * @brief 33 m 8 s
 * O(n)
 */
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    size_t i = 0;
    size_t j = 0;
    while (i < s.length() && j < t.length()) {
      char sChar = s[i];
      char tChar = t[j];

      if (sChar == tChar) {
        i++;
      }
      j++;
    }

    return i == s.length();
  }
};

/**
 * @brief 我目前仍寫不出來動態規劃的程式，這是看官方解答的
 */
class Solution2 {
 public:
  bool isSubsequence(string s, string t) {
    int n = s.size(), m = t.size();

    vector<vector<int> > f(m + 1, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
      f[m][i] = m;
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        if (t[i] == j + 'a')
          f[i][j] = i;
        else
          f[i][j] = f[i + 1][j];
      }
    }
    int add = 0;
    for (int i = 0; i < n; i++) {
      if (f[add][s[i] - 'a'] == m) {
        return false;
      }
      add = f[add][s[i] - 'a'] + 1;
    }
    return true;
  }
};

int main() {
  Solution2 s;
  bool s1 = s.isSubsequence("abc", "ahbgdc");
  bool s2 = s.isSubsequence("axc", "ahbgdc");

  cout << s1 << std::endl;
}
