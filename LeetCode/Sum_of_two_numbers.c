// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

//  

// 示例:

// 给定 nums = [2, 7, 11, 15], target = 9

// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/two-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int hash[65534],temp=0;
    int *ans;
    ans=(int*)malloc(sizeof(int)*2);
    for(long i=0;i<=65534;i++)hash[i]=-1;
    for(int i=0;i<numsSize;i++){
        hash[nums[i]+32767]=i;
    }
    for(int i=0;i<numsSize;i++){
        temp=target-nums[i]+32767;
        if(hash[temp]>0&&hash[temp]!=i){
            returnSize[0]=2;
            ans[0]=i;
            ans[1]=hash[temp];
            return ans;
        }
    }
    returnSize[0]=0;
    return ans;
}
//小范围、长数组用hash表
//bug：超过int的数报错


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans;
    ans=(int*)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                returnSize[0]=2;
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
    returnSize[0]=0;
    return ans;
}
//大范围、短数组