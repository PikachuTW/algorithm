int majorityElement(int* nums, int numsSize) {
    int assume = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == assume) {
            count += 1;
        } else {
            count -= 1;
        }
        if (count < 0) {
            assume = nums[i];
            count = 1;
        }
    }
    return assume;
}