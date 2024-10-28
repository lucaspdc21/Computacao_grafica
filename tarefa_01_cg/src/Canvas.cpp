#include "Canvas.h"


Canvas::Canvas(int wJanela, int hJanela, int dJanela, int nLin, int nCol)
    : wJanela(wJanela), hJanela(hJanela), dJanela(dJanela), nLin(nLin), nCol(nCol) {

    Dx = static_cast<float>(wJanela) / nCol;
    Dy = static_cast<float>(hJanela) / nLin;
}

std::unique_ptr<int[]> Canvas::raycast(const Vector& observer, const Sphere& sphere) {
    auto canvas = std::make_unique<int[]>(nLin * nCol);
    std::fill_n(canvas.get(), nLin * nCol, 0);

    for (int l = 0; l < nLin; l++) {
        float y = (hJanela / 2.0f) - (Dy / 2.0f) - (l * Dy);
        for (int c = 0; c < nCol; c++) {
            float x = -(wJanela / 2.0f) + (Dx / 2.0f) + (c * Dx);
            Vector windowPoint(x, y, -dJanela);
            Ray ray(observer, windowPoint - observer);
            canvas[l * nCol + c] = sphere.intersects(ray) ? 1 : 0; // 1 se intercepta, 0 caso contrário
        }
    }

    return canvas;
}
