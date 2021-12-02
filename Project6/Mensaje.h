#pragma once
#include"Entidad.h"

class Mensaje:public Entidad {
public:
	Mensaje(int x,int y,int dx,int dy) {
		this->x = x; this->y = y;
		this->dx = dx; this->dy = dy;
	}
	~Mensaje() {

	}
	void mover_mensaje() {
		x = x + dx;
		y = y + dy;
	}
	Rectangle area() {
		return Rectangle(x, y, W, H);
	}
	void mostrar_mensaje(Graphics ^g, Bitmap ^img) {
		W = img->Width;
		H = img->Height;

		g->DrawImage(img, x, y, W, H);
	}
};