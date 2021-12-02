#pragma once
#include"Entidad.h"
#include"ArregloMensaje.h"

class Jugador : public Entidad {
private:
	ArregloMensaje *mensajes;
	int ix;
	Movimiento iy;
	int vidas;
public:
	Jugador() {
		x = 2;
		y = 150;
		ix = 0;
		iy = Movimiento::Derecha;
		dx = dy = 0;
		mensajes = new ArregloMensaje();
		vidas = 6;
	}
	void mover(Graphics ^g) {
		if (x + dx >= 0 && x + W + dx < g->VisibleClipBounds.Width)
			x = x + dx;
		if (y + dy >= 0 + 90 && y + H + dy < g->VisibleClipBounds.Height)
			y = y + dy;
		mensajes->mover();
	}
	void mostrar(Graphics ^g, Bitmap ^img) {
		W = img->Width / 3;
		H = img->Height / 4;

		Rectangle corte = Rectangle(ix*W, iy*H, W, H);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		if (iy == Abajo || iy == Izquierda || iy == Derecha || iy == Arriba)
			ix = (ix + 1) % 3;
		if (dx == 0 && dy == 0 && (iy == Abajo || iy == Izquierda || iy == Derecha || iy == Arriba))
			ix = 0;

	}
	void set_movimiento(Movimiento iy) {
		this->iy = iy;
	}
	void mostrar_msg(Graphics^ g, Bitmap^ img){
		mensajes->mostrar(g, img);
	}
	void Disparo(){
		int vx = 0, vy = 0;
		if (iy == Abajo)
			vy = 20;
		else if (iy == Arriba)
			vy = -20;
		else if (iy == Izquierda)
			vx = -20;
		else if (iy == Derecha)
			vx = 20;
		Mensaje* msj = new Mensaje(x, y, vx, vy);
		mensajes->agregar_m(msj);
	}
	ArregloMensaje* get_mensajes(){
		return mensajes;
	}
	void set_vidas(int n) {
		vidas = n;
	}
	int get_vidas() {
		return vidas;
	}
};