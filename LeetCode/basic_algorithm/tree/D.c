// 二叉树的层序遍历
// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

// 示例：
// 二叉树：[3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
// 整理输入输出
    int **ret = (int**)calloc(MAX_RETURN_NUM , sizeof(int*));
    *returnColumnSizes = (int*)calloc(MAX_RETURN_NUM, sizeof(int));
    *returnSize = 0;
// 建立指向节点的指针队列和两个索引
    struct TreeNode *queue[10000];
    int outIndex = 0;
    int inIndex = 0;
// 判断异常输入，进入while循环之前初始化
    if (root == NULL){return NULL;}
    queue[inIndex++] = root;
    int levelcount = inIndex - outIndex;
    int count = 0;
// BFS
    while (levelcount > 0){
        count++;
        ret[*returnSize] = (int*)calloc(levelcount,sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelcount;
// 每一层的动作
        for (int i = 0; i < levelcount; i++){
            if (queue[outIndex]->left != NULL){
                queue[inIndex++] = queue[outIndex]->left;
            }
            if (queue[outIndex]->right != NULL){
                queue[inIndex++] = queue[outIndex]->right;
            }
            ret[*returnSize][i] = queue[outIndex]->val;
            outIndex++;
        }
// 进入下一层之前的动作
        (*returnSize)++;
        levelcount = inIndex - outIndex;
    }
    return ret;
}