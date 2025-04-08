#include <stdio.h>
#include <stdlib.h>

int checker(int c,int* new){
    int l=sizeof(new)/sizeof(new[0]);
    if (l==0) return 0;
    for (int i=0;i<l;i++){
        if (c==new[i]) return 1;
    }
    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize==0) return 0;
    int* new=(int*)malloc(sizeof(int)*numsSize);
    int c=0;
    for (int i=0;i<numsSize;i++){
        if (!checker(nums[i],new)){
            new[c]=nums[i];
            c++;
        }
    }
    for (int i=0;i<c;i++){
        nums[i]=new[i];
    }
    free(new);
    return c;
    
}