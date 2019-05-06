from stack import Stack
from random import shuffle

def findRFMax(l):
    res = [-1]*len(l)
    stack = Stack()

    for i in range(len(l)):
        while not stack.is_empty() and l[stack.top()]< l[i]:
            # res.append(i)
            # stack.pop()
            res[stack.pop()] = i
        stack.push(i)

    return res


if __name__ == '__main__':
    l = [i for i in range(10)]
    shuffle(l)
    print(l)
    print(findRFMax(l))