import { Node, arrayToLinkedList, linkedListToArray } from '../linkedList';
import { sumLists, sumLists2 } from './sumLists';

describe('sumLists', () => {
  it('returns the correct sum of two linked lists in reverse order', () => {
    // Create the first linked list: 7 -> 1 -> 6
    const list1 = arrayToLinkedList([7, 1, 6]);

    // Create the second linked list: 5 -> 9 -> 2
    const list2 = arrayToLinkedList([5, 9, 2]);

    const expectedOutput = [2, 1, 9]; // The sum of 617 + 295 is 912

    const result = sumLists(list1, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });

  it('returns the correct sum when one list is longer than the other', () => {
    // Create two linked lists: (7 -> 1 -> 6) and (9 -> 2)
    const list1 = arrayToLinkedList([7, 1, 6]);
    const list2 = arrayToLinkedList([9, 2]);
    const expectedOutput = [6, 4, 6];

    const result = sumLists(list1, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });

  it('returns the correct sum when one of the linked lists is empty', () => {
    // Create an empty linked list
    const emptyList: Node | null = null;

    // Create the second linked list: 5 -> 9 -> 2
    const list2 = arrayToLinkedList([5, 9, 2]);

    const expectedOutput = [5, 9, 2]; // The sum of 0 + 295 is 295

    const result = sumLists(emptyList, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });

  it('returns null when both linked lists are empty and there is no carry digit', () => {
    // Create two empty linked lists
    const emptyList1: Node | null = null;
    const emptyList2: Node | null = null;

    const result = sumLists(emptyList1, emptyList2);

    expect(result).toBeNull();
  });

  it('returns the correct sum when the linked lists have different lengths', () => {
    // Create the first linked list: 9 -> 7 -> 8
    const list1 = arrayToLinkedList([9, 7, 8]);

    // Create the second linked list: 6 -> 8 -> 5
    const list2 = arrayToLinkedList([6, 8, 5]);

    const expectedOutput = [5, 6, 4, 1]; // The sum of 879 + 586 is 1465

    const result = sumLists(list1, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });
});

describe('sumLists2', () => {
  it('returns the correct sum of two linked lists in reverse order', () => {
    // Create the first linked list: 7 -> 1 -> 6
    const list1 = arrayToLinkedList([7, 1, 6]);

    // Create the second linked list: 5 -> 9 -> 2
    const list2 = arrayToLinkedList([5, 9, 2]);

    const expectedOutput = [2, 1, 9]; // The sum of 617 + 295 is 912

    const result = sumLists2(list1, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });

  it('returns the correct sum when one list is longer than the other', () => {
    // Create two linked lists: (7 -> 1 -> 6) and (9 -> 2)
    const list1 = arrayToLinkedList([7, 1, 6]);
    const list2 = arrayToLinkedList([9, 2]);
    const expectedOutput = [6, 4, 6];

    const result = sumLists2(list1, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });

  it('returns the correct sum when one of the linked lists is empty', () => {
    // Create an empty linked list
    const emptyList: Node | null = null;

    // Create the second linked list: 5 -> 9 -> 2
    const list2 = arrayToLinkedList([5, 9, 2]);

    const expectedOutput = [5, 9, 2]; // The sum of 0 + 295 is 295

    const result = sumLists2(emptyList, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });

  it('returns null when both linked lists are empty and there is no carry digit', () => {
    // Create two empty linked lists
    const emptyList1: Node | null = null;
    const emptyList2: Node | null = null;

    const result = sumLists2(emptyList1, emptyList2);

    expect(result).toBeNull();
  });

  it('returns the correct sum when the linked lists have different lengths', () => {
    // Create the first linked list: 9 -> 7 -> 8
    const list1 = arrayToLinkedList([9, 7, 8]);

    // Create the second linked list: 6 -> 8 -> 5
    const list2 = arrayToLinkedList([6, 8, 5]);

    const expectedOutput = [5, 6, 4, 1]; // The sum of 879 + 586 is 1465

    const result = sumLists2(list1, list2);

    expect(linkedListToArray(result)).toEqual(expectedOutput);
  });
});

describe('performance comparison', () => {
  // Helper function to create a linked list of a specific length
  const createLinkedList = (length: number) => {
    let head: Node | null = null;
    let current: Node | null = null;
    for (let i = 1; i <= length; i++) {
      const newNode = new Node(9);
      if (head == null) {
        head = newNode;
        current = newNode;
      } else {
        current!.next = newNode;
        current = newNode;
      }
    }
    return head;
  };
  const list1 = createLinkedList(1000); // Create a linked list of length 10,000
  const list2 = createLinkedList(1000);

  it('for loop (sumLists) performs better than recursive (sumLists2)', () => {
    const start1 = process.hrtime();
    sumLists(list1, list2);
    const end1 = process.hrtime(start1);
    const time1 = end1[0] * 1000 + end1[1] / 1000000;

    const start2 = process.hrtime();
    sumLists2(list1, list2);
    const end2 = process.hrtime(start2);
    const time2 = end2[0] * 1000 + end2[1] / 1000000;

    expect(time1).toBeLessThan(time2);
  });
});
