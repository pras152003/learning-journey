
int pivotIndex(int* nums, int numsSize)
{
    int leftsum = 0;
    int rightsum = 0;

    for(int j = 0; j < numsSize; j++)
    {
        rightsum += nums[j];
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(leftsum == rightsum - nums[i])
        {
            return i;
        }
        else
        {
            leftsum += nums[i];
            rightsum -= nums[i];
        }
    }

    return -1;
}
