#define SDL_MAIN_HANDLED

#include <iostream>
#include <cmath>
#include <memory>
#include "SDL.h"
#include "Vector.h"
#include "Sphere.h"
#include "Canvas.h"
#include "Display.h"

SDL_Color bgColor = {100, 100, 100, 255}; // Cor de fundo cinza
SDL_Color esfColor = {255, 0, 0, 255}; // Cor da esfera vermelha

int main() {

    const float wJanela = 2.0f; // Largura da janela em metros
    const float hJanela = 2.0f; // Altura da janela em metros
    const float dJanela = 1.0f; // Distância da janela em metros
    const int nCol = 700; // Número de colunas (px na largura)
    const int nLin = 700; // Número de linhas (px na altura)
    const float rEsfera = 0.5f; // Raio da esfera em metros

    Sphere sphere(rEsfera, Vector(0.0f, 0.0f, -(dJanela + rEsfera)));

    // A origem do sistema de coordenadas (olho do pintor)
    Vector origin(0.0f, 0.0f, 0.0f);

    // Inicializa a janela de renderização
    Display renderer(static_cast<int>(nCol), static_cast<int>(nLin));
    Canvas canvas(wJanela, hJanela, dJanela, nLin, nCol);

    auto display = canvas.raycast(origin, sphere);

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        renderer.clear();

        // Loop para desenhar a esfera no canvas
        for (int i = 0; i < nLin; i++) {
            for (int j = 0; j < nCol; j++) {
                SDL_Color color = (display[i * nCol + j] == 0) ? bgColor : esfColor;
                renderer.drawPoint(j, i, color); // Desenha o ponto na posição (j, i)
            }
        }

        renderer.present();
    }

    return 0;
}
