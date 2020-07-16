// 整数反转
// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

// 示例 1:

// 输入: 123
// 输出: 321
//  示例 2:

// 输入: -123
// 输出: -321
// 示例 3:

// 输入: 120
// 输出: 21
// 注意:

// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

int reverse(int x) {
    if (x == 0)
        return 0;
    char s[20] = { 0 };
    int len = 0;
    long ans = 0;
    sprintf(s, "%d", x);
    if (x > 0) {
        len = strlen(s);
        for (int i = len - 1; i >= 0; i--) {
            if (ans <= 2147483647)
                ans = ans * 10 + (s[i] - '0');
            else return 0;
        }
        if (ans <= 2147483647)
            return ans;
        else return 0;
    }
    else {
        len = strlen(s) - 1;
        for (int i = len; i > 0; i--) {
            if (ans <= 2147483648)
                ans = ans * 10 + (s[i] - '0');
            else return 0;
        }
        if (ans <= 2147483648)
            return -ans;
        else return 0;
    }
}
//4ms 5.2mb

int reverse(int x){
    long m=0;
    int n=x;
    while(n){
        m=m*10+n%10;
        n=n/10;
    }
    if((int)m == m){//判定是否爆int。
            return (int)m;
        }
    return 0;
}
//0ms 5.1mb