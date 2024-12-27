#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

class Matrix {
    private:
        unsigned int rows_;
        unsigned int cols_;
        double* data_;

        double get_max_element() const;
        double get_element_width( int precision ) const;

    public:
        Matrix(unsigned int rows, unsigned int cols, double* data = nullptr);
        Matrix(const Matrix& other);
        ~Matrix();

        unsigned int rows() const { return rows_; }
        unsigned int cols() const { return cols_; }

        double get( unsigned int row, unsigned int col ) const; 
        void set( unsigned int row, unsigned int col, double value ); 
        void set_row( unsigned int row, const std::vector<double>& values );
        void set_col( unsigned int col, const std::vector<double>& values );

        Matrix dot_product( const Matrix& other ); 
        Matrix append_rowwise( const Matrix& other );
        Matrix append_columnwise( const Matrix& other );

        Matrix operator *( const Matrix& other ) {
            return dot_product( other );
        }   
        Matrix operator =( const Matrix& other );
        static Matrix ReLU( const Matrix& input );

        void print( std::ostream& os, int precision = 0 ) const;
};

    