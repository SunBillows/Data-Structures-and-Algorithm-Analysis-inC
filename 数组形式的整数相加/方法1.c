/*
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。 

示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
示例 3：

输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021
示例 4：

输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
输出：[1,0,0,0,0,0,0,0,0,0,0]
解释：9999999999 + 1 = 10000000000
*/

/*
  Note: The returned array must be malloced, assume caller calls free().
*/

int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
    //计算出k的位数
    int Ksize = 0;
    int kNum = k;
    while(kNum)
    {
        Ksize ++;
        kNum /= 10;
    }

    //设置len为两非负数中位数长的那一个数的位数
    int len = numSize>Ksize?numSize:Ksize;

    //初始化一个新数组用于存放两者相加后的值
    //malloc申请的内存空间为两者中较大的一个位数加1
    int *retArr = malloc(sizeof(int)*(len+1));

    int Ai = numSize-1; //num数组的下标
    int reti = 0;       //新数组retArr的下标
    int nextNum = 0;    //进位标志
    
    //循环，将两数的每一位相加
    while(len--)
    {
        int a = 0;
        if(Ai>=0)
        {
            a = num[Ai];
            Ai--;
        }

        //ret为两个位数相加的和，存放在retArr中
        int ret = a + k%10 + nextNum;
        k /= 10;

        //当两者之和大于10时
        if(ret>9)            
        {
            ret -= 10;
            //进位标志赋值为1
            nextNum = 1;          
        }
        //否则赋值为0
        else
            nextNum = 0;

        retArr[reti] = ret;        
        reti++;
    }

    if(nextNum == 1)
    {
        retArr[reti] = 1;        
        reti++;
    }
    
    //最后将新数组进行逆置
    int left = 0,right = reti - 1;
    while(left<right)
    {
        int temp = retArr[right];
        retArr[right] = retArr[left];
        retArr[left] = temp;
        left++;
        right--;
    }

    *returnSize = reti;
    return retArr;
}

