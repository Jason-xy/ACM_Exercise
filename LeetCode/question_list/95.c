struct TreeNode** create(int start,int end,int*m)
// 返回所有从start开始到end结束这些数所能构成的二叉搜索树，并通过间接赋值输出这些二叉树的数目
{
    struct TreeNode **p,**lefts,**rights;
    int a,i,b,j,k,count = 0;       //定义的变量
    if(start>end) {              //最最最边界的情况
        p = (struct TreeNode**)malloc(sizeof(struct TreeNode*)); //二级指针只指向一个一级指针
        *p = NULL; *m = 1; return p;
    } 
    if(start == end)             //当子树个数为一时的特殊情况
    {
         p = (struct TreeNode**)malloc(sizeof(struct TreeNode*));   //二级指针只指向一个一级指针
        *p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*p)->left = (*p)->right = NULL;   //当子树为1时的赋值
        (*p)->val = start;
        *m = 1;
        return p;
    }                         //为了减少循环量，不写也可以
    p=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*10000);//设置一个足够大的分配内存空间来存储左右子树的各种情况
    for(i = start;i<=end;i++)
    {
        lefts = create(start,i-1,&a);
        rights = create(i+1,end,&b);     //递归生成左右子树s
        
        for(k = 0;k<a;k++)
        {
            for(j=0;j<b;j++)          //两个for循环链接两个子树s        
            {
                p[count] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                p[count]->val = i;
                p[count]->left = lefts[k];
                p[count]->right = rights[j];      
                count++; //记录个数
            }
        } 
    }
     *m = count;
    return p;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize){
    struct TreeNode** p;
    if(n == 0) 
    {
        *returnSize = 0;
        return NULL;
    }       //当n为0的特殊情况
    p = create(1,n,returnSize);  //调用函数计算
    return p;
}//结束
// ————————————————
// 版权声明：本文为CSDN博主「weixin_44839228」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/weixin_44839228/article/details/89845733