#ifndef __COMMON_H
#define __COMMON_H
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

int rand_range(int start, int end);
void swap_i(int &l, int &r);
vector<int> generate_vec(int start, int end, int count, int seed = 1);
void dump_vec(vector<int> &data); 

#endif
