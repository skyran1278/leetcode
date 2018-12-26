class MyCircularQueue:

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        :type k: int
        """
        self.queue = [None]*k

        self.size = k - 1
        self.count = -1

        self.head = None
        self.tail = None

    def enQueue(self, value):
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        elif self.isEmpty():
            self.head = 0
            self.tail = 0
        else:
            if self.tail == self.size:
                self.tail = 0
            else:
                self.tail += 1

        self.count += 1
        self.queue[self.tail] = value

        return True

    def deQueue(self):
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        else:
            self.queue[self.head] = None
            self.count -= 1

            if self.count == -1:
                self.head = None
                self.tail = None
            elif self.head == self.size:
                self.head = 0
            else:
                self.head += 1

            return True

    def Front(self):
        """
        Get the front item from the queue.
        :rtype: int
        """
        if self.head is None:
            return -1

        return self.queue[self.head]

    def Rear(self):
        """
        Get the last item from the queue.
        :rtype: int
        """
        if self.tail is None:
            return -1

        return self.queue[self.tail]

    def isEmpty(self):
        """
        Checks whether the circular queue is empty or not.
        :rtype: bool
        """
        if self.head is None:
            return True

        return False

    def isFull(self):
        """
        Checks whether the circular queue is full or not.
        :rtype: bool
        """
        if self.count == self.size:
            return True
        return False


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
