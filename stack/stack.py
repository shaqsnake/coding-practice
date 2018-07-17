class Stack():
    def __init__(self):
        self._data = list()
    
    def size(self):
        return len(self._data)

    def empty(self):
        return len(self._data) == 0
    
    def pop(self):
        return self._data.pop()

    def push(self, v):
        return self._data.append(v)

    def peek(self):
        if self.empty():
            return None
        return self._data[-1]

if __name__ == '__main__':
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print("stack size: %d" % (stack.size(), ))
    while not stack.empty():
        print(stack.pop())