/*
方法一：使用额外的数组

我们可以使用额外的数组来将每个元素放至正确的位置。用 n 表示数组的长度，我们遍历原数组，
将原数组下标为 i 的元素放至新数组下标为 (i+k) mod n 的位置，最后将新数组拷贝至原数组即可。

*/


void rotate(int* nums, int numsSize, int k) 
{
    int newArr[numsSize];
	
    for (int i = 0; i < numsSize; ++i) 
	{
        newArr[(i + k) % numsSize] = nums[i];
    }
	
    for (int i = 0; i < numsSize; ++i) 
	{
        nums[i] = newArr[i];
    }
}

/*
复杂度分析

时间复杂度： O(n)其中 n 为数组的长度。
空间复杂度： O(n)。
*/
