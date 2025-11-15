import assert from 'assert';

// Problem 2 - Find second largest within O(n) complexity.
function findSecondLargest(sequence) {
  let largest = -Infinity;
  let second = -Infinity;

  for (const num of sequence) {
    if (num > largest) {
      // shift largest down to second
      second = largest;
      largest = num;
    } else if (num < largest && num > second) {
      // distinct smaller number becomes second largest
      second = num;
    }
  }

  return second;
}

assert.equal(findSecondLargest([3, 3, 2, 1]), 2);
assert.equal(findSecondLargest([3, 3, 4, 2, 1]), 3);

/**
 * can use heap to solve this problem as well
 */
function findSecondLargest2(sequence) {
  const heap = new MinHeap();

  for (const num of sequence) {
    // keep only distinct values in the heap (size is at most 2, so this is cheap)
    if (heap.data.includes(num)) continue;

    heap.push(num);

    // keep only the two largest values
    if (heap.size() > 2) {
      heap.pop(); // remove the smallest of the three
    }
  }

  // after processing, heap has the 2 largest distinct values:
  // root (min) = second largest, other = largest
  return heap.peek();
}
