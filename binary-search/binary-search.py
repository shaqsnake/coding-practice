def binary_search(data, target, low, high):
    if low > high:
        return -1
    
    mid = high + low // 2
    if  data[mid] == target:
        return mid
    elif data[mid] < target:
        return binary_search(data, target, mid+1, high)
    else:
        return binary_search(data, target, low, mid-1)

def binary_search2(data, target, low, high):
    while low < high:
        mid = low + high // 2

        if data[mid] == target:
            return mid
        if data[mid] < target:
            low = mid + 1
        else:
            high = mid -1

    return -1



if __name__ == '__main__':
    l = [1, 2, 4, 6, 7, 8, 11, 15, 21, 27]
    print(binary_search(l, 2, 0, len(l)-1))
    print(binary_search2(l, 2, 0, len(l)-1))
