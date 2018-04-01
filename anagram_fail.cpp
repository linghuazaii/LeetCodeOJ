#include "common.h"

bool is_anagram(string &l, string &r) {
    int res = 0;
    for (int i = 0; i < l.size(); ++i)
        res ^= l[i];
    for (int i = 0; i < r.size(); ++i) 
        res ^= r[i];

    return (res == 0);
}

int main(int argc, char **argv) {
    string l = "listen";
    string r = "rilent";
    cout << (is_anagram(l, r) ? "true" : "false") << endl;

    return 0;
}
