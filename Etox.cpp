//Student ID: SHEEHYUN

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double etox_5_terms(double x){
  return 1 + x + x*x/2 + x*x*x/6 + x*x*x*x/24;
}

int main(int argc, char ** argv){
  string user_input;
  double x;

  cout << "Enter a value for x: ";
  getline(cin, user_input);
  istringstream(user_input) >>x;

  double result;
  result = etox_5_terms(x);
  cout << result;

  return 0;
}
