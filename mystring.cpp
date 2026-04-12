#include <iostream>
#include "mystring.hpp"

int MyString::get_length(const char* str) const{
    if (!str){
        return 0;
    }
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

MyString::MyString(){
    data = new char[1];
    data[0] = '\0';
}

MyString::MyString(const char* str){
    int len = get_length(str);
    data = new char[len + 1];
    for(int i = 0; i < len; i++){
        data[i] = str[i];
    }
    data[len] = '\0';
}

MyString::MyString(const MyString& other){
    int len = get_length(other.data);
    data = new char[len +  1];
    for(int i = 0; i <= len; i++){
        data[i] = other.data[i];
    }
}

MyString::~MyString(){
    delete[] data;
}

void MyString::set_new_string(const char* str){
    delete[] data;
    int len = get_length(str);
    data = new char[len + 1];
    for(int i = 0; i  <= len; i++){
        data[i] = str[i];
    }
}

char MyString::get(int i) const{
    return data[i];
}

void MyString::set(int i, char c){
    data[i] = c;
}

void MyString::print() const{
    std::cout << data << std::endl;
}

void MyString::read_line(){
    delete[] data;
    std::string temp;
    std::getline(std::cin, temp);

    int len = temp.length();
    data = new char[len + 1];
    for(int i = 0; i <= len; i++){
        data[i] = temp[i];
    }
    data[len] = '\0';
}