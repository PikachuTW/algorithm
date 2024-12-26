/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int assume1 = 0;
    int assume2 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == assume1) {
            count1 += 1;
        } else if (nums[i] == assume2) {
            count2 += 1;
        } else if (count1 <= 0) {
            assume1 = nums[i];
            count1 = 1;
        } else if (count2 <= 0) {
            assume2 = nums[i];
            count2 = 1;
        } else {
            count1 -= 1;
            count2 -= 1;
        }
    }
    int check1 = 0;
    int check2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == assume1) {
            check1 += 1;
        } else if (nums[i] == assume2) {
            check2 += 1;
        }
    }
    int arr[2] = {0};
    *returnSize = 0;
    if (check1 > numsSize / 3) {
        arr[(*returnSize)++] = assume1;
    }
    if (check2 > numsSize / 3) {
        arr[(*returnSize)++] = assume2;
    }
    int* returnArr = malloc(sizeof(int) * (*returnSize));
    memmove(returnArr, arr, sizeof(int) * (*returnSize));
    return returnArr;
}