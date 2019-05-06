class Empty(Exception):
    pass

class Stack():
    def __init__(self):
        self._data = []
    
    def __len__(self):
        return len(self._data)

    def is_empty(self):
        return len(self._data) == 0
    
    def pop(self):
        if self.is_empty():
            raise Empty("Stack is empty.")
        return self._data.pop()

    def push(self, v):
        return self._data.append(v)

    def top(self):
        if self.is_empty():
            raise Empty("Stack is empty.")
        return self._data[-1]

if __name__ == '__main__':
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print("stack size: %d" % (len(stack), ))
    while not stack.is_empty():
        print(stack.pop())