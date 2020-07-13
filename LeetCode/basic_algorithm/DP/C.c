// 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6
// 进阶:

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

int maxSubArray(int* nums, int numsSize){
    int max=nums[0],i=0,j=1,sum=nums[0];
    for(;j<numsSize;j++){
        sum+=nums[j];
        if(nums[i]<0){
            sum-=nums[i];
            i++;
        }
        else if(sum<0){
            i=j;
            sum=nums[i];
        }
        max=max>sum?max:sum;
    }
    return max;
}//8ms 6.1mb


#define MAX(a,b) ((a)>(b)?(a):(b))
int maxSubArray(int* nums, int numsSize){
    int tmp = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        tmp = MAX(tmp + nums[i], nums[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}