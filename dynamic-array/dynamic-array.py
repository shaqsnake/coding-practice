import ctypes

class DynamicArray(object):
    def __init__(self):
        self._len = 0
        self._cap = 1
        self._ref = self._make_array(self._cap)

    def _make_array(self, n):
        return (n*ctypes.py_object)()

    def __len__(self):
        return self._len

    def __getitem__(self, i):
        if not 0 <= i < self._len:
            raise IndexError("out of index")
        return self._ref[i]

    def append(self, v):
        if self._len == self._cap:
            self._resize(self._cap*2)
        self._ref[self._len] = v
        self._len += 1
    
    def insert(self, k, v):
        if self._len == self._cap:
            self._resize(self._cap*2)
        for i in range(self._len, k, -1):
            self._ref[i] = self._ref[i-1]
        self._ref[k] = v
        self._len += 1

    def remove(self, v):
        for i in range(self._len):
            if self._ref[i] == v:
                for j in range(i, self._len-1):
                    self._ref[j] = self._ref[j+1]
                self._ref[self._len-1] = None
                self._len -= 1
                return
        raise ValueError("value not found")


    def _resize(self, c):
        temp = self._make_array(c)
        for i in range(self._len):
            temp[i] = self._ref[i]
        self._ref = temp
        self._cap = c


if __name__ == '__main__':
    da = DynamicArray()
    da.append(1)
    da.append(2)
    da.append(3)
    for i in range(len(da)):
        print(da[i])
    da.insert(1, 'a')
    for i in range(len(da)):
        print(da[i])
    da.remove('a')
    for i in range(len(da)):
        print(da[i])