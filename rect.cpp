#include <iostream>
#include "rect.hpp"
using namespace std;

//конструктор по умолчанию
Rect::Rect(): left(0), right(0), top(0), bottom(0){
    cout << "Default Constructor at"<< this  << endl;
}

Rect::Rect(int l, int r, int t, int b): left(l), right(r), top(t), bottom(b){
    cout << "Parameterized construction at" << this << endl;
}

//деструктор
Rect::~Rect(){
    cout << "Destructor at " << this << endl;
}

Rect::Rect(const Rect& other): left(other.left), right(other.right), top(other.top), bottom(other.bottom){
    cout << "Copy construction at" << this << "(from " << &other << ")" << endl;
}

int Rect::get_left() const{return left;}
int Rect::get_right() const{return right;}
int Rect::get_top() const{return top;}
int Rect::get_bottom() const{return bottom;}

void Rect::set_all(int l, int r, int t, int b){
    left = l;
    right = r;
    top = t;
    bottom = b;
}

void Rect::inflate(int amount){
    left -= amount;
    right += amount;
    top -= amount;
    bottom += amount;
}

void Rect::inflate(int dw, int dh){
    left -= dw;
    right += dw;
    top -= dh;
    bottom += dh;
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom){
    left -= d_left;
    right += d_right;
    top -= d_top;
    bottom += d_bottom;
}

void Rect::move(int dx, int dy){
    left += dx;
    right += dx;
    top += dy;
    bottom += dy;
}

Rect bounding_rect(Rect r1, Rect r2){
    int left = min(r1.get_left(), r2.get_left());
    int right = max(r1.get_right(), r2.get_right());
    int top = min(r1.get_top(), r2.get_top());
    int bottom = max(r1.get_bottom(), r2.get_bottom());

    return Rect(left, right, top, bottom);
}

void print_rect(Rect &r){
    cout << "Rect L=" << r.get_left() << ", R = " << r.get_right() << ", T = " << r.get_top() << ", B = "<< r.get_bottom() << endl;
}

int Rect::get_width() const{
    return right - left;
}

int Rect::get_height() const{
    return bottom - top;
}

int Rect::get_square() const{
    return get_width() * get_height();
}

void Rect::set_width(int w){
    right = left + w;
}

void Rect::set_height(int h){
    bottom = top + h;
}