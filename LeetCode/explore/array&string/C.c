// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:

// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:

// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/array-and-string/c5tv3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
//     if( !intervals || !intervalsSize || !*intervalsColSize){
//         returnColumnSizes = (int**)malloc(sizeof(int*));
//         returnColumnSizes[0] = (int*)malloc(sizeof(int));
//         returnColumnSizes[0][0] = 0;
//         return NULL;
//     }

//     int** ans = (int**)malloc(sizeof(int*)*intervalsSize);
//     ans[0] = (int*)malloc(sizeof(int) * 2);
//     ans[0][0] = intervals[0][0];
//     ans[0][1] = intervals[0][1];

//     returnColumnSizes = (int**)malloc(sizeof(int*)*intervalsSize);
//     returnColumnSizes[0] = (int*)malloc(sizeof(int));
//     returnColumnSizes[0][0] = 2; 

//     int i = 0, j = 0;
//     for(i = 1; i < intervalsSize; i++){
//         if(intervals[i][0] <= ans[j][1])
//             ans[j][1] = intervals[i][0];
//         else{
//             ans[++j] = (int*)malloc(sizeof(int) * 2);
//             ans[j][0] = intervals[i][0];
//             ans[j][1] = intervals[i][1];
//             returnColumnSizes[j] = (int*)malloc(sizeof(int));
//             returnColumnSizes[j][0] = 2;
//         }
//     }
//     *returnSize = j + 1;
//     return ans;
// }

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int box[100005];
    int keng[100005];
    int maxNum = 0;
    int l, r, cnt;
    returnSize[0] = 0;
    int **returnArr = (int**)calloc(intervalsSize, sizeof(int*));
    returnColumnSizes[0] = (int*)calloc(intervalsSize, sizeof(int));
    for(int i = 0; i < intervalsSize; ++i) {
        returnArr[i] = (int*)calloc(2, sizeof(int));
        returnColumnSizes[0][i] = 2;
    }
    memset(box, 0, sizeof(box));
    memset(keng, 0, sizeof(keng));
    for(int i = 0; i < intervalsSize; ++i) {
        if(box[intervals[i][0]] == box[intervals[i][1]]) {
            keng[intervals[i][0]] = 1;
        }
        ++box[intervals[i][0]];
        --box[intervals[i][1]];
        maxNum = maxNum < intervals[i][1] ? intervals[i][1] : maxNum;
    }
    for(int i = 0; i <= maxNum; ++i) {
        if(!box[i] && keng[i] && cnt == 0) {
            returnArr[returnSize[0]][0] = i;
            returnArr[returnSize[0]++][1] = i;
        }
        if(box[i]) {
            if(cnt == 0) {
                l = i;
            }
            cnt += box[i];
            if(cnt == 0) {
                r = i;
                returnArr[returnSize[0]][0] = l;
                returnArr[returnSize[0]++][1] = r;
            }
        }
    }
    return returnArr;
}