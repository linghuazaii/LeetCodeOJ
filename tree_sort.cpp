#include "common.h"

typedef struct node {
    struct node *left;
    struct node *right;
    int val;
} node;

void insert_node(node *root, int val) {
    node *
}

node *create_binary_search_tree(vector<int> &data) {
    if (data.empty())
        return NULL;

    node *root = (node *)calloc(1, sizeof(node));
    root->val = data[0];
    for (int i = 1; i < data.size(); ++i) {
        insert_node(root, data[i]);
    }

    return root;
}

int main(int argc, char **argv) {


    return 0;
}
