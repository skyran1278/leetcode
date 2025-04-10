#include <vector>

using namespace std;

/**
 * @brief 1 hrs 10 m 12 s
 * O(M * N * 3^L)
 */
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int rowSize = board.size();
    int colSize = board[0].size();
    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        if (board[row][col] == word[0]) {
          vector<vector<bool>> used(rowSize, vector<bool>(colSize, false));
          if (dfs(word, 0, board, used, row, col)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool dfs(string& word, int wordIndex, vector<vector<char>>& board,
           vector<vector<bool>>& used, int row, int col) {
    if (wordIndex == word.length()) {
      return true;
    }

    int rowSize = board.size();
    int colSize = board[0].size();
    if (row >= rowSize || row < 0 || col < 0 || col >= colSize ||
        used[row][col] || board[row][col] != word[wordIndex]) {
      return false;
    }

    used[row][col] = true;

    static const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto&& [dr, dc] : directions) {
      int i = row + dr;
      int j = col + dc;
      if (dfs(word, wordIndex + 1, board, used, i, j)) {
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
