

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int permutationSize = 1;
    for (int i=2; i<=numsSize; i++)
    {
        permutationSize *= i;
    }
    int* ans = (int *)malloc(permutationSize * numsSize * sizeof(int));
    int p[numsSize];
    for(int i=0; i<numsSize; i++)
    {
        p[i] = i;
    }
    memcpy(ans, nums, numsSize * sizeof(int));
    int* ptr = ans + numsSize;
    for(int i=1; i<permutationSize; i++, ptr+=numsSize)
    {
        int j = numsSize-2;
		while(p[j] > p[j+1])
		{
			j--;
		}
		int num = p[j];
		int k = numsSize-1;
		while(p[k] < num)
		{
			k--;
		}
		p[j] = p[k];
		p[k] = num;
		for(j=j+1, k=numsSize-1; j < k; j++, k--)
		{
			num = p[j];
			p[j] = p[k];
			p[k] = num;
		}
        for(j=0; j<numsSize; j++)
        {
            *(ptr+j) = nums[p[j]];
        }
    }
    int** rtn_arr= (int **)malloc(permutationSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(permutationSize * sizeof(int));
    for(int i=0; i<permutationSize; i++)
    {
        *(rtn_arr+i) = ans+i*numsSize;
        *(*returnColumnSizes + i) = numsSize;
    }
    *returnSize = permutationSize;
    return rtn_arr;
}
