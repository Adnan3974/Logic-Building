#ifndef VECTOR_H
#define VECTOR_H

class Vector2D
{
    float x, y;

public:
    Vector2D(float n1 = 0, float n2 = 0) : x(n1), y(n2) {};

    Vector2D &operator+(Vector2D &other);
    
    Vector2D &operator-(Vector2D &other);

    Vector2D &operator*(Vector2D &other);

    ostream& display(ostream& out);
};

#endif