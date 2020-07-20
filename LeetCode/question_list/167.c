// 两数之和 Ⅱ
// 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

// 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

// 说明:

// 返回的下标值（index1 和 index2）不是从零开始的。
// 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
// 示例:

// 输入: numbers = [2, 7, 11, 15], target = 9
// 输出: [1,2]
// 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int index_min,int index_max,int* array,int num){
    int mid;
    while(index_min <= index_max){
        mid=(index_max-index_min)/2+index_min;
        if(array[mid]==num)
        return mid;
        else if(array[mid]>num)
        index_max=mid-1;
        else if(array[mid]<num)
        index_min=mid+1;
    }
    return 0;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* ans=(int*)malloc(sizeof(int)*2);
    (*returnSize)=2;
    for(int i=0;i<numbersSize;i++){
        ans[0]=i+1;
        ans[1]=find(i+1,numbersSize-1,numbers,target-numbers[i])+1;
        if(ans[1]-1)
        return ans;
    }
    return 0;
}
//二分查找 8ms 6.5mb
