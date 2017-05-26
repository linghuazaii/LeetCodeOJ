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
using namespace std;

/**
 * Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’ * s complement method is used.

Note:

 - All letters in hexadecimal (a-f) must be in lowercase.
 - The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
 - The given number is guaranteed to fit within the range of a 32-bit signed integer.
 - You must not use any method provided by the library which converts/formats the number to hex directly.
 */

class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        const char table[17] = "0123456789abcdef";
        uint32_t number = uint32_t(num);
        string result = "";
        char bit;
        while (number > 0) {
            bit = number & 0xF;
            result.push_back(table[bit]);
            number >>= 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char **argv) {
    Solution so;
    //int num = 19920520;
    int num = -1;
    cout << so.toHex(num) << endl;

    return 0;
}

