// 搜索插入位置
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 你可以假设数组中无重复元素。

// 示例 1:

// 输入: [1,3,5,6], 5
// 输出: 2
// 示例 2:

// 输入: [1,3,5,6], 2
// 输出: 1
// 示例 3:

// 输入: [1,3,5,6], 7
// 输出: 4
// 示例 4:

// 输入: [1,3,5,6], 0
// 输出: 0

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/array-and-string/cxqdh/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int searchInsert(int* nums, int numsSize, int target){
    int min = 0, max = numsSize - 1, mid = 0;
    while(min <= max){
        mid = min + (max - min) / 2;
        if(nums[mid] == target)
        return mid;
        else if(nums[mid] < target)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return min;
}