#include <iostream>
#include <stdexcept>

class MatrixA {
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
	MatrixA() = default;

	MatrixA(size_t r, size_t c) : data(nullptr), rows(r), cols(c) {
		allocateMemory(rows, cols);
	}

	~MatrixA() {
    freeMemory();
  }

  MatrixA& operator=(const MatrixA& other) {
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

  void resize(size_t newRows, size_t newCols) {
    MatrixA temp(newRows, newCols);
    size_t minRows = std::min(rows, newRows);
    size_t minCols = std::min(cols, newCols);

    for (size_t i = 0; i < minRows; ++i) {
      for (size_t j = 0; j < minCols; ++j) {
        temp.data[i][j] = data[i][j];
      }
    }
    *this = std::move(temp);
  }

};

int main() {
  
}