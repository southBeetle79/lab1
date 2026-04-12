#include "matrix.hpp"

Matrix::Matrix(int n):rows(n), cols(n){
    data = new double[n*n];
    for (int i = 0; i < n;  i++){
        for( int j = 0; j < n; j++){
            data[i*n + j] = (i == j)? 1.0 : 0.0;
        }
    }
}

Matrix::Matrix(int m, int n, double fill_value): rows(m), cols(n){
    data = new double[m*n];
    for(int i = 0; i < m*n; i++){
        data[i] = fill_value;
    }
}

Matrix::Matrix(const Matrix& other):rows(other.rows), cols(other.cols){
    data = new double[rows*cols];
    for(int i = 0; i < rows*cols; i++){
        data[i] = other.data[i];
    }
}

Matrix::~Matrix(){
    delete[] data;
}

double Matrix::get(int i, int j) const{
    if(i >= rows || j >= cols);
    return data[i*cols+j];
}

void Matrix::set(int i, int j, double value){
    if(i >+ rows || j >= cols){
        throw "Index is empty";
    }
    data[i*cols+j] = value;
}

void Matrix::negate(){
    for(int i = 0; i < rows*cols; i++){
        data[i] = -data[i];
    }
}

void Matrix::add_in_place(const Matrix& other){
    if (rows != other.rows || cols != other.cols){
        throw "Dimensions must match";
    }
    for(int i = 0; i < rows*cols; i++){
        data[i] += other.data[i];
    }
}

Matrix Matrix::multiply(const Matrix& other) const{
    if (cols != other.rows){
        throw "Incompatible dimensions";
    }

    Matrix result(rows, other.cols, 0.0);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < other.cols; j++){
            double sum = 0.0;
            for(int k = 0; k < cols; k++){
                sum += this ->get(i, k)* other.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

