#include "common.h"

int max_product_sub_array(vector<int> &data) {
    int max_product_here = 1;
    int min_product_here = 1;
    int max_product = 1;

    for (int i = 0; i < data.size(); ++i) {
        if (data[i] > 0) {
            max_product_here *= data[i];
            min_product_here = min(min_product_here * data[i], 1);
        } else if (data[i] == 0) {
            max_product_here = 1;
            min_product_here = 1;
        } else {
            int temp = max_product_here;
            max_product_here = max(min_product_here * data[i], 1);
            min_product_here = temp * data[i];
        }
        if (max_product < max_product_here)
            max_product = max_product_here;
    }

    return max_product;
}

int main(int argc, char **argv) {
    vector<int> data = generate_vec(-10, 10, 10);
    dump_vec(data);

    int max_product = max_product_sub_array(data);
    cout << max_product << endl;

    return 0;
}
