// Remember, all submissions are being checked for plagiarism.
// Your recruiter will be informed in case suspicious activity is detected.

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cstdio>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int solution(vector<string>& R) {
  int N = static_cast<int>(R.size());
  int M = static_cast<int>(R[0].size());

  // Directions: 0=right, 1=down, 2=left, 3=up
  int dr[] = {0, 1, 0, -1};
  int dc[] = {1, 0, -1, 0};

  int row = 0, col = 0, dir = 0;

  set<tuple<int, int, int>> states;  // (row, col, dir) for cycle detection
  set<pair<int, int>> visited;       // unique squares visited

  visited.insert({row, col});

  while (true) {
    // Check if we've been in this exact state before
    auto state = make_tuple(row, col, dir);
    if (states.count(state)) {
      break;  // cycle detected
    }
    states.insert(state);

    // Try to move forward
    int nr = row + dr[dir];
    int nc = col + dc[dir];

    if (nr >= 0 && nr < N && nc >= 0 && nc < M &&
        R[static_cast<size_t>(nr)][static_cast<size_t>(nc)] == '.') {
      row = nr;
      col = nc;
      visited.insert({row, col});
    } else {
      // Rotate 90 degrees clockwise
      dir = (dir + 1) % 4;
    }
  }

  return static_cast<int>(visited.size());
}

int main() {
  vector<string> grid = {"...X..", "....XX", "..X..."};
  int result = solution(grid);
  printf("%d\n", result);

  return 0;
}
