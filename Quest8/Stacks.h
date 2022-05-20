// Student ID: 20447032

#ifndef Stacks_h
#define Stacks_h

#include <vector>
#include <sstream>

class Stack_Int {
private:
    

public:
    std::vector<int> _data;
    // No explicit constructor or destructor
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        if(_data.size() == 0){
            return true;
        } else {
            return false;
        }
    }

    void push(int val) {
        _data.push_back(val);
    }

    int top(bool& success) const {
        if(is_empty()){
            success = false;
            return 0;
        } else {
            success = true;
            return _data.back();
        }
    }

    bool pop() {
        if(is_empty()){
            return false;
        } else {
            _data.pop_back();
            return true;
        }
    }

    bool pop(int& val) {
        if(is_empty()){
            return false;
        } else {
            val = _data.back();
            _data.pop_back();
            return true;
        }
    }

    std::string to_string() const {
        size_t length = _data.size();
        std::string result = "Stack (" + std::to_string(length) + " elements):\n";
        size_t i;
        int count = 0;
        for(i = length -1 ; i >= 0; i--){
            count ++;
            result += std::to_string(_data.at(i)) + "\n";
            if(count  == 10 || i == 0){
                break;
            }
        }
        if(count == 10){
            result += "...\n";
        }
        result += "Elements, if listed above, are in increasing order of age.";
        return result;
    }

    // Don't remove the following line
    friend class Tests;
};


class Stack_String {

private:
    

public:
    std::vector<std::string> _data;
    // No explicit constructor or destructor
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        if(_data.size() == 0){
            return true;
        } else {
            return false;
        }
    }

    void push(std::string val) {
        _data.push_back(val);
    }

    std::string top(bool& success) const {
        if(is_empty()){
            success = false;
            return 0;
        } else {
            success = true;
            return _data.back();
        }
    }

    bool pop() {
        if(is_empty()){
            return false;
        } else {
            _data.pop_back();
            return true;
        }
    }

    bool pop(std::string& val) {
        if(is_empty()){
            return false;
        } else {
            val = _data.back();
            _data.pop_back();
            return true;
        }
    }

    std::string to_string() const {
        size_t length = _data.size();
        std::string result = "Stack (" + std::to_string(length) + " elements):\n";
        size_t i;
        int count = 0;
        for(i = length -1 ; i >= 0; i--){
            count ++;
            result += _data.at(i) + "\n";
            if(count  == 10 || i == 0){
                break;
            }
        }
        if(count == 10){
            result += "...\n";
        }
        result += "Elements, if listed above, are in increasing order of age.";
        return result;
    }

    // Don't remove the following line
    friend class Tests;
};

#endif /* Stacks_h */
