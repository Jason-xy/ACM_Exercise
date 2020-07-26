// 4. 寻找两个正序数组的中位数
// 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

// 你可以假设 nums1 和 nums2 不会同时为空。

//  

// 示例 1:

// nums1 = [1, 3]
// nums2 = [2]

// 则中位数是 2.0
// 示例 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// 则中位数是 (2 + 3)/2 = 2.5

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i = 0, m = 0, n = 0, ans[2] = {0};
    long mid = (nums1Size + nums2Size) / 2;
    for(i = 0; i <= mid; i++){
        ans[1] = ans[0];
        if(m < nums2Size && n < nums1Size && nums1[n] >= nums2[m])
            ans[0] = nums2[m++];
        else if(m < nums2Size && n < nums1Size && nums1[n] <= nums2[m])
            ans[0] = nums1[n++];
        else if(n == nums1Size && m < nums2Size)
            ans[0] = nums2[m++];
        else if(m == nums2Size && n < nums1Size)
            ans[0] = nums1[n++];
    }
    if((long)(nums1Size + nums2Size) % 2 == 0)
    return (ans[0]+ans[1])/(double)2;
    else
    return ans[0];
}