// Pow(x, n)
// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

// 示例 1:

// 输入: 2.00000, 10
// 输出: 1024.00000
// 示例 2:

// 输入: 2.10000, 3
// 输出: 9.26100
// 示例 3:

// 输入: 2.00000, -2
// 输出: 0.25000
// 解释: 2-2 = 1/22 = 1/4 = 0.25
// 说明:

// -100.0 < x < 100.0
// n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

double myPow(double x, int n){
    if(x==1)return 1;
    double ans = 1,cnt = x;
    int sign = 0;
    long m = n;
    if(m < 0){
        sign = 1;
        m = m - n - n;
    }
    while(m){
        if(m&1)
        ans*=cnt;
        cnt*=cnt;
        m>>=1;
    }
    if(sign)
    return 1/ans;
    else
    return ans;
}