#ifndef MYSTRING_HPP
#define MYSTRING_HPP

class MyString{
private:
    char* data;
    int get_length(const char* str) const;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();
    char get(int i) const;
    void set(int i, char c);
    void set_new_string(const char* str);
    void print() const;
    void read_line();
};

#endif