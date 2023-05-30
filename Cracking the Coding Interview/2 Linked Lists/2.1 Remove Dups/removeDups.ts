import { Node } from '../linkedList';

export const removeDups = (head: Node | null): void => {
  const set = new Set();
  let current = head;
  let previous = null;
  if (current == null) {
    return;
  }
  while (current != null) {
    if (!set.has(current.value)) {
      set.add(current.value);
      previous = current;
    } else {
      previous!.next = current.next;
    }
    current = current.next;
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
