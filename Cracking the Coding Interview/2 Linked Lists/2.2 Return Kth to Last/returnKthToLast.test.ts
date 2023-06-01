import { arrayToLinkedList } from '../linkedList';
import { returnKthToLast, returnKthToLast2 } from './returnKthToLast';

describe('returnKthToLast', () => {
  it('returns the kth to last element correctly when the list is not empty', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const k = 2;
    const expectedOutput = 4;

    expect(returnKthToLast(head, k)?.value).toBe(expectedOutput);
  });

  it('returns null when the list is empty', () => {
    const head = null;
    const k = 2;

    expect(returnKthToLast(head, k)).toBeNull();
  });

  it('returns null when k is greater than the length of the list', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 4;

    expect(returnKthToLast(head, k)).toBeNull();
  });

  it('returns the head node when k is equal to the length of the list', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 3;
    const expectedOutput = 1;

    expect(returnKthToLast(head, k)?.value).toBe(expectedOutput);
  });

  it('returns the last node when k is 1', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 1;
    const expectedOutput = 3;

    expect(returnKthToLast(head, k)?.value).toBe(expectedOutput);
  });

  it('returns null when k is 0', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 0;

    expect(returnKthToLast(head, k)).toBeNull();
  });

  it('returns null when k is negative', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = -2;

    expect(returnKthToLast(head, k)).toBeNull();
  });
});

describe('returnKthToLast2', () => {
  it('returns the kth to last element correctly when the list is not empty', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const k = 2;
    const expectedOutput = 4;

    expect(returnKthToLast2(head, k)?.value).toBe(expectedOutput);
  });

  it('returns null when the list is empty', () => {
    const head = null;
    const k = 2;

    expect(returnKthToLast2(head, k)).toBeNull();
  });

  it('returns null when k is greater than the length of the list', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 4;

    expect(returnKthToLast2(head, k)).toBeNull();
  });

  it('returns the head node when k is equal to the length of the list', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 3;
    const expectedOutput = 1;

    expect(returnKthToLast2(head, k)?.value).toBe(expectedOutput);
  });

  it('returns the last node when k is 1', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 1;
    const expectedOutput = 3;

    expect(returnKthToLast2(head, k)?.value).toBe(expectedOutput);
  });

  it('returns null when k is 0', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = 0;

    expect(returnKthToLast2(head, k)).toBeNull();
  });

  it('returns null when k is negative', () => {
    // Create a linked list: 1 -> 2 -> 3
    const head = arrayToLinkedList([1, 2, 3]);
    const k = -2;

    expect(returnKthToLast2(head, k)).toBeNull();
  });
});

describe('returnKthToLast performance', () => {
  it('performs at O(n) time and O(1) space', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const k = 2;

    const start = process.hrtime();
    returnKthToLast(head, k);
    const end = process.hrtime(start);
    const time = end[0] * 1000 + end[1] / 1000000;

    expect(time).toBeLessThan(0.01);
  });

  it('performs at O(n) time and O(n) space', () => {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    const k = 2;

    const start = process.hrtime();
    returnKthToLast2(head, k);
    const end = process.hrtime(start);
    const time = end[0] * 1000 + end[1] / 1000000;

    expect(time).toBeLessThan(0.01);
  });
});
