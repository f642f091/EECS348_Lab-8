#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Default constructor for an empty matrix
Matrix::Matrix() : size(0), data() {}

// Constructor to initialize NxN matrix filled with 0s
Matrix::Matrix(size_t N) : size(N), data(N, std::vector<int>(N, 0)) {}

// Constructor with input data
Matrix::Matrix(const std::vector<std::vector<int>>& input) : size(input.size()), data(input) {}

// Returns matrix size (N)
size_t Matrix::get_size() const {
    return size;
}

// Get value at position (i, j)
int Matrix::get_value(size_t i, size_t j) const {
    if (i >= size || j >= size) throw std::out_of_range("Index out of bounds");
    return data[i][j];
}

// Set value at position (i, j)
void Matrix::set_value(size_t i, size_t j, int value) {
    if (i >= size || j >= size) throw std::out_of_range("Index out of bounds");
    data[i][j] = value;
}

// Print entire matrix to stdout
void Matrix::print_matrix() const {
    for (const auto& row : data) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Matrix addition (element-wise)
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Matrix multiplication (dot product)
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            for (size_t k = 0; k < size; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Sum of main diagonal (top-left to bottom-right)
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i][i];
    }
    return sum;
}

// Sum of secondary diagonal (top-right to bottom-left)
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i][size - 1 - i];
    }
    return sum;
}

// Swap two rows i and j
void Matrix::swap_rows(size_t i, size_t j) {
    if (i >= size || j >= size) throw std::out_of_range("Row index out of bounds");
    std::swap(data[i], data[j]);
}

// Swap two columns c1 and c2
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size) throw std::out_of_range("Column index out of bounds");
    for (std::size_t row = 0; row < size; ++row) {
        std::swap(data[row][c1], data[row][c2]);
    }
}

// Static method to load a matrix from a file
Matrix Matrix::load_matrix_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file.");
    }

    size_t n;
    file >> n;
    Matrix matrix(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int val;
            file >> val;
            matrix.set_value(i, j, val);
        }
    }
    return matrix;
}
