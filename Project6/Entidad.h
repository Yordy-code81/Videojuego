#pragma once
#include<iostream>
#include<conio.h>
using namespace System;
using namespace System::Drawing;

enum Movimiento { Abajo, Izquierda, Derecha, Arriba };

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int W, H;

public:

	void set_x(int x) {
		this->x = x;
	}
	void set_y(int y) {
		this->y = y;
	}
	void set_dx(int dx) {
		this->dx = dx;
	}
	void set_dy(int dy) {
		this->dy = dy;
	}
	void set_W(int W) {
		this->W = W;
	}
	void set_H(int H) {
		this->H = H;
	}

	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	int get_dx() {
		return dx;
	}
	int get_dy() {
		return dy;
	}
	int get_W() {
		return W;
	}
	int get_H() {
		return H;
	}

	Rectangle Area() {
		return Rectangle(x, y, W+20, H+10);
	}

	void mostrar(Graphics ^g, Bitmap ^img) {
		g->FillRectangle(Brushes::Black, Area());
	}
};