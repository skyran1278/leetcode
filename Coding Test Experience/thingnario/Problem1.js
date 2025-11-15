import assert from 'assert';

// Problem 1 - Bubble sort
function bubbleSort(sequence) {
  const arr = [...sequence]; // avoid mutating the original array
  const n = arr.length;

  for (let i = 0; i < n - 1; i++) {
    let swapped = false;

    for (let j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        // swap
        const temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }

    // if no swaps happened, array is already sorted
    if (!swapped) break;
  }

  return arr;
}

assert.deepEqual(bubbleSort([5, 1, 3, 2, 4]), [1, 2, 3, 4, 5]);
