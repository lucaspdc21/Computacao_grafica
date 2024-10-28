#include "Ray.h"

Ray::Ray(const Vector& origin, const Vector& direction)
    : origin(origin), direction(direction.normalize()) {}
