// 3的幂
// 给定一个整数，写一个函数来判断它是否是 3 的幂次方。

// 示例 1:

// 输入: 27
// 输出: true
// 示例 2:

// 输入: 0
// 输出: false
// 示例 3:

// 输入: 9
// 输出: true
// 示例 4:

// 输入: 45
// 输出: false
// 进阶：
// 你能不使用循环或者递归来完成本题吗？


//基础思路
bool isPowerOfThree(int n){
    if(!n)return false;
    if(n==1)return true;
    while(n!=3){
        if(n%3)
        return false;
        n/=3;
    }
    return true;
}
//28ms 5.9mb

//检测该数是否为int类最大3的幂的约数
bool isPowerOfThree(int n){
    return (n>0) && (1162261467%n==0);
}
//20ms 6mb

bool isPowerOfThree(int n){
    if(n < 0)
        return false;
    unsigned int tmp = 1;
    while (tmp < n) tmp = (tmp << 1) + tmp;//左移一位相当于x2，加tmp相当于x3
    return (tmp == n ? true : false);
}
//16ms 6mb
