// 对称二叉树
// 给定一个二叉树，检查它是否是镜像对称的。

 

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
 

// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3
 

// 进阶：

// 你可以运用递归和迭代两种方法解决这个问题吗？

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int LNR(struct TreeNode * root,int* array,int index){
    if(!root){
        array[index]=123456;
        return index+1;
    }
    if(root->left||root->right)
    index=LNR(root->left,array,index);
    array[index]=root->val;
    index+=1;
    if(root->left||root->right)
    index=LNR(root->right,array,index);
    return index;
}

int RNL(struct TreeNode * root,int* array,int index){
    if(!root){
        array[index]=123456;
        return index+1;
    }
    if(root->left||root->right)
    index=RNL(root->right,array,index);
    array[index]=root->val;
    index+=1;
    if(root->left||root->right)
    index=RNL(root->left,array,index);
    return index;
}

bool isSymmetric(struct TreeNode* root){
    if(root){
        if(root->left&&root->right)
        if(root->left->val!=root->right->val)
        return false;
    }
    int arrayLNR[10000]={0},arrayRNL[10000]={0},numLNR=0,numRNL=0;
    numLNR=LNR(root,arrayLNR,numLNR);
    numRNL=RNL(root,arrayRNL,numRNL);
    for(int i=0;i<numLNR/2+1;i++){
        if(arrayLNR[i]!=arrayRNL[i])
        return false;
    }
    return true;
}
//两个相反的遍历序列比较 有BUG
//4ms 6.4mb

int isMirror(struct TreeNode* T1, struct TreeNode* T2){
    if(!T1&&!T2)return 1;
    if(!T1||!T2)return 0;
    return (T1->val==T2->val)&&isMirror(T1->left,T2->right)&&isMirror(T1->right,T2->left);
}

bool isSymmetric(struct TreeNode* root){
    return isMirror(root,root);
}//4ms 6.3mb

int isMirror(struct TreeNode* T1, struct TreeNode* T2){
    if(!T1&&!T2)return 1;
    if(!T1||!T2)return 0;
    return (T1->val==T2->val)&&isMirror(T1->left,T2->right)&&isMirror(T1->right,T2->left);
}

bool isSymmetric(struct TreeNode* root){
    if(!root)return 1;
    return isMirror(root->left,root->right);
}//相比之前可以少遍历一倍的节点

