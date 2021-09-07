// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

// B是A的子结构， 即 A中有出现和B相同的结构和节点值。

// 例如:
// 给定的树 A:

//      3
//     / \
//    4   5
//   / \
//  1   2
// 给定的树 B：

//    4 
//   /
//  1
// 返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool rootSubStructure(struct TreeNode* A, struct TreeNode* B){
    if(B == NULL)
        return true;
    else if(A == NULL || B->val != A->val)
        return false;
    else 
        return rootSubStructure(A->left, B->left) && rootSubStructure(A->right, B->right);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if(A == NULL || B == NULL)
        return false;
    else 
        return rootSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}