//Student ID: SHEEHYUN

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool play_game(int n) {
  int x;
  string userinput;
  cout << "Welcome to my number guessing game\n\n";
  for(int i = 1; i < 7; i++){
    cout << "Enter a guess: ";
    getline(cin, userinput);
    istringstream(userinput) >> x;
    cout << "You entered: " << x << endl;
    if(x == n){
      cout << "You found it in " << i << " guess(es)." << endl;
      return true;
    }
  }
  cout << "\nI'm sorry. You didn't find my number." << endl;
  cout << "It was " << n << endl;
  return false;
}

double etox(double x, size_t n){
  if(n == 0){
    return 0;
  }
  double sum = 1.0;
  for(size_t i = 1; i < n; i++){
    double Vi;
    double px = 1;
    double fi = 1;
    for(size_t j = 1; j <= i; j++){
      fi *= j;
      px *= x;
    }
    Vi = px/fi;
    sum += Vi;
  }
  return sum;
}

size_t count_chars(string s, char c){
  size_t count = 0;
  for(size_t i = 0; i <s.length(); i++){
    if(s[i] == c){
    count ++;
    }
  }
  return count;
}

size_t gcd(size_t a, size_t b){
  while(a != b){
    if(a > b){
      a = a-b;
    }else{
      b = b-a;
    }
  }
  return a;
}

string get_ap_terms(int a, int d, size_t n){
  if(n == 0){
    return "";
  }
  int x = 0;
  string result = to_string(a);
  for(size_t i = 1; i < n; i++){
    x = a + i*d;
    result += "," + to_string(x);
  }
  return result;
}

string get_gp_terms(double a, double r, size_t n){
  if(n == 0){
    return "";
  }
  double x =0;
  ostringstream y;
  y << a;
  for(size_t i = 1; i < n; i++){
    double powri = 1;
    for(size_t j = 0; j < i; j++){
      powri *= r;
    }
    x = a * powri;
    y << "," << x;
  }
  return y.str();
}

double get_nth_fibonacci_number(size_t n){
  if(n <= 1){
    return n;
  }
  double prev = 0;
  double curr = 1;
  for(size_t i = 0; i < n -1; i++){
    double rece = prev + curr;
    prev = curr;
    curr = rece;
  }
  return curr;
}
