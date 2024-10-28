#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"

class Sphere {
    public:
        float radius;
        Vector center;

        Sphere(float radius, const Vector& center);
        bool intersects(const Ray& ray) const;
};

#endif // SPHERE_H
