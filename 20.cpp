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
#include <stack>
using namespace std;
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool pair_brackets(stack<char> &st, char bracket) {
        if (st.empty())
            return false;
        char temp = st.top();
        if (temp == '(' && bracket == ')')
            return true;
        if (temp == '{' && bracket == '}')
            return true;
        if (temp == '[' && bracket == ']')
            return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i) {
            if (pair_brackets(st, s[i]))
                st.pop();
            else
                st.push(s[i]);
        }
        if (st.empty())
            return true;
        return false;
    }
};

int main(int argc, char **argv) {
    Solution so;
    cout << (so.isValid("()[]{}") ? "true" : "false") <<endl;

    return 0;
}

