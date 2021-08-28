/*
输入为[1,2,3,4,5,6,7],k = 3;

方法2：数组翻转

数组旋转次数为 k = k % numsSize ,所以只需将 0 ~ numsSize-k-1 各位置的元素进行逆置,即[4,3,2,1,5,6,7]；
再将 numsSize - k ~ numsSize - 1 各位置的元素进行逆置,即[4,3,2,1,7,6,5];
最后再讲整个数组进行逆置，即[5,6,7,1,2,3,4];

*/


//代码的实现

//设计一个逆置函数
void reverse(int* num,int left,int right)
{
    while(left < right)
    {
        int tmp = num[left];
        num[left] = num[right];
        num[right] = tmp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    //当k>numSize时
    k %= numsSize;

    reverse(nums,0,numsSize-k-1);
    reverse(nums,numsSize-k,numsSize-1);
    reverse(nums,0,numsSize-1);

}

