#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class Vector {
    public:
        float x, y, z;

        Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f);
        Vector operator-(const Vector& v) const;
        Vector operator+(const Vector& v) const;
        Vector operator*(float s) const;
        float dot(const Vector& v) const;
        float lengthSquared() const;
        float length() const;
        Vector normalize() const;
};

#endif // VECTOR_H
