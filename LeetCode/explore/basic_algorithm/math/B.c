//  Fizz Buzz
// 写一个程序，输出从 1 到 n 数字的字符串表示。

// 1. 如果 n 是3的倍数，输出“Fizz”；

// 2. 如果 n 是5的倍数，输出“Buzz”；

// 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

// 示例：

// n = 15,

// 返回:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char** res = (char**)malloc(sizeof(char*)*n);
    for(int i=1;i<=n;i++){
        res[i-1] = (char*)malloc(sizeof(char)*10); 
        memset(res[i-1], 0, 10);  
        if(i%3==0)
            strcat(res[i-1], "Fizz");
        if(i%5==0)
            strcat(res[i-1], "Buzz");
        if(strlen(res[i-1])==0)
            sprintf(res[i-1],"%d", i);
    }
    return res;
}