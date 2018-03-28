#include "common.h"

typedef struct node {
    struct node *left;
    struct node *right;
    int val;
} node;

node *build_tree(vector<int> &data) {
    if (data.empty())
        return NULL;

    node *root = (node *)calloc(1, sizeof(node));
    root->val = data[0];

    queue<node *> q;
    q.push(root);

    node *cur;
    for (int i = 1; !q.empty();) {
        cur = q.front();
        if (i < data.size()) {
            cur->left = (node *)calloc(1, sizeof(node));
            cur->left->val = data[i++];
            q.push(cur->left);
        }
        if (i < data.size()) {
            cur->right = (node *)calloc(1, sizeof(node));
            cur->right->val = data[i++];
            q.push(cur->right);
        }
        q.pop();
    }

    return root;
}

void layer_traverse(node *root) {
    queue<node *> q;
    if (root == NULL)
        return;

    q.push(root);
    node *cur;
    while (!q.empty()) {
        cur = q.front();
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
        q.pop();
        cout << cur->val << " ";
    }
    cout<<"\n\n";
}

void preorder(node *root) {
    if (root != NULL) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


int main(int argc, char **argv) {
    vector<int> data = generate_vec(1, 100, 17);
    dump_vec(data);
    node *root = build_tree(data);
    layer_traverse(root);
    preorder(root);
    cout << endl;

    return 0;
}
