#pragma once
#include"Entidad.h"
#include"ArregloMensaje.h"

class Adversario :public Entidad {
private:
	int ix;
	Movimiento iy;
	ArregloMensaje *objetos;
public:
	Adversario(int px,int py,int pdx,int pdy) {
		x = px; y = py;
		ix = 0;
		iy = Movimiento::Izquierda;
		dx = pdx; dy = pdy;
		objetos = new ArregloMensaje();
	}
	~Adversario() {

	}
	void mover(Graphics ^g, bool a) {
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
		if (a == true) {
			if (rand() % 150 == 0)
				disparo();
			objetos->mover();
		}
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
	void mostrar_obj(Graphics^ g, Bitmap^ img, bool a) {
		if (a == true)
			objetos->mostrar(g, img);
	}
	void set_movimiento(Movimiento iy) {
		this->iy = iy;
	}
	Movimiento get_movimiento() {
		return iy;
	}
	void disparo()
	{
		int vx = 0, vy = 0;
		if (iy == Izquierda)
			vx = -10;
		else if (iy == Derecha)
			vx = 10;
		Mensaje* ob = new Mensaje(x, y, vx, vy);
		objetos->agregar_m(ob);
	}
	ArregloMensaje *get_obj() {
		return objetos;
	}
};