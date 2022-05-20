#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Pet.h"

using namespace std;

size_t Pet::_population = 0;


Pet::Pet(string name, long id, int num_limbs) {
    _population ++;
    _name = name;
    _id = id;
    _num_limbs = num_limbs;
}

Pet::~Pet() {
    _population --;
}

string Pet::get_name() const {
    return _name; 
}

long Pet::get_id() const {
    return _id;
}

int Pet::get_num_limbs() const {
    return _num_limbs;
}

bool Pet::set_name(string name) {
    if(name.empty()){
        return false;
    } else {
        _name = name;
        return true;
    }
}

bool Pet::set_id(long id) {
    if(id < 0){
        return false;
    } else {
        _id = id;
        return true;
    }
}

bool Pet::set_num_limbs(int num_limbs) {
    if(num_limbs < 0) {
        return false;
    } else {
        _num_limbs = num_limbs;
        return true;
    }
}

string Pet::to_string() const {
    long id = get_id();
    int num_limbs = get_num_limbs();
    string result = "(Name: " + get_name() + 
    ", ID: " + std::to_string(id) + 
    ", Limb Count: " + std::to_string(num_limbs) + ")";

    return result;
}

void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len) {
    // TODO - Resize pets as necessary
    pets.resize(n);
    long prev_id = 0;
    for (size_t i = 0; i < n; i++) {
        long id = prev_id + 1 + rand() % 10;
        pets[i].set_id(id);
        pets[i].set_num_limbs(rand() % 9); // up to arachnids

        // TODO - make and set a name of the requested length
        pets[i].set_name(make_a_name(name_len));
        // TODO - adjust prev_id as necessary
        prev_id = id;
    }
}

string Pet::make_a_name(int len) {
    string vowels = "aeiou";
    string consonants = "bcdfghjklmnpqrstvwxyz";
    string name = "";
    string s = (rand() % 2 == 0) ? consonants : vowels ;
    for (int i = 0; i < len; i ++){
        int index = rand() % s.length();
        name += s[index];
        s = (s==consonants) ? vowels: consonants;
    }
    return name;
}

bool operator==(const Pet& pet1, const Pet& pet2) {
// TODO - Your code here
    if(pet1.get_id() == pet2.get_id()){
        if(pet1.get_name() == pet2.get_name()){
            if(pet1.get_num_limbs() == pet2.get_num_limbs()){
                return true;
            }
            return false;
        }
        return false;
    } else {
        return false;
    }
}

bool operator!=(const Pet& pet1, const Pet& pet2) {
// TODO - Your code here
    if(pet1 == pet2){
        return false;
    } else {
        return true;
    }
}

ostream& operator<<(ostream& os, const Pet& pet) {
// TODO - Your code here
    os << pet.to_string();
    return os;
}

