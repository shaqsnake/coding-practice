from stack import Stack

def findRFMax(l):
    res = [-1]*len(l)
    stack = Stack()

    for i in range(len(l)):
        while not stack.empty() and l[stack.peek()]< l[i]:
            # res.append(i)
            # stack.pop()
            res[stack.pop()] = i
        stack.push(i)

    return res


if __name__ == '__main__':
    l = [3, 4, 2, 1, 5, 7, 10]
    # l = [3, 4, 1, 2, 5, 7, 10]
    print(findRFMax(l))