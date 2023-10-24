import { Node } from '../linkedList';

export const isPalindrome = (head: Node | null): boolean => {
  const arr = [];
  let current = head;
  while (current) {
    arr.push(current.value);
    current = current.next;
  }
  for (let index = 0; index < arr.length / 2; index++) {
    const front = arr[index];
    const back = arr[arr.length - index - 1];
    if (front !== back) {
      return false;
    }
  }
  return true;
};

export const isPalindrome2 = (head: Node | null): boolean => {
  const arr = [];
  let fastRunner = head;
  let slowRunner = head;
  while (slowRunner && fastRunner && fastRunner.next) {
    arr.push(slowRunner.value);
    slowRunner = slowRunner.next;
    fastRunner = fastRunner.next.next;
  }

  if (slowRunner && fastRunner) {
    slowRunner = slowRunner.next;
  }

  while (slowRunner) {
    const top = arr.pop();
    if (top !== slowRunner.value) {
      return false;
    }
    slowRunner = slowRunner.next;
  }
  return true;
};
