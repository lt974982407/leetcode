![image-20210330205111631](C:\Users\LITIE974982407\AppData\Roaming\Typora\typora-user-images\image-20210330205111631.png)

首先本题也可从右上出发（可以算之前题目的特例），因为从右上角出发，可以满足向左变小，向右变大。

也可以先找到行号，再在每一行里面找，注意查找的时候可以采用二分查找。

二分查找：

第一种二分查找：寻找某个数

```c++
int binarySearch(int[] nums, int target) {
    int left = 0;
    int right = nums.length - 1;
    
    while (left <= right){
        int mid = (left + right)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if (nums[mid] > target){
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
    }
    return -1;
}
```

针对以上问题：

有一个问题，循环的条件为什么时<= 而不是< ? 

开始的时候右边界为数组长度-1，这说明了去区间是左右封闭的，当区间不存在时即停止查找，即left > right，所以得到的循环条件。



第二种二分查找：寻找左侧边界的二分搜索，即当数组中存在重复元素的时候，返回最左边的值

```c++
int left_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0;
    int right = nums.length; // 注意

    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
        }
    }
   if (left == nums.length) return -1;
   return nums[left] == target ? left : -1;
}
```



首先right的初值为数组的长度，说明区间时左闭右开的。所以while的条件为left<right 。

再有明确一点，事实上，这里的left表示数组中到底有几个元素比target要小，所以当找到nums[mid] == target 的时候，并不是直接返回，而是进一步缩小范围。范围分为[left,mid) 和 [mid + 1, right)。

最后如果left为数组的大小，即数组中所有数字都要比target小，返回-1，函数中最后一句上一种类型相似。

第三种二分查找：寻找右侧边界的二分查找

```c++
int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    if (left == 0) return -1;
    return nums[left-1] == target ? (left-1) : -1;
}
```



这里要注意的是，left（right最终和left相等）表示的为小于等于target的数目，所以最后判定为left - 1。