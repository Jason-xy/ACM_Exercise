// 打乱数组
// 打乱一个没有重复元素的数组。

 

// 示例:

// // 以数字集合 1, 2 和 3 初始化数组。
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);

// // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
// solution.shuffle();

// // 重设数组到它的初始状态[1,2,3]。
//solution.shuffle();


typedef struct {
    int *source;
    int *output;
    int size;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj= (Solution*)malloc(sizeof(Solution));
    obj->source=(int*)malloc(sizeof(int)*(numsSize+1));
    obj->output=(int*)malloc(sizeof(int)*(numsSize+1));
    for(int i=0;i<numsSize; i++)
    obj->source[i]=nums[i],obj->output[i]=nums[i];
    obj->size=numsSize;
    return obj;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize=obj->size;
    for(int i=0;i<obj->size;i++)
    obj->output[i]=obj->source[i];
    return obj->output;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize=obj->size;
    memset(obj->output,INT_MAX,sizeof(int)*(obj->size+1));
    int pos=0;
    unsigned int n=(unsigned int)time(NULL);
    for(int i=0;i<obj->size;i++){
        srand((n++)%INT_MAX);
        pos=rand()%(obj->size);
        if(obj->output[pos]==INT_MAX)
        obj->output[pos]=obj->source[i];
        else{
            for(;obj->output[pos%obj->size]!=INT_MAX;pos++);
            obj->output[pos%obj->size]=obj->source[i];
        }
    }
    return obj->output;
}

void solutionFree(Solution* obj) {
    free(obj->output);
    free(obj->source);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/

typedef struct {
    int *array;
    int *origin;
    int size;
} Solution;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int randomInt(int min, int max){
    int ret = rand() % (max - min + 1) + min;
    return ret;
}

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *new = malloc(sizeof(Solution));
    new->size = numsSize;
    new->array = malloc(sizeof(int) * numsSize);
    new->origin = malloc(sizeof(int) * numsSize);
    for(int i = 0; i <  numsSize; i++){
        new->array[i] = nums[i];
        new->origin[i] = nums[i];
    }
    return new;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->size;
    for(int i = 0; i < *retSize; i++){
        obj->array[i] = obj->origin[i];
    }
    return obj->array;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize = obj->size;
    int swapIndex;
    //srand(time(NULL));
    for(int i = 0; i < *retSize; i++){
        swapIndex = randomInt(i, *retSize - 1);
        swap(&(obj->array[i]), &(obj->array[swapIndex]));
    }
    return obj->array;
}

void solutionFree(Solution* obj) {
    free(obj->array);
    free(obj->origin);
    free(obj);
    return;
}