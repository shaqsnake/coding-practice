class Empty(Exception):
    pass


class ArrayQueue(object):
    DEFAULT_CAPACITY = 10
    def __init__(self):
        self._data = [None] * ArrayQueue.DEFAULT_CAPACITY
        self._size = 0
        self._front = 0

    def __len__(self):
        return self._size
    
    def __str__(self):
        res = []
        for i in range(self._size):
            res.append(self._data[(self._front+i) % len(self._data)])
        return ''.join("{}".format(res))

    def is_empty(self):
        return self._size == 0

    def _resize(self, n):
        # newQueue = [None] * n
        # for i in range(len(self._data)):
        #     newQueue[i] = self._data[(self._front+i) % len(self._data)]
        # self._data = newQueue
        oldQueue = self._data
        self._data = [None] * n

        walk = self._front
        for i in range(self._size):
            self._data[i] = oldQueue[walk]
            walk = (walk + 1) % len(oldQueue)
        self._front = 0

    def enqueue(self, v):
        if self._size == len(self._data): # dynamic resize
            self._resize(2*self._size)
        # circle reuse
        avail = (self._front + self._size) % len(self._data)
        self._data[avail] = v
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            raise Empty("Queue is empty.")
        res = self._data[self._front]
        self._data[self._front] = None
        # back to front if end up to the tail
        self._front = (self._front + 1) % self._size
        self._size -= 1
        return res


if __name__ == '__main__':
    q = ArrayQueue()
    for i in range(1, 11):
        q.enqueue(i)
    print(q)
    q.dequeue()
    q.dequeue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(11)
    print(q)
    