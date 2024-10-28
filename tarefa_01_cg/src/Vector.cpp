#include "Vector.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

Vector Vector::operator-(const Vector& v) const {
    return {x - v.x, y - v.y, z - v.z};
}

Vector Vector::operator+(const Vector& v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vector Vector::operator*(float s) const {
    return {x * s, y * s, z * s};
}

float Vector::dot(const Vector& v) const {
    return x * v.x + y * v.y + z * v.z;
}

// Evita calculos custosos onde não é neceśsario tirar a raiz
float Vector::lengthSquared() const {
    return x * x + y * y + z * z;
}

float Vector::length() const {
    return std::sqrt(lengthSquared());
}

Vector Vector::normalize() const {
    float len = length();
    return (len > 0.0f) ? *this * (1.0f / len) : Vector{0.0f, 0.0f, 0.0f};
}
