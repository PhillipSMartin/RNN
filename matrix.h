#pragma once
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <cmath>

class Matrix {
    private:
        unsigned int rows_;
        unsigned int cols_;
        double* data_;

        double get_max_element() const;
        double get_element_width( int precision ) const;

    public:
        Matrix(unsigned int rows, unsigned int cols);
        Matrix(const Matrix& other);
        ~Matrix();

        unsigned int rows() const { return rows_; }
        unsigned int cols() const { return cols_; }

        double get( unsigned int row, unsigned int col ) const; 
        void set( unsigned int row, unsigned int col, double value ); 
        Matrix dot_product( const Matrix& other ); 
        Matrix append( const Matrix& other );

        Matrix operator *( const Matrix& other ) {
            return dot_product( other );
        }   

        void print( std::ostream& os, int precision = 2 ) const;
};

    