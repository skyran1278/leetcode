#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief 12m 7s (recall)
 * O(mn)
 * O(m, n)
 */
class Solution {
 public:
  int minTotalDistance(vector<vector<int>>& grid) {
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    vector<int> rows{};
    vector<int> cols{};

    for (int row = 0; row < m; ++row) {
      for (int col = 0; col < n; ++col) {
        if (grid[row][col]) {
          rows.push_back(row);
        }
      }
    }

    for (int col = 0; col < n; ++col) {
      for (int row = 0; row < m; ++row) {
        if (grid[row][col]) {
          cols.push_back(col);
        }
      }
    }

    return distance(rows) + distance(cols);
  }

  int distance(const vector<int>& values) {
    int result = 0;
    int low = 0;
    int high = static_cast<int>(values.size()) - 1;
    while (low < high) {
      result += values[high--] - values[low++];
    }

    return result;
  }
};

// ── helpers ──────────────────────────────────────────────────────────────────

void run(const std::string& name, std::vector<std::vector<int>> grid,
         int expected) {
  Solution sol;
  int result = sol.minTotalDistance(grid);
  bool ok = (result == expected);
  std::cout << (ok ? "[PASS]" : "[FAIL]") << " " << name << "  got=" << result
            << "  expected=" << expected << "\n";
  assert(ok);
}

// ── test cases
// ────────────────────────────────────────────────────────────────

int main() {
  // Example 1: 題目原例，答案 6
  run("Example1 (3x5, answer=6)",
      {{1, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}}, 6);

  // 只有一個人，距離為 0
  run("Single person", {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 0);

  // 兩人在同一列相鄰，距離 1
  run("Two adjacent in row", {{1, 1}}, 1);

  // 兩人在同一行相鄰，距離 1
  run("Two adjacent in col", {{1}, {1}}, 1);

  // 兩人在對角，manhattan = 2
  run("Diagonal 2x2", {{1, 0}, {0, 1}}, 2);

  // 3x3 四角都有人，中心 (1,1) 是最佳點，每人距離 2，共 8
  run("Four corners 3x3", {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}, 8);

  // 1x5 一排，端點各一，最佳點中間，距離 2+2=4
  run("1x5 both ends", {{1, 0, 0, 0, 1}}, 4);

  // 所有人在同一格，距離 0
  run("All same cell", {{0, 0}, {0, 1}}, 0);

  // 大一點的 case，手動驗算
  // grid 5x5，(0,0) (0,4) (4,0) (4,4) 四角
  // rows: [0,0,4,4] → median 在 0 和 4 之間 → dist=(4-0)+(4-0)=8
  // cols: [0,4,0,4] → dist=(4-0)+(4-0)=8 → total=16
  run("Four corners 5x5",
      {{1, 0, 0, 0, 1},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0},
       {1, 0, 0, 0, 1}},
      16);

  std::cout << "\nAll tests passed!\n";
  return 0;
}
