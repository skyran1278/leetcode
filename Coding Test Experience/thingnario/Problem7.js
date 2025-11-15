// Problem 7 - Immutability
// Write some example(s) to explain the concept of immutability and what's the benefit of it, especially on performance

/**
 * Cheap comparison: reference equality
 * O(1) vs O(n)
 */
if (oldState === newState) {
  // nothing changed
}

/**
 * Memoization
 */
if (prevInput === nextInput) {
  return cachedResult; // fast shortcut
}

/**
 * Enables structural sharing
 */
const oldList = [1, 2, 3, 4];
const newList = [...oldList.slice(0, 2), 99, ...oldList.slice(3)];
