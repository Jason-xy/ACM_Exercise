// 合并两个有序数组
// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

 

// 说明:

// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

// 示例:

// 输入:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// 输出: [1,2,2,3,5,6]

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *help = (int*)malloc(sizeof(int) * (m + 1));
    int i = 0,num1 = 0,num2 = 0;
    for(i = 0;i < m;i++)
    help[i] = nums1[i];
    for(i = 0;i < m + n;i++){
        if(num1<m&&num2<n){
            if(help[num1]<=nums2[num2])
                nums1[i]=help[num1++];
            else
                nums1[i]=nums2[num2++];
        }
        else if(num1==m)
        nums1[i]=nums2[num2++];
        else if(num2==n)
        nums1[i]=help[num1++];
    }
}