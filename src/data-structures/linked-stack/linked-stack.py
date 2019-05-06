class LinkedStack(object):

    class _Node(object):
        __slots__ = '_element', '_next'

        def __init__(self, element, next):
            self._element = element
            self._next = next

    def __init__(self):
        self._head = None
        self._size = 0

    def __len__(self):
        return self._size

    def __str__(self):
        res = ""
        cur = self._head
        while cur:
            res += "{} -> ".format(cur._element)
            cur = cur._next
        res += 'NULL'
        return res

    def is_empty(self):
        return self._size == 0

    def push(self, e):
        self._head = self._Node(e, self._head)
        self._size += 1

    def pop(self):
        if self.is_empty():
            raise Empty("Stack is empty")
        res = self._head._element
        self._head = self._head._next
        self._size -= 1
        return res

    def top(self):
        if self.is_empty():
            raise Empty("Stack is empty")
        return self._head._element

def createLinkedStack(elements):
    stack = LinkedStack()
    for element in elements:
        stack.push(element)
    return stack


if __name__ == '__main__':
    stack = createLinkedStack([1, 2, 3, 4, 5])
    print(len(stack))
    print(stack)
    print(stack.pop())
    print(stack.pop())
    print(stack)
    print(stack.top())