/*
	解题思路：通过创建一个临时数组，将nums1和nums2两个数组的元素进行比较，较小的元素放入临时数组中从而变成使其成为非递减数组
	最后将临时数组拷贝给nums1完成程序。
*/


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //创建一个临时的数组空间
    int* tmp = malloc(sizeof(int)*(m+n));

    //创建nums1、nums2和tmp数组的下标
    int i1=0,i2=0;
    int i=0;

    //当其中一个数组走到末尾时，循环停止
    while(i1 < m && i2 < n)
    {
        if(nums1[i1] < nums2[i2])
        {
            tmp[i] = nums1[i1];
            i++;
            i1++;
        }
        else
        {
            tmp[i] = nums2[i2];
            i++;
            i2++;
        }
    }

    //当另一个数组下标未走到结尾时，则将此数组后的所有元素放到临时数组中
    while(i1 < m)
    {
        tmp[i] = nums1[i1];
        i++;
        i1++;
    }
    while(i2 < n)
    {
        tmp[i] = nums2[i2];
        i++;
        i2++;
    }

    //拷贝tmp至nums1中
    memcpy(nums1,tmp,sizeof(int)*(m+n));

    //最后释放临时数组的空间
    free(tmp);
}

/*
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int p1 = 0, p2 = 0;
    int sorted[m + n];
    int cur;
    
    while (p1 < m || p2 < n) 
    {
        if (p1 == m) 
        {
            cur = nums2[p2++];
        } 
        else if (p2 == n) 
        {
            cur = nums1[p1++];
        } 
        else if (nums1[p1] < nums2[p2]) 
        {
            cur = nums1[p1++];
        } 
        else 
        {
            cur = nums2[p2++];
        }
        sorted[p1 + p2 - 1] = cur;
    }

    for (int i = 0; i != m + n; ++i) 
    {
        nums1[i] = sorted[i];
    }
}

*/
