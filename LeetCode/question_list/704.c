// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1
int search(int* nums, int numsSize, int target){
    int head = 0, tail = numsSize - 1, mid = 0;
    while(head <= tail){
        mid = (head + tail) / 2;
        if(target == nums[mid])
            return mid;
        else if(target > nums[mid])
            head = mid + 1;
        else if(target < nums[mid])
            tail = mid - 1;
    }
    return -1;
}