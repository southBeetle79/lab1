class Matrix{
private:
    int rows;
    int cols;
    double* data;
public:
    Matrix(int n);
    Matrix(int m, int , double fill_value = 0);
    Matrix(const Matrix& other);
    ~Matrix();

    double get(int n , int j) const;
    void set(int i, int j, double value);
    int get_height() const{return rows;}
    int get_width() const{return cols;}

    void negate();
    void add_in_place(const Matrix& other);
    Matrix multiply(const Matrix& other) const;
};