/* This file is auto-generated.Edit it at your own peril.*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <stack>
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
#include <math.h>
using namespace std;

/*
   Given an encoded string, return it's decoded string.
   
   The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
   
   You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
   
   Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
   
Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
    bool isDigit(char c) {
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }

    string decodeString(string &s, int &i) {
        string result = "";

        while (i < s.length() && s[i] != ']') {
            if (!isDigit(s[i]))
                result += s[i++];
            else {
                int n = 0;
                while (isDigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                ++i;
                string res = decodeString(s, i);
                ++i;
                while (n-- > 0)
                    result += res;
            }
        }
        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};

int main(int argc, char **argv) {
    //string test = "3[a]2[bc]";
    //string test = "3[a2[c]]";
    //string test = "2[abc]3[cd]ef";
    string test = "100[leetcode]";
    Solution s;
    string rs = s.decodeString(test);
    cout << test << endl;
    cout << rs << endl;

    return 0;
}

