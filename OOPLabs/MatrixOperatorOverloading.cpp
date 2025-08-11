#include <iostream>
using namespace std;
#include "MatrixOperatorOverloading.h"

Matrix &Matrix::operator+(const int n)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] += n;
        }
    }
    return *this;
}

Matrix &Matrix::operator-(const int n)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] -= n;
        }
    }
    return *this;
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
        return *this;
    if (rows != other.rows || cols != other.cols)
    {
        for (int i = 0; i < rows; ++i)
        {
            delete matrix[i];
        }
        delete[] matrix;
        rows = other.rows;
        cols = other.cols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; ++i)
        {
            matrix[i] = new int[cols];
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix &other)
{
    bool result = true;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != other.matrix[i][j])
            {
                result = false;
            }
        }
    }
    return result;
}

Matrix &Matrix::operator+(const Matrix &other)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            this->matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-(const Matrix &other)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

ostream &operator<<(ostream &out, const Matrix &m)
{
    for (int i = 0; i < m.rows; ++i)
    {
        for (int j = 0; j < m.cols; ++j)
        {
            out << m.matrix[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

int main()
{
    int rows = 3, cols = 3;
    int static_matrix1[rows][cols] = {{45, 6, 76}, {23, 4, 65}, {9, 12, 3}};
    int static_matrix2[rows][cols] = {{4, 46, 96}, {2, 41, 5}, {2, 1, 30}};
    int **matrix1 = new int *[rows];
    int **matrix2 = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix1[i][j] = static_matrix1[i][j];
            matrix2[i][j] = static_matrix2[i][j];
        }
    }

    Matrix m1(rows, cols, matrix1);
    Matrix m2(rows, cols, matrix2);

    m1 = m1 - 4;
    cout << m1;
    Matrix m3 = m1 + m2;
    cout << m3;
    for (int i = 0; i < rows; ++i)
    {
        delete matrix1[i];
        delete matrix2[i];
    }
    delete[] matrix1;
    delete matrix2;
}