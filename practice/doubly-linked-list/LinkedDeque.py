from DoublyLinkedList import _DoublyLinkedList


class Empty(Exception):
    pass

class LinkedDeque(_DoublyLinkedList):
    """Double-ended queue implementation based on a doubly linked list.
    """
    def first(self):
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._header._next._element
    
    def last(self):
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._tailer._prev._element

    def insert_first(self, e):
        return self._insert_between(e, self._header, self._header._next)

    def insert_last(self, e):
        return self._insert_between(e, self._tailer._prev, self._tailer)
    
    def delete_first(self):
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._delete_node(self._header._next)

    def delete_last(self):
        if self.is_empty():
            raise Empty("Deque is empty")
        return self._delete_node(self._tailer._prev)


if __name__ == '__main__':
    ld = LinkedDeque()
    ld.insert_first(1)
    ld.insert_last(2)
    ld.insert_last(3)
    print(ld)
    print(ld.first())
    print(ld.last())
    ld.delete_first()
    print(ld)
