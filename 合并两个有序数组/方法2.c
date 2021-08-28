/*
直接合并后排序

最直观的方法是先将数组nums2放进nums1的尾部，然后直接对整个数组进行排序

*/

int cmp(int* a, int* b) {
    return *a - *b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    for (int i = 0; i != n; ++i) 
	{
        nums1[m + i] = nums2[i];
    }

	qsort(nums1, nums1Size, sizeof(int), cmp);
}


