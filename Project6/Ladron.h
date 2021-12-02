#pragma once
#include"Entidad.h"

class Ladron :public Entidad {
private:
	int ix;
	Movimiento iy;
public:
	Ladron(int px, int py, int pdx, int pdy) {
		x = px; y = py;
		ix = 0;
		iy = Movimiento::Izquierda;
		dx = pdx; dy = pdy;
	}
	~Ladron() {

	}
	void mover(Graphics ^g) {
		x = x + dx;
		y = y + dy;
		if (x + dx<0 || x + dx + W>g->VisibleClipBounds.Width)
			dx = dx * -1;
		if (y + dy<0 + 90 || y + dy + H>g->VisibleClipBounds.Height)
			dy = dy * -1;
		if (dx < 0)
			iy = Izquierda;
		if (dx > 0)
			iy = Derecha;
	}
	void mostrar(Graphics ^g, Bitmap ^img) {
		W = img->Width / 4;
		H = img->Height / 4;

		Rectangle corte = Rectangle(ix*W, iy*H, W, H);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		if (iy == Abajo || iy == Izquierda || iy == Derecha || iy == Arriba)
			ix = (ix + 1) % 4;
		if (dx == 0 && dy == 0 && (iy == Abajo || iy == Izquierda || iy == Derecha || iy == Arriba))
			ix = 0;

	}
	void set_movimiento(Movimiento iy) {
		this->iy = iy;
	}
	Movimiento get_movimiento() {
		return iy;
	}
};