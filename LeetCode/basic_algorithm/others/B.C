// 汉明距离
// 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

// 给出两个整数 x 和 y，计算它们之间的汉明距离。

// 注意：
// 0 ≤ x, y < 231.

// 示例:

// 输入: x = 1, y = 4

// 输出: 2

// 解释:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑

// 上面的箭头指出了对应二进制位不同的位置。

int hammingDistance(int x, int y){
    int num_x[33]={0},num_y[33]={0};
    int i=0,ans=0;
    while(x){
        num_x[i++]=x%2;
        x/=2;
    }
    i=0;
    while(y){
        num_y[i++]=y%2;
        y/=2;
    }
    for(i=0;i<33;i++){
        if(num_x[i]!=num_y[i])
        ans++;
    }
    return ans;
}//0ms 5.1mb;
