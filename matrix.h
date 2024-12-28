#pragma once

#include <iostream>
#include <vector>

class Matrix {
    private:
        unsigned int rows_;
        unsigned int cols_;
        double* data_{ nullptr };

        double get_max_element() const;
        double get_element_width( int precision ) const;

    public:
        Matrix() : Matrix{0, 0} {}
        Matrix(unsigned int rows, unsigned int cols, const std::vector<double>& data = {});
        Matrix(const Matrix& other);
        ~Matrix();

        unsigned int rows() const { return rows_; }
        unsigned int cols() const { return cols_; }

        double get( unsigned int row, unsigned int col ) const; 
        void set( unsigned int row, unsigned int col, double value ); 
        void set_row( unsigned int row, const std::vector<double>& values );
        void set_col( unsigned int col, const std::vector<double>& values );
        void set_all( const std::vector<double>& values );

        Matrix dot_product( const Matrix& other ) const; 
        Matrix append_rowwise( const Matrix& other ) const;
        Matrix append_columnwise( const Matrix& other ) const;

        Matrix operator *( const Matrix& other ) const {
            return dot_product( other );
        }   
        void operator =( const Matrix& other );
        static Matrix ReLU( const Matrix& input );

        void print( std::ostream& os, int precision = 0 ) const;
};

    