// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
int missingNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] != i) return i;
    }
    return numsSize;
}