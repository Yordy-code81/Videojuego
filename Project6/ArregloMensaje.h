#pragma once
#include"Mensaje.h"

class ArregloMensaje {
private:
	Mensaje **amsg;
	int n;
public:
	ArregloMensaje() {
		n = 0;
		amsg = new Mensaje*[n];
	}
	~ArregloMensaje() {

	}
	void agregar_m(Mensaje *nuevo) {
		Mensaje **aux = new Mensaje*[n + 1];
		for (int i = 0; i < n; i++) {
			aux[i] = amsg[i];
		}
		aux[n] = nuevo;
		n = n + 1;
		if (amsg != NULL)
			delete amsg;
		amsg = aux;
	}
	void eliminar_m(int pos){
		Mensaje** aux = new Mensaje *[n - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = amsg[i];

		for (int j = pos; j < n - 1; j++)
			aux[j] = amsg[j + 1];

		delete amsg[pos];
		n--;
		amsg = aux;
	}
	void mover() {
		for (int i = 0; i < n; i++) {
				amsg[i]->mover_mensaje();
		}
	}
	void mostrar(Graphics ^g, Bitmap ^img) {
		for (int i = 0; i < n; i++) {
			amsg[i]->mostrar_mensaje(g, img);
		}
	}
	Mensaje* get_mensaje(int pos)
	{
		return amsg[pos];
	}
	int get_cantidad()
	{
		return n;
	}
};