export class Node<T = unknown> {
  public value: T;
  public next: Node<T> | null;

  constructor(value: T) {
    this.value = value;
    this.next = null;
  }
}

// Helper function to convert an array to a linked list
export const arrayToLinkedList = <T>(arr: T[]) => {
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
export const linkedListToArray = (head: Node | null) => {
  const arr = [];
  let current = head;
  while (current != null) {
    arr.push(current.value);
    current = current.next;
  }
  return arr;
};

// Helper function to create a linked list of a specific length
export const createLinkedList = (length: number) => {
  if (length <= 0) {
    throw new Error('Invalid linked list length');
  }

  const head = new Node(1);
  let current = head;
  for (let i = 2; i <= length; i++) {
    const newNode = new Node(i);
    current.next = newNode;
    current = newNode;
  }

  return head;
};

export const reverseLinkedList = <T>(head: Node<T> | null) => {
  let current = head;
  let prev = null;
  while (current) {
    const next = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }
  return prev;
};
