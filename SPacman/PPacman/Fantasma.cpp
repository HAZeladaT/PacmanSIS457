#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma() {
	posicionX = 100;
	posicionY = 100;
	velocidad = 1;
	velocidadPatron = 5;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;
}


void Fantasma::move()
{

	// Mover el fantasma a la izquierda o derecha
	posicionX += velocidad;

	// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
	if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
	{
		// Mover fantasma atras
		posicionX -= velocidad;
	}

	// Mover el fantasma arriba o abajo
	posicionY += velocidad;

	// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
	if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	{
		// Mover fantasma atras
		posicionY -= velocidad;
	}
}

void Fantasma::render()
{
	// Color primario de la imagen del fantasma
	//SDL_SetColorKey(screenSurface, SDL_TRUE, SDL_MapRGB(fantasmaSurface->format, 0, 0, 0));

	SDL_Texture* nuevaTextura = NULL;

	nuevaTextura = SDL_CreateTextureFromSurface(renderer, fantasmaSurface);
	if (nuevaTextura == NULL)
	{
		cout << "No se puede crear una textura a partir de fantasmaSurface, SDL Error: " << SDL_GetError() << endl;
	}
	else
	{
		// Obtener dimension de la imagen
		ancho = fantasmaSurface->w;
		alto = fantasmaSurface->h;
	}

	/*SDL_Rect* clip = nullptr;
	double angle = 0.0;
	SDL_Point* center = nullptr;
	SDL_RendererFlip flip = SDL_FLIP_NONE;*/

	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

	// Establecer las dimensionces del recorte para remderizar
	/*if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}*/

	// Renderizar en la pantalla
	//SDL_RenderCopyEx(renderer, nuevaTextura, clip, &renderQuad, angle, center, flip);
	SDL_RenderCopyEx(renderer, nuevaTextura, nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
}