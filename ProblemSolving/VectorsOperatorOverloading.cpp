#include <iostream>
using namespace std;
#include "VectorsOperatorOverloading.h"

Vector2D &Vector2D::operator+(Vector2D &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2D &Vector2D::operator-(Vector2D &other)
{

    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2D &Vector2D::operator*(Vector2D &other)
{
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

ostream &Vector2D::display(ostream &out = cout)
{
    out << this->x << endl;
    out << this->y;
    return out;
}

int main()
{
    Vector2D v1(34, 5), v2(67, 8), v3(12, 4), v4, v5;
    v4 = v1 + v2;
    v5 = v2 - v3;
    v1 = v1 * v2;
    v4.display();
    cout << endl;
    v5.display();
    cout << endl;
    v1.display();
    cout << endl;
    
    return 0;
}