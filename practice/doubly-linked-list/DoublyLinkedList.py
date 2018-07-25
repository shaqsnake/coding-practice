class _DoublyLinkedList(object):

    class _Node(object):
        __slots__ = '_element', '_prev', '_next'
        def __init__(self, element, prev, next):
            self._element = element
            self._prev = prev
            self._next = next
    
    def __init__(self):
        self._header = self._Node(None, None, None)
        self._tailer = self._Node(None, None, None)
        self._header._next = self._tailer
        self._tailer._prev = self._header
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def __str__(self):
        res = ""
        cur = self._header._next
        while cur != self._tailer:
            res += "{}->".format(cur._element)
            cur = cur._next
        return res[:-2]

    def _insert_between(self, e, predecessor, successor):
        newNode = self._Node(e, predecessor, successor)
        predecessor._next = newNode
        successor._prev = newNode
        self._size += 1
        return newNode

    def _delete_node(self, node):
        predecessor = node._prev
        successor = node._next
        predecessor._next = successor
        successor._prev = predecessor
        e = node._element
        node._element = node._prev = node._next = None
        return e
        