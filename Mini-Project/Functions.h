#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

void fiveHundredNumbers(vector<int>&v, int&n);

vector<int> algoSelect(vector<int> v);
vector<int> algoMerge(vector<int> v);
vector<int> algoRadix(vector<int> v);
void printVector(vector<int>& arr);