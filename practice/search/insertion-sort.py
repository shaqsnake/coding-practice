def insertionSort(l):
    for i in range(1, len(l)):
        tmp = l[i]
        j = i
        while j > 0 and tmp < l[j-1]:
            l[j] = l[j-1]
            j -= 1
        l[j] = tmp
    
    return l


if __name__ == '__main__':
    l = [5, 3, 7, 1, 2, 4, 6]
    print(insertionSort(l))