#include<stdio.h> 
int* twoSum(int* nums, int numsSize, int target) {
    int res[2];
    int i,j;
    for(i=0;i<numsSize;i++){
        res[0]=i;
        int x=target-nums[i];
        for(j=i+1;j<numsSize;j++){
            if(x==nums[j]){
                res[1]=j;
                return res;
            }
        }
    }
}
int main(){
	int nums[] = {2,7,11,15};
    int *p  = twoSum(nums, 4, 9);
    printf("nums[%d]+nums[%d]=9",p[0],p[1]);
    return 0;

}
