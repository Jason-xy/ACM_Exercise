// 存在重复元素
// 给定一个整数数组，判断是否存在重复元素。

// 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

// 示例 1:

// 输入: [1,2,3,1]
// 输出: true
// 示例 2:

// 输入: [1,2,3,4]
// 输出: false
// 示例 3:

// 输入: [1,1,1,3,3,4,3,2,4,2]
// 输出: true

#define false 0
#define true 1
typedef int bool;


//哈希链表 224ms 10.5mb
#include<stdlib.h>
#include<stdio.h>
typedef struct __HashNode HashNode;
struct __HashNode {
    int num;
    HashNode* next;
};
bool hashadd(HashNode** Table, int num) {
    HashNode* temp = (HashNode*)malloc(sizeof(HashNode));
    int hash = (num + 120000006) % 97;
    HashNode* p = Table[hash];
    temp->num = num;
    temp->next = NULL;
    for (; p; p = p->next) {
        if (num == p->num)
            return true;
    }
    if (Table[hash]->next)
        temp->next = Table[hash]->next;
    Table[hash]->next = temp;
    return false;
}
bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1)return false;
    if (nums[0] == nums[1])return true;
    HashNode** table = (HashNode**)malloc(sizeof(HashNode*) * 100);
    for (int i = 0; i < 100; i++) {
        table[i] = (HashNode*)malloc(sizeof(HashNode));
        table[i]->num = -1;
        table[i]->next = NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        if (hashadd(table, nums[i]))
            return true;
    }
    return false;
}
int main()
{
    int nums[4] = { -1,0,1 };
    containsDuplicate(nums, 4);
}

//暴力n^2 超时
bool containsDuplicate(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j <numsSize;j++){
            if(nums[j] == nums[i])
            return true;
        }
    }
    return false;
}

//哈希二维数组  
bool containsDuplicate(int* nums, int numsSize){
    if (numsSize <= 1)return false;
    if (nums[0] == nums[1])return true;
    int hashtable[110][110]={0};
    int hash=0,flag=0;
    for(int i=0; i < numsSize; i++){
        if(nums[i]!=0){
            hash=(nums[i]+120000006)%97;
            for(int j=0; j < 110; j++){
                if(hashtable[hash][j]==nums[i]){
                    return true;
                }
                else if(hashtable[hash][j]==0){
                    hashtable[hash][j]=nums[i];
                    break;
                }
            }
        }
        else{
            if(flag==1)
            return true;
            flag=1;
        }
    }
    return false;
}

//暴力调参
//hashtable[110][110] 52ms 8.1mb
//hashtable[1000][50] 28ms 8.1mb
//hashtable[10000][3] 20ms 7.7mb
//hashtable[5000][3]  16ms 8.0mb

//哈希一维数组 发生冲突
bool containsDuplicate(int* nums, int numsSize){
    if (numsSize <= 1)return false;
    if (nums[0] == nums[1])return true;
    int hashtable[50000]={0},hash=0;
    for(int i = 0; i < numsSize; i++){
        hash=(nums[i]+120000006)%49999;
        if(hashtable[hash]>0)
        return true;
        hashtable[hash]+=1;
    }
    return false;
}