#include <string>
#include "BWT.h"
#include <algorithm>    
#include <iostream>
#include <vector>
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwtRotate(const string & s, int n ){
    string rotate;
    string  shiftedChar = s.substr(0,n);
    string  restOfString = s.substr(n);
    rotate+=restOfString;
    rotate+=shiftedChar;
    return rotate;
}

string bwt(const string & s) {
    vector<string> rotatedStrings;
    string rbwt;
    for(unsigned int i = 0; i < s.length(); i++){
        string rotated = bwtRotate(s,i);
        rotatedStrings.push_back(rotated);
    }
    
    sort(rotatedStrings.begin(), rotatedStrings.end());
    // print out last character in each element of array
    for( vector<string>::iterator iter = rotatedStrings.begin(); iter != rotatedStrings.end(); iter++){
        string s = *iter;
        rbwt += s.back();
    }
    return rbwt;
}
