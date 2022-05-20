#include <iostream>
#include <string>
#include <sstream>
#include "Eliza.h"

using namespace std;

int main (){

    cout << "Testing rotate_vowels" << endl;
    string s = "i'M A coOkiE monster";
    string val = rotate_vowels(s);

    cout << val;

    // cout << "Testing Enter" << endl;
    // enter();

    // return 0;
}