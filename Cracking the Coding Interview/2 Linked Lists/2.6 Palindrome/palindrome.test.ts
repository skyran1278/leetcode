import {
  Node,
  arrayToLinkedList,
  createLinkedList,
  reverseLinkedList,
} from '../linkedList';
import { isPalindrome } from './palindrome';

describe('isPalindrome', () => {
  it('should return true for a palindrome linked list', () => {
    // Create a palindrome linked list, e.g., 1 -> 2 -> 3 -> 2 -> 1
    const linkedList = arrayToLinkedList([1, 2, 3, 2, 1]);
    expect(isPalindrome(linkedList)).toBe(true);
  });

  it('should return true for a single-node linked list', () => {
    // A single-node list is a palindrome by definition
    const linkedList = new Node(1);
    expect(isPalindrome(linkedList)).toBe(true);
  });

  it('should return false for a non-palindrome linked list', () => {
    // Create a non-palindrome linked list, e.g., 1 -> 2 -> 3 -> 4 -> 5
    const linkedList = arrayToLinkedList([1, 2, 3, 4, 5]);
    expect(isPalindrome(linkedList)).toBe(false);
  });

  it('should handle large palindrome linked lists', () => {
    // Create a large palindrome linked list, e.g., 1 -> 2 -> ... -> 1000 -> ... -> 2 -> 1
    const linkedList = createLinkedList(1000);
    const reversedLinkedList = reverseLinkedList(createLinkedList(1000));
    let current = linkedList;
    while (current.next) {
      current = current.next;
    }
    current.next = reversedLinkedList;

    expect(isPalindrome(linkedList)).toBe(true);
  });
});
