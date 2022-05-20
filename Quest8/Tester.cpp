#include <iostream>
#include <vector>

#include "Stacks.h"

using namespace std;

int main(){
    Stack_Int a;
    for(int i = 18; i < 1500; i ++){
        a.push(i);
    }
    string result = a.to_string();
    cout << result << endl;
}