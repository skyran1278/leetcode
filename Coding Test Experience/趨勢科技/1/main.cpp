#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int solution(int N, vector<int>& A, vector<int>& B) {
  auto n = static_cast<size_t>(N);
  size_t M = A.size();

  // Build adjacency list and compute degrees
  vector<int> degree(n, 0);
  for (size_t i = 0; i < M; i++) {
    degree[static_cast<size_t>(A[i])]++;
    degree[static_cast<size_t>(B[i])]++;
  }

  vector<bool> removed(n, false);

  // Queue holds vertices to remove in the current round
  queue<size_t> current;
  for (size_t i = 0; i < n; i++) {
    if (degree[i] <= 1) {
      current.push(i);
    }
  }

  if (current.empty()) return 0;

  int seconds = 0;

  // Build adjacency list for neighbor traversal
  vector<vector<size_t>> adj(n);
  for (size_t i = 0; i < M; i++) {
    auto a = static_cast<size_t>(A[i]);
    auto b = static_cast<size_t>(B[i]);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  while (!current.empty()) {
    seconds++;
    vector<size_t> batch;
    auto sz = current.size();
    while (sz--) {
      size_t v = current.front();
      current.pop();
      if (removed[v]) continue;
      removed[v] = true;
      batch.push_back(v);
    }
    for (size_t v : batch) {
      for (size_t u : adj[v]) {
        if (!removed[u] && --degree[u] <= 1) {
          current.push(u);
        }
      }
    }
  }

  return seconds;
}

int main() {
  int N = 5;
  vector<int> A = {0, 1, 2, 3};
  vector<int> B = {1, 2, 3, 4};

  int result = solution(N, A, B);
  printf("%d\n", result);  // Expected output: 2

  return 0;
}
