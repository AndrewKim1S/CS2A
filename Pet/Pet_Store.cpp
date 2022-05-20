#include <iostream>
#include <sstream>

#include <vector>

#include "Pet_Store.h"

using namespace std;

enum _SORT_ORDER {
    BY_ID,
    BY_NAME,
    NONE
};

Pet_Store::Pet_Store(size_t n) {
    set_size(n);
    _sort_order = NONE;
}

void Pet_Store::set_size(size_t n) {
    _pets.resize(n);
}

size_t Pet_Store::get_size() const {
    return _pets.size();
}

void Pet_Store::clear() {
    _pets.clear();
}

void Pet_Store::populate_with_n_random_pets(size_t n) {
    Pet::get_n_pets(n, _pets, 7);
    _sort_order = BY_ID;
}

bool Pet_Store::_id_compare(const Pet& p1, const Pet& p2) {
    return p1.get_id() < p2.get_id();
}

bool Pet_Store::_name_compare(const Pet& p1, const Pet& p2) {
    return p1.get_name() < p2.get_name();
}

void Pet_Store::_sort_pets_by_id() {
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_id_compare);
    _sort_order = BY_ID;
}
                                                                                      
void Pet_Store::_sort_pets_by_name() {
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_name_compare);
    _sort_order = BY_NAME;
}

bool Pet_Store::find_pet_by_id_lin(long id, Pet& pet) {
    for(size_t i = 0; i < _pets.size(); i++){
        if(_pets[i].get_id() == id){
            pet = _pets[i];
            return true;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_name_lin(string name, Pet& pet) {
    for(size_t i = 0; i < _pets.size(); i++){
        if(_pets[i].get_name() == name){
            pet = _pets[i];
            return true;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_id_bin(long id, Pet& pet) {
    if(_sort_order != BY_ID){
        _sort_pets_by_id();
    }
    int top = 0;
    int bott = _pets.size();
    while(top <= bott){
        int mid = top + (bott-top)/2;
        
        if(_pets[mid].get_id() == id){
            pet = _pets[mid];
            return true;
        }
        if(_pets[mid].get_id() < id){
            top = mid + 1;
        } else {
            bott = mid - 1;
        }
    }
    return false;
}

// When this method is called, the _pets[] vector must be sorted in
// lexicographic non-descending order by _name. If it is not already,
// then it will be resorted.
bool Pet_Store::find_pet_by_name_bin(string name, Pet& pet) {
    if(_sort_order != BY_NAME){
        _sort_pets_by_name();
    }
    int top = 0;
    int bott = _pets.size();
    while(top <= bott){
        int mid = top + (bott-top)/2;
        
        if(_pets[mid].get_name() == name){
            pet = _pets[mid]; 
            return true;
        }
        if(_pets[mid].get_name() < name){
            top = mid + 1;
        } else {
            bott = mid - 1;
        }
    }
    return false;
}

// Return a string representation of the pets with indexes n1 through n2
// inclusive, exclusive of non-existent indices
// Each pet is on a line by itself.
string Pet_Store::to_string(size_t n1, size_t n2) {
    string return_value = "";
    for(size_t i = n1; i <= n2; i++){
        return_value += _pets[i].to_string() + "\n";
    }
    return return_value;
}

// int main(){
//     Pet_Store store;
//     store.set_size(100);
//     store.populate_with_n_random_pets(100);
//     Pet pet("zulu",3,14);
//     store.find_pet_by_id_bin(28, pet);
// }