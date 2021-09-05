// 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

// 不要使用系统的 Math.random() 方法。

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand10() {
    while (true) {
        int x = (rand7() - 1) * 7 + (rand7() - 1); // 0~48
        if (x >= 1 && x <= 40) return x % 10 + 1;
        
        x = (x % 40) * 7 + rand7(); // 1~63
        if (x <= 60) return x % 10 + 1;
        x = (x - 61) * 7 + rand7(); // 1~21
        if (x <= 20) return x % 10 + 1;
    }
}