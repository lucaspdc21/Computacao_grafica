#include "Sphere.h"

Sphere::Sphere(float radius, const Vector& center) : radius(radius), center(center) {}

bool Sphere::intersects(const Ray& ray) const {
    Vector w = ray.origin - center;

    // Coeficientes
    float a = ray.direction.dot(ray.direction);          // A = d·d
    float b = 2 * w.dot(ray.direction);                  // B = 2 * w·d
    float c = w.dot(w) - radius * radius;                // C = ||w||^2 - r^2

    // Discriminante
    float discriminant = b * b - 4 * a * c;

    // Verifica se o discriminante é não negativo
    return discriminant >= 0;
}
