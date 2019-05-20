
寻找[l, r]内满足 >=x 的最小值，即找到满足条件的左极值
```c++
while (l < r) {
    int mid = (l + r) >> 1;
    if (a[mid] >= x) r = mid;
    else l = mid + 1;
}
return a[l];
```

寻找[l, r]内满足 <=x 的最大值，即找到满足条件的右极值
```c++
while (l < r) {
    int mid = (l + r + 1) >> 1; //保证边界合法
    if (a[mid] <= x) l = mid;
    else r = mid - 1;
}
return a[l];
```