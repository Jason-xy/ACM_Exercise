// 统计一个数字在排序数组中出现的次数。
int search(int* nums, int numsSize, int target){
    int head = 0, tail = numsSize - 1, mid = 0;
    int ans = 0, i = 0;
    while(head <= tail){
        mid = (head + tail) / 2;
        //如果小于中值，则在前半段。
        if(target < nums[mid]){
            if(tail == mid) break;
            tail = mid;
        }
        else if(target > nums[mid])
            head = mid + 1;
        else{
            for(i = mid; i >= 1 && nums[i - 1] == target; i--);
            for(;i < numsSize && nums[i] == target; i++) 
                ans++;
            return ans;
        }
    }
    return 0;
}