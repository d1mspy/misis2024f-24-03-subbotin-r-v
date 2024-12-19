#include <iostream>
#include <stdexcept>

class Matrix {
private:
  float** data {nullptr};
  size_t rows {0};
  size_t cols {0};

  void freeMemory() {
    if (data) {
      for (size_t i = 0; i < rows; ++i) {
        delete[] data[i];
      }
    	delete[] data;
    	data = nullptr;
    }
  }

  void allocateMemory(size_t newRows, size_t newCols) {
    data = new float*[newRows];
    for (size_t i = 0; i < newRows; ++i) {
      data[i] = new float[newCols]{};
    }
  }

public:
	Matrix() = default;

	Matrix(size_t r, size_t c) : data(nullptr), rows(r), cols(c) {
		allocateMemory(rows, cols);
	}

	~Matrix() {
    freeMemory();
  }

  Matrix& operator=(const Matrix& other) {
    if (this != &other) {
      freeMemory();
      rows = other.rows;
      cols = other.cols;
      allocateMemory(rows, cols);
      for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
          data[i][j] = other.data[i][j];
        }
      }
    }
    return *this;
  }

};

int main() {
  
}