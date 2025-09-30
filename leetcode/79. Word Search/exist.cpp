#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 1 hrs 10 m 12 s
 * @brief 53 m 44 s
 * O(M * N * 3^L)
 * O(MN)
 */
class Solution {
 public:
  // board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
  // word = "SEE"
  bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> used(board.size(),
                              vector<bool>(board[0].size(), false));

    // --- Word reversal trick ---
    vector<int> counts(2, 0);
    for (size_t row = 0; row < board.size(); row++) {
      for (size_t col = 0; col < board[row].size(); col++) {
        if (board[row][col] == word[0]) {
          counts[0]++;
        } else if (board[row][col] == word[word.size() - 1]) {
          counts[1]++;
        }
      }
    }

    if (counts[0] > counts[1]) {
      reverse(word.begin(), word.end());
    }

    for (size_t row = 0; row < board.size(); row++) {
      for (size_t col = 0; col < board[row].size(); col++) {
        if (backtrack(board, used, row, col, word, 0)) {
          return true;
        }
      }
    }

    return false;
  }

  bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& used,
                 int row, int col, string& word, int idx) {
    if (idx == word.size()) {
      return true;
    }

    int m = board.size();
    int n = board[0].size();
    if (row >= m || row < 0 || col < 0 || col >= n || used[row][col] ||
        board[row][col] != word[idx]) {
      return false;
    }

    used[row][col] = true;

    static const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto&& [dr, dc] : directions) {
      if (backtrack(board, used, row + dr, col + dc, word, idx + 1)) {
        return true;
      }
    }

    used[row][col] = false;

    return false;
  }
};

int main() {
  Solution s;

  vector<vector<char>> board3 = {
      {'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
  string word3 = "AAB";
  s.exist(board3, word3);

  vector<vector<char>> board2 = {{'a', 'a'}};
  string word2 = "aaa";
  s.exist(board2, word2);

  vector<vector<char>> board1 = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word1 = "ABCCED";
  s.exist(board1, word1);
}
