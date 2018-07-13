def cache(f):
    data = dict()
    def wrapper(n):
        if n not in data:
            data[n] = f(n)
            # print("cache miss: %d" % (n,))
        return data[n]
    return wrapper

@cache
def fib(n):
    if n < 2:
        return 1
    return fib(n-2) + fib(n-1)


if __name__ == '__main__':
    for i in range(10):
        print(i, fib(i))