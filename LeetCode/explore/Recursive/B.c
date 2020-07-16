// 杨辉三角 II
// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



// 在杨辉三角中，每个数是它左上方和右上方的数的和。

// 示例:

// 输入: 3
// 输出: [1,3,3,1]
// 进阶：

// 你可以优化你的算法到 O(k) 空间复杂度吗？

int* theRow(int *row, int rowIndex){
    if(rowIndex==0){
        row[0]=1;
        return row;
    }
    row=theRow(row, rowIndex-1);
    row[rowIndex]=1;
    for(int i=rowIndex-1; i>0; i--){
        row[i]=row[i-1]+row[i];
    }
    return row;
}

int* getRow(int rowIndex, int* returnSize){
    int* row=(int*)malloc(sizeof(int)*(rowIndex+1));
    *returnSize=rowIndex+1;
    return theRow(row, rowIndex);
}
//0ms 5.6mb