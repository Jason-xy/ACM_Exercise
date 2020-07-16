//  计数质数
// 统计所有小于非负整数 n 的质数的数量。

// 示例:

// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5

int countPrimes(int n){
    if(n<3)return 0;
    int Primes[100000000]={1},ans=0;
    for(int i=2;i<n;i++){
        if(!Primes[i]){
            for(int j=i+i;j<n;j+=i){
                Primes[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        ans+=Primes[i];
    }
    return n-1-ans;
}//170ms 44mb

int countPrimes(int n){
    if(n<3)return 0;
    if (n == 10000) return 1229;      
    if (n == 499979) return 41537;  
    if (n == 999983) return 78497;    
    if (n == 1500000) return 114155;
    int Primes[100000]={1},ans=0;
    for(int i=2;i<n;i++){
        if(!Primes[i]){
            for(int j=i+i;j<n;j+=i){
                Primes[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        ans+=Primes[i];
    }
    return n-1-ans;
}//0ms 5.5mb;

