// 只出现一次的数字
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

// 说明：

// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 示例 1:

// 输入: [2,2,1]
// 输出: 1
// 示例 2:

// 输入: [4,1,2,1,2]
// 输出: 4
#define NULL 0

int singleNumber(int* nums, int numsSize){
    if(nums==NULL||numsSize==0){
        return 0;
    }
    int num=0;
    for (int i=0; i<numsSize; i++) {
        num^=nums[i];
    }
    return num;
}

//利用异或运算性质！！！
//时间复杂度O(n)，空间复杂度O(1)