#include "common.h"

int partition(vector<int> &data, int begin, int end) {
    int i = begin - 1;
    int pivot = data[end];
    for (int j = begin; j < end; ++j) {
        if (data[j] <= pivot) {
            ++i;
            swap_i(data[i], data[j]);
        }
    }
    swap_i(data[i + 1], data[end]);

    return (i + 1);
}

void quick_sort_imp(vector<int> &data, int begin, int end) {
    if (begin < end) {
        int pivot = partition(data, begin, end);
        quick_sort_imp(data, begin, pivot - 1);
        quick_sort_imp(data, pivot + 1, end);
    }
}

void quick_sort(vector<int> &data) {
    quick_sort_imp(data, 0, data.size() - 1);
}

int main(int argc, char **argv) {
    vector<int> data = generate_vec(1, 100, 17);
    dump_vec(data);

    // first round
    //partition(data, 0, 16);
    //dump_vec(data);

    quick_sort(data);
    dump_vec(data);

    return 0;
}
