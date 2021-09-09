// 剑指 Offer 04. 二维数组中的查找
// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

//  

// 示例:

// 现有矩阵 matrix 如下：

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// 给定 target = 5，返回 true。

// 给定 target = 20，返回 false。

//  

// 限制：

// 0 <= n <= 1000

// 0 <= m <= 1000

//  

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//遍历
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = 0, j = 0;
    for(i = 0; i < matrixSize; i++){
        for(j = 0; j < *matrixColSize; j++){
            if(matrix[i][j] == target)
            return true;
        }
    }
    return false;
}

//遍历优化
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = 0, j = 0;
    if(!*matrixColSize || !matrixSize || !matrix)return false;
    for(i = 0; i < matrixSize && matrix[i][0] < target; i++){
        for(j = 0; j < *matrixColSize && matrix[i][j] <= target; j++){
            if(matrix[i][j] == target)
            return true;
        }
    }
    return false;
}

//二分法
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(!matrix || !matrixSize || !*matrixColSize)return false;
    int mid = 0;
    int head = 0, tail = matrixSize * (*matrixColSize) - 1;
    int x = 0, y = 0;
    while(head <= tail) {
        mid = (head + tail) / 2;
        x = mid % *matrixColSize;
        y = mid / matrixSize;
        if(target == matrix[x][y])
            return true;
        else if(target > matrix[x][y])
            head = mid + 1;
        else if(target < matrix[x][y])
            tail = mid - 1;
    }
    return false;
}


