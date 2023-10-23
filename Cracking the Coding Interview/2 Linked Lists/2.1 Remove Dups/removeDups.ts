import { Node } from '../linkedList';

export const removeDups = (head: Node | null): void => {
  const set = new Set();
  let runner = head;
  if (runner == null) {
    return;
  }
  let removeRunner: Node | null = null;
  while (runner != null) {
    if (!set.has(runner.value)) {
      set.add(runner.value);
      removeRunner = runner;
    } else {
      if (removeRunner != null) removeRunner.next = runner.next;
    }
    runner = runner.next;
  }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the length of the linked list

export const removeDupsNoBuffer = (head: Node | null): void => {
  let current = head;

  while (current != null) {
    let runner = current;
    while (runner.next != null) {
      if (runner.next.value === current.value) {
        runner.next = runner.next.next;
      } else {
        runner = runner.next;
      }
    }
    current = current.next;
  }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
// where n is the length of the linked list
