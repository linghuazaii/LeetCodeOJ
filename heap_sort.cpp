#include "common.h"

void heapify(vector<int> &data, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;
    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        swap_i(data[largest], data[i]);
        heapify(data, n, largest);
    }
}

void heap_sort(vector<int> &data) {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(data, n, i);

    for (int i = n - 1; i >= 0; --i) {
        swap_i(data[0], data[i]);
        heapify(data, i, 0);
    }
}

int main(int argc, char **argv) {
    vector<int> data = generate_vec(1, 100, 17);
    dump_vec(data);

    heap_sort(data);
    dump_vec(data);

    return 0;
}
