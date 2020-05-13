#include <string>
#include <vector>
#include "SuffixArray.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Implement suffix_array() correctly
 */

vector<unsigned int> suffix_array(const string & s) {
    vector<unsigned int> n;
    vector<string> suffix_arr;
    unordered_map<string, unsigned int> map;
    // assigned all substrings of suffix_array to array
    for( unsigned int i = 0; i < s.length(); i ++){
        string subStr = s.substr(i);
        suffix_arr.push_back(subStr);
        map.emplace(subStr, i);
    }
    // sort
    std::sort (suffix_arr.begin(), suffix_arr.end());
    // how to output indexes?
    for ( vector<string>::iterator iter = suffix_arr.begin(); iter != suffix_arr.end(); iter++){
        string toFind = *iter;
        n.push_back(map[toFind]);
    }
    return n;
}
