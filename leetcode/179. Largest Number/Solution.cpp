#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Compare {
  bool operator()(string a, string b) {
    string s1 = a + b;
    string s2 = b + a;
    return s1 < s2;
  }
};

/**
 * @brief 1 hrs 35 m 3 s
 * @brief 13 m 53 s
 * O(n log n)
 * O(n)
 */
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    priority_queue<string, vector<string>, Compare> heap;

    for (auto&& num : nums) {
      heap.push(to_string(num));
    }

    string result;
    while (!heap.empty()) {
      result += heap.top();
      heap.pop();
    }

    if (result[0] == '0') {
      return "0";
    }

    return result;
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
