// 两个数组的交集 II
// 给定两个数组，编写一个函数来计算它们的交集。

// 示例 1:

// 输入: nums1 = [1,2,2,1], nums2 = [2,2]
// 输出: [2,2]
// 示例 2:

// 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出: [4,9]
// 说明：

// 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
// 我们可以不考虑输出结果的顺序。
// 进阶:

// 如果给定的数组已经排好序呢？你将如何优化你的算法？
// 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
// 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NULL 0
//复杂度nlogn 8ms 5.4mb
void quick_sort(int* s, int l, int r){
    if (l < r){
        int i = l, j = r, x = s[l];
        while (i < j){
            while(i < j && s[j] >= x)
                j--;  
            if(i < j) 
                s[i++] = s[j];
            while(i < j && s[i] < x)
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(!nums1||!nums2||!nums1Size||!nums2Size){
        returnSize[0]=0;
        return NULL;
    }
    quick_sort(nums1,0,nums1Size-1);
    quick_sort(nums2,0,nums2Size-1);
    int i=0,j=0,ansnum=0,max=0;
    max=nums1Size>=nums2Size?nums1Size:nums2Size;
    int* ans=(int*)malloc(sizeof(int)*max);
    memset(ans,0,sizeof(int)*max);
    returnSize[0]=0;
    for(i=0; i<nums1Size&&j<nums2Size;){
        if(nums1[i]>nums2[j])
        j++;
        else if(nums1[i]<nums2[j])
        i++;
        else{
            ans[ansnum++]=nums1[i];
            i++;
            j++;
            returnSize[0]++;
        }
    }
    return ans;
}

