#ifndef CANVAS_H
#define CANVAS_H

#include <memory>
#include "Sphere.h"

class Canvas {
    public:
        int wJanela, hJanela, dJanela;
        int nLin, nCol;
        float Dx, Dy;

        Canvas(int wJanela, int hJanela, int dJanela, int nLin, int nCol);
        std::unique_ptr<int[]> raycast(const Vector& observer, const Sphere& sphere);
};

#endif // CANVAS_H
