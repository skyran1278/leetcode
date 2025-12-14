#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 13 m 34 s
 * O(n log n)
 * O(n)
 */
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> numStrings;
    for (auto&& num : nums) {
      numStrings.push_back(to_string(num));
    }
    sort(numStrings.begin(), numStrings.end(),
         [](string a, string b) { return a + b > b + a; });

    if (numStrings[0] == "0") return "0";

    string largestNumber;
    for (auto&& num : numStrings) {
      largestNumber += num;
    }

    return largestNumber;
  }
};

int main() {
  Solution s;

  vector<int> s3 = {34323, 3432};
  s.largestNumber(s3);

  vector<int> s2 = {3, 30, 34, 5, 9};
  s.largestNumber(s2);

  vector<int> s1 = {432, 43243};
  s.largestNumber(s1);
}
