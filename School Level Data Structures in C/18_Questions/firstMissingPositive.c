//Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
//You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space

//using hashmap
#include<stdio.h>
#include<stdlib.h>
int findMissingPositive(int A[], int n){
    //create hash array, calloc assigns 0
    int *H = (int*)calloc(n+2, sizeof(int));
    //1 for present nos
    for(int i = 0; i<n; i++){
        if(A[i] > 0 && A[i] <= n){
            H[A[i]] = 1;
        }
    }
    //search in hash table
    for(int i = 1; i < n+1; i++){
        if(H[i] == 0){
            free(H);
            return i;
        }
    }
    free(H);
    return 1;
}
int main(){
    int A[] = {3, 4, -1, 1};
    int n = 4;
    int ans = findMissingPositive(A, 4);
    printf("The first missing positive interger is: %d", ans);
    return 0;
}

// as per conditions

int firstMissPositive(int nums[], int numsSize)
{
    int i;

    for(i = 0; i < numsSize; i++)
    {
        while(nums[i] >= 1 &&
              nums[i] <= numsSize &&
              nums[i] != nums[nums[i]-1])
        {
            int temp = nums[i];
            nums[i] = nums[temp-1];
            nums[temp-1] = temp;
        }
    }

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != i + 1)
            return i + 1;
    }

    return numsSize + 1;
}