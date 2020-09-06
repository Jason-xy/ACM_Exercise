// 107. 二叉树的层次遍历 II
// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其自底向上的层次遍历为：

// [
//   [15,7],
//   [9,20],
//   [3]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
typedef struct queue{
    struct TreeNode *node[1000];
    int head;
    int tail;
    int length;
}Queue;

void push(Queue *queue, struct TreeNode *node){
    queue->node[queue->tail] = node;
    queue->tail = (queue->tail + 1) % 1000;
    queue->length++;
}

struct TreeNode *pop(Queue *queue){
    struct TreeNode *p = queue->node[queue->head];
    queue->head = (queue->head + 1) % 1000;
    queue->length--;
    return p;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    Queue *queue1 = (Queue*)malloc(sizeof(Queue));
    Queue *queue2 = (Queue*)malloc(sizeof(Queue));
    queue1->head = queue1->tail = queue1->length = queue2->head = queue2->tail =queue2->length = 0;

    int **ans = (int **)malloc(sizeof(int *)*15);

}

//TODO 






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct Queue {
    int front;
    int rear;
    int len;
    struct TreeNode* elms[];
} Queue;

Queue *creatQueue(int len){
    Queue *q = malloc(sizeof(Queue) + len*sizeof(struct TreeNode*));
    q->len = len;
    q->front = 0;
    q->rear = 0;
    return q;
}

void enQueue(Queue *q, struct TreeNode* node){
    if(node == NULL) return;
    if((q->rear+1)%(q->len) == q->front) return;
    q->elms[q->rear] = node;
    q->rear = (q->rear+1)%(q->len);
}

struct TreeNode* outQueue(Queue *q){
    if(q->rear == q->front) return NULL;
    struct TreeNode* node = q->elms[q->front];
    q->front = (q->front+1)%(q->len);
    return node;
}

int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    int left=maxDepth(root->left), right=maxDepth(root->right);
    return 1 + (left>=right ? left : right);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    // 计算树的最大深度
    *returnSize = maxDepth(root);

    // 以树的最大深度初始化结果的行数
    int **arrays = malloc(*returnSize * sizeof(int*));
    if(root==NULL) return arrays;// 空树请适可而止

    // 初始化保存每行的列数的数组
    *returnColumnSizes = malloc(*returnSize * sizeof(int));

    // 计算队列需要的最大长度
    // 即满二叉树最末层结点个数+1（因为用循环队列，所以+1）
    const int qMaxLen = (1 << (*returnSize-1)%(CHAR_BIT*sizeof(int))) +1;

    // 创建父队和子队，并把root入父队
    Queue *parentQ = creatQueue(qMaxLen), *childrenQ = creatQueue(qMaxLen);
    enQueue(parentQ, root);

    // level表示层数，遍历从最顶层开始，逐层向下
    // 初始i=1是为了结果的level行的列数正确
    for(int level=*returnSize-1, i=1; level > -1; --level){
        (*returnColumnSizes)[level] = i;
        arrays[level] = malloc(i * sizeof(int));

        // 父亲放到结果里，并且把孩子生出来
        for(i=0; parentQ->rear != parentQ->front; ++i){
            struct TreeNode* node = outQueue(parentQ);
            arrays[level][i] = node->val;
            if(node->left) enQueue(childrenQ, node->left);
            if(node->right) enQueue(childrenQ, node->right);
        }
        // 子队进化成父队
        // 下面的循环结束后会算出下一层父亲的个数
        // 并在下一次循环赋值(*returnColumnSizes)[level]
        for(i=0; childrenQ->rear != childrenQ->front; ++i)
            enQueue(parentQ, outQueue(childrenQ));
    }
    return arrays;
}