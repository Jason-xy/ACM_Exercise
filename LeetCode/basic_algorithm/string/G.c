// 实现 strStr()
// 实现 strStr() 函数。

// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:

// 输入: haystack = "hello", needle = "ll"
// 输出: 2
// 示例 2:

// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
// 说明:

// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
void Get_Next(char* T, int *next)
{
	int j, k;
	j = 0;
	k = -1;
	next[0] = -1;
	while (j < strlen(T))
	{
		if (k == -1 || T[j] == T[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

//KMP算法
int KMP(char* S, char* T)
{
    if(T=="")return 0;
	int i = 0, j = 0,next[255]={0};
	Get_Next(T, next);
	int slen = strlen(S);
	int tlen = strlen(T);

	while (i < slen && j < tlen)
	{
		if (j == -1 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == tlen)
	{
		return i - tlen;
	}
	else
	{
		return -1;
	}
}