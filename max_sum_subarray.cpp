#include "common.h"

#ifndef INT_MIN
#define INT_MIN 1 << (sizeof(int) * 8 - 1)
#endif

int max_sum_sub_array(vector<int> &data) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i = 0; i < data.size(); ++i) {
        max_ending_here += data[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;
}

int main(int argc, char **argv) {
    vector<int> data = generate_vec(-10, 10, 10);
    dump_vec(data);

    int max_sum = max_sum_sub_array(data);
    cout << max_sum << endl;

    return 0;
}
