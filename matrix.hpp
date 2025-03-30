#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstddef>
#include <vector>
#include <iostream>

class Matrix {
public:
    // declare attributes and functions
    Matrix(); // default constructor
    Matrix(std::size_t N);
    Matrix(const std::vector<std::vector<int>>& nums);

    static Matrix load_matrix_from_file(const std::string& filename);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;

    
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    std::size_t get_size() const;

    // Trace
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;

    // Swapping
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);


    void print_matrix() const;

private:
    std::size_t size;
    std::vector<std::vector<int>> data;
};

#endif // __MATRIX_HPP__
