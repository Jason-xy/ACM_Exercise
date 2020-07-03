// 有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？



// 连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。

//  

// 输入的cont代表连分数的系数（cont[0]代表上图的a0，以此类推）。返回一个长度为2的数组[n, m]，使得连分数的值等于n / m，且n, m最大公约数为1。

//  

// 示例 1：

// 输入：cont = [3, 2, 0, 2]
// 输出：[13, 4]
// 解释：原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。
// 示例 2：

// 输入：cont = [0, 0, 3]
// 输出：[3, 1]
// 解释：如果答案是整数，令分母为1即可。
// 限制：

// cont[i] >= 0
// 1 <= cont的长度 <= 10
// cont最后一个元素不等于0
// 答案的n, m的取值都能被32位int整型存下（即不超过2 ^ 31 - 1）。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/deep-dark-fraction
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
int gcd(int a, int b){
    int r;
    while(r){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int GCD(int a,int b){
    while(b^=a^=b^=a%=b);
    return a;
}

void plus(int *a,int *b,int *c){
    c[0]=a[0]*b[1]+b[0]*a[1];
    c[1]=a[1]*b[1];
}

int* fraction(int* cont, int contSize, int* returnSize) {
    int temp1[2] = { 1,cont[contSize - 1] }, temp2[2] = { 1,1 }, r = 0;
    int* ans = (int*)malloc(sizeof(int) * 2);
    for (int i = contSize - 1; i > 0; i--) {
        temp2[0] = cont[i - 1];
        plus(temp1, temp2, temp1);
        temp1[0] ^= temp1[1];
        temp1[1] ^= temp1[0];
        temp1[0] ^= temp1[1];
    }
    r = gcd(temp1[0], temp1[1]);
    ans[1] = temp1[0] / r;
    ans[0] = temp1[1] / r;
    returnSize[0] = 2;
    return ans;
}

int main(){
    int a[2]={3,2};
    int b[2]={3,2};
    plus(a,b,a);
    printf("%d %d\n",a[0],a[1]);
    printf("%d",gcd(12,4));
}
