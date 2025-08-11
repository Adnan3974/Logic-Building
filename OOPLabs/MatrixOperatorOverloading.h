#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
    int rows, cols;
    int **matrix;

public:
    Matrix(int r = 0, int c = 0, int **mat = nullptr) : rows(r), cols(c)
    {
        if (r > 0 && c > 0)
        {
            matrix = new int *[rows];
            for (int i = 0; i < rows; ++i)
            {
                matrix[i] = new int[cols];
            }
            if (mat != nullptr)
            {
                for (int i = 0; i < rows; ++i)
                {
                    for (int j = 0; j < cols; ++j)
                    {
                        matrix[i][j] = mat[i][j];
                    }
                }
            }
            else
                for (int i = 0; i < rows; ++i)
                {
                    for (int j = 0; j < cols; ++j)
                    {
                        matrix[i][j] = 0;
                    }
                }
        }

        else
            matrix = nullptr;
    };

    //  Destructor
    ~Matrix()
    {
        if (matrix != nullptr)
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }

    // Copy constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        if (rows > 0 && cols > 0)
        {
            matrix = new int *[rows];
            for (int i = 0; i < rows; ++i)
            {
                matrix[i] = new int[cols];
                for (int j = 0; j < cols; ++j)
                {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        else
        {
            matrix = nullptr;
        }
    }

    Matrix &operator+(const int);      // add int to the Matrix
    Matrix &operator=(Matrix const &); // Assign Matrix
    bool operator==(Matrix const &);   // equal Comparison
    Matrix &operator-(const int);      // subtract int from Matrix
    Matrix &operator+(Matrix const &); // Add two Matrices
    Matrix &operator-(Matrix const &); // Subtract two matrices
    friend ostream &operator<<(ostream &, const Matrix &);
};
#endif
