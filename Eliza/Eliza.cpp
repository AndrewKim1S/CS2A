//Student ID: 20447032

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string rotate_vowels(string& s){
    string copy = s;
    s = "";
    for(size_t i = 0; i < copy.length(); i++){
        if(copy[i] == 'A' || copy[i] == 'a'){
            s += (int) copy[i] + 4;
        }
        else if(copy[i] == 'E' || copy[i] == 'e'){
            s += (int) copy[i] + 4;
        }
        else if(copy[i] == 'I' || copy[i] == 'i'){
            s += (int) copy[i] + 6;
        }
        else if(copy[i] == 'O' || copy[i] == 'o'){
            s += (int) copy[i] + 6;
        }
        else if(copy[i] == 'U' || copy[i] == 'u'){
            s += (int) copy[i] - 20;
        } 
        else {
            s += copy[i];
        }
    }
    return s;
}

string lispify(string s){
    string result = "";
    for(size_t i = 0; i < s.length(); i++){
        if(s[i] == 's'){
            result += "th";
            continue;
        }
        if(s[i] == 'S'){
            result += "Th";
            continue;
        }
        result += s[i];
    }
    return result;
}

void enter(){
    cout << "What?" << endl;
    string userinput;
    while(true){
        getline(cin, userinput);
        if(userinput == ""){
            cout << "What?" << endl;
            continue;
        }
        cout << "    " + userinput + "\n\n";
        if(userinput.find("!") != string::npos){
            cout << "OMG! You don't say!! " << userinput  << "!!!!!" << endl;
            continue;
        }
        if(userinput.find("why") != string::npos || userinput.find("what") != string::npos){
            cout << "I'm sorry, I don't like questions that contain what or why" << endl;
            continue;
        }
        if (userinput.find('s') != string::npos){
            cout << "Interthting. When did you thtop thtopping your thibilanth?" << endl;
            cout << lispify(userinput) << "! Sheesh! Now what?" << endl;
            continue;
        }
        if(userinput.find("bye") != string::npos || userinput.find("quit") != string::npos|| userinput.find("Bye") != string::npos|| userinput.find("Quit") != string::npos){
            cout << "Ok Bye. Nice being a force of change in your life." << endl;
            break;
        } else {
            int num = rand() % 10;
            if(num == 8 || num == 9){
                cout << "Huh? Why do you say: " << userinput << "?" <<  endl;
                continue;
            } else {
                cout << rotate_vowels(userinput) << "?" << endl;
                continue;  
            }
        }
    }
}
