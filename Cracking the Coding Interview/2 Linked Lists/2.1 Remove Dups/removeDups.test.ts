import {
  Node,
  arrayToLinkedList,
  createLinkedList,
  linkedListToArray,
} from '../linkedList';
import { removeDups, removeDupsNoBuffer } from './removeDups';

describe('removeDups', () => {
  it('should remove duplicates from an unsorted linked list', () => {
    const head = arrayToLinkedList([1, 3, 2, 1, 4, 2, 5]);
    removeDups(head);
    expect(linkedListToArray(head)).toEqual([1, 3, 2, 4, 5]);
  });

  it('should handle an empty linked list', () => {
    const head = null;
    removeDups(head);
    expect(head).toBeNull();
  });

  it('should handle a linked list with a single node', () => {
    const head = new Node(1);
    removeDups(head);
    expect(linkedListToArray(head)).toEqual([1]);
  });

  it('should not modify a linked list with no duplicates', () => {
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    removeDups(head);
    expect(linkedListToArray(head)).toEqual([1, 2, 3, 4, 5]);
  });

  it('should remove all duplicates in a linked list', () => {
    const head = arrayToLinkedList([1, 1, 1, 1, 1]);
    removeDups(head);
    expect(linkedListToArray(head)).toEqual([1]);
  });
});

describe('removeDupsNoBuffer', () => {
  it('should remove duplicates from an unsorted linked list', () => {
    const head = arrayToLinkedList([1, 3, 2, 1, 4, 2, 5]);
    removeDupsNoBuffer(head);
    expect(linkedListToArray(head)).toEqual([1, 3, 2, 4, 5]);
  });

  it('should handle an empty linked list', () => {
    const head = null;
    removeDupsNoBuffer(head);
    expect(head).toBeNull();
  });

  it('should handle a linked list with a single node', () => {
    const head = new Node(1);
    removeDupsNoBuffer(head);
    expect(linkedListToArray(head)).toEqual([1]);
  });

  it('should not modify a linked list with no duplicates', () => {
    const head = arrayToLinkedList([1, 2, 3, 4, 5]);
    removeDupsNoBuffer(head);
    expect(linkedListToArray(head)).toEqual([1, 2, 3, 4, 5]);
  });

  it('should remove all duplicates in a linked list', () => {
    const head = arrayToLinkedList([1, 1, 1, 1, 1]);
    removeDupsNoBuffer(head);
    expect(linkedListToArray(head)).toEqual([1]);
  });
});

describe('removeDups performance', () => {
  it('should have acceptable performance for removeDups', () => {
    const length = 10000; // Define the length of the linked list for performance testing
    const head = createLinkedList(length);

    // Measure the execution time of removeDups
    const startTime = process.hrtime();
    removeDups(head);
    const endTime = process.hrtime(startTime);
    const executionTime = endTime[0] * 1000 + endTime[1] / 1000000; // Convert to milliseconds

    // Adjust the acceptable execution time according to your requirements
    const acceptableExecutionTime = 10; // Specify the acceptable execution time in milliseconds

    expect(executionTime).toBeLessThanOrEqual(acceptableExecutionTime);
  });

  it('should have acceptable performance for removeDupsNoBuffer', () => {
    const length = 10000; // Define the length of the linked list for performance testing
    const head = createLinkedList(length);

    // Measure the execution time of removeDupsNoBuffer
    const startTime = process.hrtime();
    removeDupsNoBuffer(head);
    const endTime = process.hrtime(startTime);
    const executionTime = endTime[0] * 1000 + endTime[1] / 1000000; // Convert to milliseconds

    // Adjust the acceptable execution time according to your requirements
    const acceptableExecutionTime = 1000; // Specify the acceptable execution time in milliseconds

    expect(executionTime).toBeLessThanOrEqual(acceptableExecutionTime);
  });
});
