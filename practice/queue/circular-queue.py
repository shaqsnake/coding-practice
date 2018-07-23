class Empty(Exception):
    pass

class CircularQueue(object):
    """Queue implementation using circularly linked list for storage.
    """
    class _Node(object):
        def __init__(self, e, n):
            self._element = e
            self._next = n

    def __init__(self):
        self._tail = None
        self._size = 0

    def __len__(self):
        return self._size

    def __str__(self):
        if self.is_empty():
            return ""

        res = ""
        head = self._tail._next
        while head:
            res += "{} ".format(head._element)
            head = head._next
            if head == self._tail:
                res += "{} ".format(head._element)
                break
        return res

    def is_empty(self):
        return self._size == 0

    def first(self):
        if self.is_empty():
            raise Empty("Queue is empty")
        head = self._tail._next
        return head._element
    
    def dequeue(self):
        if self.is_empty():
            raise Empty("Queue is empty")
        head = self._tail._next
        if self._size == 1:
            self._tail = None
        else:
            self._tail._next = head._next
        self._size -= 1
        return head._element
    
    def enqueue(self, e):
        newNode = self._Node(e, None)
        if self.is_empty():
            newNode._next = newNode
        else:
            newNode._next = self._tail._next
            self._tail._next = newNode
        self._tail = newNode
        self._size += 1


if __name__ == '__main__':
    queue = CircularQueue()
    for i in range(1, 10):
        queue.enqueue(i)
    print(queue)
    print(queue.first())
    print(queue.dequeue())
    print(queue.dequeue())
    print(queue)