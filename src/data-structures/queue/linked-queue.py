class Empty(Exception):
    pass

class LinkedQueue(object):

    class _Node(object):
        __slots__ = '_element', '_next'

        def __init__(self, e, n):
            self._element = e
            self._next = n

    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    def __len__(self):
        return self._size
    
    def __str__(self):
        res = ""
        cur = self._head
        while cur:
            res += "{} ".format(cur._element)
            cur = cur._next
        return res

    def is_empty(self):
        return self._size == 0
    
    def first(self):
        if self.is_empty():
            raise Empty("Queue is empty")
        return self._head._element

    def dequeue(self):
        if self.is_empty():
            raise Empty("Queue is empyt")
        res = self._head._element
        self._head = self._head._next
        self._size -= 1
        if self.is_empty():
            self._tail = None
        return res

    def enqueue(self, e):
        newNode = self._Node(e, None)
        if self.is_empty():
            self._head = newNode
        else:
            self._tail._next = newNode
        self._tail = newNode
        self._size += 1


if __name__ == '__main__':
    queue = LinkedQueue()
    for i in range(1, 10):
        queue.enqueue(i)
    print(queue)
    print(queue.first())
    print(queue.dequeue())
    print(queue.dequeue())
    print(queue)