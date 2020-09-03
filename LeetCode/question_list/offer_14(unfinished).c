// 剑指 Offer 14- I. 剪绳子
// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

// 示例 1：

// 输入: 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1
// 示例 2:

// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
// 提示：

// 2 <= n <= 58

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int cuttingRope(int n){
    int m1 = pow(n, 1/2), m2 = m1 + 1;
    int left1 = n % m1, left2 = n % m2;
    int sum1 = pow((n - left1) / m1, m1);
    if(left1)
    sum1 += pow(((n - left1) / m1 + 1), left1);
    int sum2 = pow((n - left2) / m2, m2);
    if(left2)
    sum2 += pow(((n - left2) / m2 + 1), left2);
    return sum1 > sum2 ? sum1 : sum2;
}