#include "common.h"
#include <vector>

int rand_range(int start, int end) {
    if (start < end) {
        int temp;
        temp = start;
        start = end;
        end = temp;
    }
    return (start + rand() / (RAND_MAX / (end - start + 1) + 1));
}

void swap_i(int &l, int &r) {
    int temp = l;
    l = r;
    r = temp;
}

vector<int> generate_vec(int start, int end, int count, int seed)  {
    srand(time(0) + seed);
    vector<int> data;
    for (int i = 0; i < count; ++i) {
        data.push_back(rand_range(start, end));
    }

    return data;
}

void dump_vec(vector<int> &data) {
    cout<<"vector data: ";
    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<"\n\n";
}
