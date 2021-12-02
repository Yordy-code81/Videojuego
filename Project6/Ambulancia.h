#pragma once
#include"Entidad.h"

class Ambulancia :public Entidad {
private:
	int ix;
	Movimiento iy;
public:
	Ambulancia() {
		x = 2;
		y = 300;
		dx = 0;
		dy = 0;
		ix = 0;
		iy = Derecha;
	}
	~Ambulancia() {

	}
	void mover(Graphics ^g) {
	
		if (x + dx >= 0 && x + W + dx < g->VisibleClipBounds.Width)
			x = x + dx;
		if (y + dy >= 0 + 90 && y + H + dy < g->VisibleClipBounds.Height)
			y = y + dy;
	}
	void mostrar(Graphics ^g, Bitmap ^img) {
		W = img->Width;
		H = img->Height / 4;

		Rectangle corte = Rectangle(ix*W, iy*H, W, H);
		Rectangle zoom = Rectangle(x, y, W * 3, H * 3);
		g->DrawImage(img, zoom, corte, GraphicsUnit::Pixel);

		if (iy == Abajo || iy == Izquierda || iy == Derecha || iy == Arriba)
			ix = (ix + 1) % 1;
		if (dx == 0 && dy == 0 && (iy == Abajo || iy == Izquierda || iy == Derecha || iy == Arriba))
			ix = 0;
	}
	void set_movimiento(Movimiento iy) {
		this->iy = iy;
	}
};