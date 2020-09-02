// 剑指 Offer 12. 矩阵中的路径
// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

// [["a","b","c","e"],
// ["s","f","c","s"],
// ["a","d","e","e"]]

// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

//  

// 示例 1：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true
// 示例 2：

// 输入：board = [["a","b"],["c","d"]], word = "abcd"
// 输出：false
// 提示：

// 1 <= board.length <= 200
// 1 <= board[i].length <= 200

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#define true 1
#define false 0

//待优化
typedef int bool;
typedef struct position{
    int x;
    int y;
}Pos;
typedef struct cross{
    Pos pos[10];
    int num;
    int k[10];
}Cross;

bool exist(char** board, int boardSize, int* boardColSize, char* word){

    if(word[0]=='a' && word[1]== 0)
    return true;

    int path[150][150] = {0};
    int k = 0;

    Pos start, now;
    start.x = 0; start.y = 0;
    char cmp = word[k];

    Cross stk;
    stk.num = 1;
    for(int i = 0; i < 10;i++)
    stk.k[i] = 0;

    for(start.x = 0; start.x < boardSize; start.x++){
        for(start.y = 0; start.y < boardSize; start.y++){
            for(int i = 0; i < 150; i++){
                for(int j = 0; j < 150; j++){
                    path[i][j] = 0;
                }
            }
            now.x = start.x, now.y = start.y, k = 0;
            for(;board[start.x][start.y] == word[0];){
                now.x = stk.pos[stk.num - 1].x;
                now.y = stk.pos[stk.num - 1].y;
                k = stk.k[stk.num - 1];
                stk.num--;
                if(board[now.x][now.y] == word[k] && path[now.x][now.y] == 0){
                    path[now.x][now.y] = 1;
                    k++;
                    if(word[k] == 0)
                        return true;
                    if(now.x + 1 < boardSize && board[now.x + 1][now.y] == word[k] && path[now.x + 1][now.y] == 0){
                        stk.pos[stk.num].x = now.x + 1;
                        stk.pos[stk.num].y = now.y;
                        stk.k[stk.num] = k;
                        stk.num++;
                    }
                    if(now.x - 1 >= 0 && board[now.x - 1][now.y] == word[k] && path[now.x - 1][now.y] == 0){
                        stk.pos[stk.num].x = now.x - 1;
                        stk.pos[stk.num].y = now.y;
                        stk.k[stk.num] = k;
                        stk.num++;
                    }
                    if(now.y + 1 < boardSize && board[now.x][now.y + 1] == word[k] && path[now.x][now.y + 1] == 0){
                        stk.pos[stk.num].x = now.x;
                        stk.pos[stk.num].y = now.y + 1;
                        stk.k[stk.num] = k;
                        stk.num++;
                    }
                    if(now.y - 1 >= 0 && board[now.x][now.y - 1] == word[k] && path[now.x][now.y - 1] == 0){
                        stk.pos[stk.num].x = now.x;
                        stk.pos[stk.num].y = now.y - 1;
                        stk.k[stk.num] = k;
                        stk.num++;
                    }
                    if(stk.num == 0)
                        break;
                }
            }
        }
    }
    return 0;
}




//回溯
bool myExist(char **board, int rows, int cols, int **arr, int row, int col, int *strLen, char* str)
{
    if (str[*strLen] == '\0') {
        return true;
    } 

    int res = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == str[*strLen] && arr[row][col] == 0) {
        (*strLen)++;
        arr[row][col] = 1;
        res = myExist(board, rows, cols, arr, row - 1, col, strLen, str) ||
              myExist(board, rows, cols, arr, row, col + 1, strLen, str) ||
              myExist(board, rows, cols, arr, row + 1, col, strLen, str) ||
              myExist(board, rows, cols, arr, row, col - 1, strLen, str);

        if (!res) {
            (*strLen)--;
            arr[row][col] = 0;
        }              
    }

    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
    if (board == NULL || boardSize <= 0 || word == NULL) {
        return false;
    }

    int rows = boardSize;
    int cols = *boardColSize;
    int i, j;
    int **arr = (int **)malloc(sizeof(int *) * rows);
    bool res = false;
    int strLen = 0;

    for (i = 0; i < rows; i++) {   
        arr[i] = (int *)malloc(sizeof(int) * cols);
        memset(arr[i], 0, sizeof(int) * cols);
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (myExist(board, rows, cols, arr, i, j, &strLen, word)) {
                res = true;
                break;;
            }
        }
    }

    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    if (res) {
        return true;
    } else {
        return false;
    }
}