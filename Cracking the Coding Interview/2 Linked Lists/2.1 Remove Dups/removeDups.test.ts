import { Node, removeDups, removeDupsNoBuffer } from './removeDups';

// Helper function to convert an array to a linked list
const arrayToLinkedList = (arr: number[]) => {
  const head = new Node(arr[0]);
  let current = head;
  for (let i = 1; i < arr.length; i++) {
    const newNode = new Node(arr[i]);
    current.next = newNode;
    current = newNode;
  }
  return head;
};

// Helper function to convert a linked list to an array
const linkedListToArray = (head: Node | null) => {
  const arr = [];
  let current = head;
  while (current !== null) {
    arr.push(current.value);
    current = current.next;
  }
  return arr;
};

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
