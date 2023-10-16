import { Node } from '../linkedList';

export const sumLists = (
  list1: Node | null,
  list2: Node | null
): Node | null => {
  if (list1 == null && list2 == null) {
    return null;
  }

  const addedList: Node = new Node(0);
  let current: Node = addedList;
  while (list1 != null || list2 != null) {
    let addedValue: number = current.value;
    if (list1 != null) {
      addedValue += list1.value;
      list1 = list1.next;
    }
    if (list2 != null) {
      addedValue += list2.value;
      list2 = list2.next;
    }
    current.value = addedValue % 10;
    if (list1 == null && list2 == null && addedValue < 10) {
      break;
    }
    current.next = new Node(addedValue > 10 ? 1 : 0);
    current = current.next;
  }
  return addedList;
};

const sum = (
  digit: number,
  list1: Node | null | undefined,
  list2: Node | null | undefined
): Node | null => {
  if (list1 == null && list2 == null && digit === 0) {
    return null;
  }

  let addedValue = digit;
  if (list1 != null) {
    addedValue += list1.value;
  }
  if (list2 != null) {
    addedValue += list2.value;
  }
  const currentDigit = new Node(addedValue % 10);

  currentDigit.next = sum(addedValue > 10 ? 1 : 0, list1?.next, list2?.next);

  return currentDigit;
};
export const sumLists2 = (
  list1: Node | null,
  list2: Node | null
): Node | null => {
  return sum(0, list1, list2);
};
