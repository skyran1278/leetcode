#include <algorithm>
#include <climits>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int>& A, int L, int R) {
  long long need = static_cast<long long>(R) - L + 1;
  size_t n = A.size();

  unordered_map<int, int> count;
  long long have = 0;
  int best = INT_MAX;

  size_t left = 0;
  for (size_t right = 0; right < n; right++) {
    if (A[right] >= L && A[right] <= R) {
      count[A[right]]++;
      if (count[A[right]] == 1) {
        have++;
      }
    }

    while (have == need) {
      best = min(best, static_cast<int>(right - left + 1));
      if (A[left] >= L && A[left] <= R) {
        count[A[left]]--;
        if (count[A[left]] == 0) {
          have--;
        }
      }
      left++;
    }
  }

  return best == INT_MAX ? -1 : best;
}

int main() {
  vector<int> A = {2, 1, 4, 3, 2, 1, 1, 4};
  int result = solution(A, 2, 4);
  printf("%d\n", result);

  return 0;
}
