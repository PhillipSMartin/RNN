#include "matrix.h"

double Matrix::get_max_element() const {
    double _max_element = data_[0];
    for (unsigned int _i = 1; _i < rows_ * cols_; _i++) {
        if (data_[_i] > _max_element) {
            _max_element = data_[_i];
        }
    }
    return _max_element;
}

double Matrix::get_element_width( int precision ) const {
    return precision + 2 + std::floor( std::log10( get_max_element() ) );
}

Matrix::Matrix(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Invalid matrix dimensions");
    }
    rows_ = rows;
    cols_ = cols;
    data_ = new double[rows_ * cols_];
}

Matrix::Matrix(const Matrix& other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    data_ = new double[rows_ * cols_];
    for (unsigned int _i = 0; _i < rows_ * cols_; _i++) {
        data_[_i] = other.data_[_i];
    }
}

Matrix::~Matrix() {
    delete[] data_;
}

double Matrix::get( unsigned int row, unsigned int col ) const { 
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[row * cols_ + col]; 
}

void Matrix::set( unsigned int row, unsigned int col, double value ) {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Index out of range");
    }
    data_[row * cols_ + col] = value;
}

Matrix Matrix::dot_product( const Matrix& other ) {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("Matrices must have compatible dimensions");
    }
    Matrix _result(rows_, other.cols_);
    for (unsigned int _my_row = 0; _my_row < rows_; ++_my_row) {
        for (unsigned int _other_col = 0; _other_col < other.cols_; ++_other_col) {
            double _sum = 0;
            for (unsigned int _i = 0; _i < cols_; ++_i) {
                _sum += get(_my_row, _i) * other.get(_i, _other_col);
            }
            _result.set(_my_row, _other_col, _sum);
        }
    }
    return _result;
}

Matrix Matrix::append( const Matrix& other ) {
    if (rows_ != other.rows_) {
        throw std::invalid_argument("Matrices must have compatible dimensions");
    }
    Matrix _result(rows_, cols_ + other.cols_);
    for (unsigned int _my_row = 0; _my_row < rows_; ++_my_row) {
        for (unsigned int _my_col = 0; _my_col < cols_; ++_my_col) {
            _result.set(_my_row, _my_col, get(_my_row, _my_col));
        }
        for (unsigned int _other_col = 0; _other_col < other.cols_; ++_other_col) {
            _result.set(_my_row, cols_ + _other_col, other.get(_my_row, _other_col));
        }
    }
    return _result;
}

void Matrix::print( std::ostream& os, int precision /* = 2 */ ) const {
    os << std::fixed << std::setprecision( precision );  // Set 4 decimal places
    for (unsigned int _row = 0; _row < rows_; ++_row) {
        for (unsigned int _col = 0; _col < cols_; ++_col) {
            os << std::setw( get_element_width( precision ) ) << get(_row, _col) << " ";  // Set width to 12 characters
        }
        os << '\n';
    }
    os << std::endl;
}


