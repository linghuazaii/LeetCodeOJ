#include <algorithm>
#include "common.h"


void merge(vector<int> &data, int begin, int mid, int end) {
    vector<int> left(data.begin() + begin, data.begin() + mid + 1);
    vector<int> right(data.begin() + mid + 1, data.begin() + end + 1);

    int li, ri, di = begin;
    for (li = 0, ri = 0; li < left.size() && ri < right.size();) {
        if (left[li] < right[ri]) {
            data[di] = left[li];
            ++li;
        } else {
            data[di] = right[ri];
            ++ri;
        }
        ++di;
    }

    while (li < left.size()) {
        data[di] = left[li];
        ++li;
        ++di;
    }

    while (ri < right.size()) {
        data[di] = right[ri];
        ++ri;
        ++di;
    }
}

void merge_sort_imp(vector<int> &data, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        merge_sort_imp(data, begin, mid);
        merge_sort_imp(data, mid + 1, end);
        merge(data, begin, mid, end);
    }
}

void merge_sort(vector<int> &data) {
    merge_sort_imp(data, 0, data.size() - 1);
}

int main(int argc, char **argv) {
    /*
    vector<int> l_data = generate_vec(1, 100, 9, 10);
    sort(l_data.begin(), l_data.end());
    dump_vec(l_data);

    vector<int> r_data = generate_vec(1, 100, 5, 20);
    sort(r_data.begin(), r_data.end());
    dump_vec(r_data);

    vector<int> data = merge(l_data, 0, l_data.size() - 1, r_data, 0, r_data.size() - 1);
    dump_vec(data);
    */
    vector<int> data = generate_vec(1, 100, 17);
    dump_vec(data);

    merge_sort(data);
    dump_vec(data);

    return 0;
}
