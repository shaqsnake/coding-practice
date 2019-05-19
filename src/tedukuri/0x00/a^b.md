```c++
int power(int a, int b, int p) { // calculate a power b mod p
    int res = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
    }
    return res;
}
```