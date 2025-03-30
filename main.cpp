#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// Load matrix from a given file
Matrix load_matrix_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file.");
    }

    size_t n;
    file >> n;
    Matrix matrix(n);

    // Fill matrix with values from file
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int val;
            file >> val;
            matrix.set_value(i, j, val);
        }
    }

    return matrix;
}

int main(int argc, char* argv[]) {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    // Load matrix
    Matrix matrix = load_matrix_from_file(filename);

    std::cout << "Matrix loaded:\n";
    matrix.print_matrix();

    // Matrix addition
    std::cout << "\nMatrix + Matrix:\n";
    auto result_add = matrix + matrix;
    result_add.print_matrix();

    // Matrix multiplication
    std::cout << "\nMatrix * Matrix:\n";
    auto result_mul = matrix * matrix;
    result_mul.print_matrix();

    // Diagonal sums
    std::cout << "\nMajor Diagonal Sum: " << matrix.sum_diagonal_major() << "\n";
    std::cout << "Minor Diagonal Sum: " << matrix.sum_diagonal_minor() << "\n";

    // Swap rows
    matrix = load_matrix_from_file(filename);
    matrix.swap_rows(0, 1);
    std::cout << "\nAfter swapping rows 0 and 1:\n";
    matrix.print_matrix();

    // Swap columns
    matrix = load_matrix_from_file(filename);
    matrix.swap_cols(0, 1);
    std::cout << "\nAfter swapping cols 0 and 1:\n";
    matrix.print_matrix();

    // Set a value in matrix
    matrix = load_matrix_from_file(filename);
    matrix.set_value(0, 0, 999);
    std::cout << "\nAfter setting (0, 0) to 999:\n";
    matrix.print_matrix();

    return 0;
}
