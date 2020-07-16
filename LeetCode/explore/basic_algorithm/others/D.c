// 帕斯卡三角形
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



// 在杨辉三角中，每个数是它左上方和右上方的数的和。

// 示例:

// 输入: 5
// 输出:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **triangle= (int**)malloc(sizeof(int*)*(numRows));
    *returnColumnSizes=(int*)malloc(sizeof(int)*(numRows));
    *returnSize=numRows;
    for(int i=0; i<numRows; i++){
        triangle[i]=(int*)malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i]=i+1;
        triangle[i][0]=1;
        for(int j=1; j<i; j++){
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
        }
        triangle[i][i]=1;
    }
    return triangle;
}
