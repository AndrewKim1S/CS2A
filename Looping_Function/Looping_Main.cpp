
#include <iostream>
#include <string>
#include "Looping_Functions.h"
using namespace std;

int main(){
    cout << "\nTesting play game(8)" << endl;
    play_game(8);

    cout << "\nTesting Etox(7.5,9)" << endl;
    int x = etox(7.5,9);
    cout << x << endl;

    cout << "\nTesting count chars(My favorite movie is Iron Man,i)" << endl;
    x = count_chars("My favorite movie is Iron Man", 'i');
    cout << x << endl;

    cout << "\nTesting gcd(20,45)" << endl;
    x = gcd(20,45);
    cout << x << endl;

    cout << "\nTesting get_ap_terms(5,8,10)" << endl;
    string y = get_ap_terms(5,8,10);
    cout << y << endl;

    cout << "\nTesting get_gp_terms(5,8,10)" << endl;
    y = get_gp_terms(5,8,10);
    cout << y << endl;

    cout << "\nTesting get_nth_fibonacci_number(9)" << endl;
    x = get_nth_fibonacci_number(9);
    cout << x << endl;
}