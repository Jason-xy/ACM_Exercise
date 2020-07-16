// 加一
// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

// 你可以假设除了整数 0 之外，这个整数不会以零开头。

// 示例 1:

// 输入: [1,2,3]
// 输出: [1,2,4]
// 解释: 输入数组表示数字 123。
// 示例 2:

// 输入: [4,3,2,1]
// 输出: [4,3,2,2]
// 解释: 输入数组表示数字 4321。
#define NULL 0

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    if(!digits || !digitsSize){
        *returnSize=0;
        return NULL;
    }
    int* ans=(int*)malloc(sizeof(int)*(digitsSize+1));
    memset(ans, 0, sizeof(int)*(digitsSize+1));
    ans[digitsSize]+=1;
    for(int i=digitsSize;i>0;i--){
        ans[i]+=digits[i-1];
        if(ans[i]==10){
            ans[i]-=10;
            ans[i-1]+=1;
        }
    }
    if(ans[0]==0){
        int*p=ans+1;
        *returnSize=digitsSize;
        return p;
    }
    else{
        *returnSize=digitsSize+1;
        return ans;
    }
}
//0ms,5.7mb