def unique(s, start, stop):
    if stop - start <= 1:
        return True
    elif not unique(s, start, stop-1):
        return False
    elif not unique(s, start+1, stop):
        return False
    else:
        return s[start] != s[stop-1]


if __name__ == '__main__':
    print(unique("abcb", 0, 4))

