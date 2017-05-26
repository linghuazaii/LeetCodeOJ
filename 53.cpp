/* This file is auto-generated.Edit it at your own peril.*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <termios.h>
#include <inttypes.h>
#include <errno.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/mman.h>
#include <sched.h>
#include <malloc.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
using namespace std;

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int length = nums.size();
        int dp[length];
        dp[0] = nums[0];
        int maximum = dp[0];
        for (int i = 1; i < length; ++i) {
            dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + nums[i];
            maximum = max(maximum, dp[i]);
        }

        return maximum;
    }
};

int main(int argc, char **argv) {
    const int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution so;
    cout<< so.maxSubArray(nums) <<endl;

    return 0;
}

