
int pivotIndex(int* nums, int numsSize) {
    int leftsum=0;
    int rightsum=0;
    int i=0;
    int res=0;
    while(i<numsSize){
        rightsum=0;
        for(int j=i+1;j<numsSize;j++){
            rightsum+=nums[j];
        }
        if(leftsum==rightsum){
            return i;
            break;
        }
        else{
            leftsum+=nums[i];
            i++;
        }
    }
    return -1;
 }
