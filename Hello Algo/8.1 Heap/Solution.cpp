#include <algorithm>
#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct MinHeap {
  int* harr;
  int capacity, heap_size;
  MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
  }
  int extractMin();
  void deleteKey(int i);
  void insertKey(int k);
  int parent(int i);
  int left(int i);
  int right(int i);
  void MinHeapify(int i);
  void decreaseKey(int i, int new_val);
};

// Function to extract minimum value in heap and then to store
// next minimum value at first index.
int MinHeap::extractMin() {
  if (heap_size == 0) return -1;
  int smallest = harr[0];
  harr[0] = harr[heap_size - 1];
  heap_size--;
  MinHeapify(0);
  return smallest;
}

// Function to delete a key at ith index.
void MinHeap::deleteKey(int i) {
  if (i < 0 || i >= heap_size) return;
  decreaseKey(i, -__INT_MAX__ - 1);
  extractMin();
}

// Function to insert a value in Heap.

void MinHeap::insertKey(int k) {
  if (heap_size + 1 > capacity) return;
  decreaseKey(heap_size++, k);
}

// Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) {
  harr[i] = new_val;
  while (i != 0 && harr[parent(i)] > harr[i]) {
    swap(harr[i], harr[parent(i)]);
    i = parent(i);
  }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < heap_size && harr[l] < harr[i]) smallest = l;
  if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
  if (smallest != i) {
    swap(harr[i], harr[smallest]);
    MinHeapify(smallest);
  }
}

/* Get index of left child node */
int MinHeap::left(int i) { return 2 * i + 1; }

/* Get index of right child node */
int MinHeap::right(int i) { return 2 * i + 2; }

/* Get index of parent node */
int MinHeap::parent(int i) {
  return (i - 1) / 2;  // Integer division down
}
