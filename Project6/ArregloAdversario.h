#pragma once
#include"Adversario.h"

class ArregloAdversario {
private:
	Adversario **aadv;
	int n;
public:
	ArregloAdversario() {
		n = 0;
		aadv = new Adversario*[n];
	}
	~ArregloAdversario() {

	}
	void agregar_a(Adversario *nuevo) {
		
		Adversario **aux = new Adversario*[n + 1];
		for (int i = 0; i < n; i++) {
			aux[i] = aadv[i];
		}
		aux[n] = nuevo;
		n = n + 1;
		if (aadv != nullptr)
			delete[]aadv;
		aadv = aux;
	}
	void eliminar_a(int pos){
		Adversario** aux = new Adversario *[n - 1];

		for (int i = 0; i < pos; i++)
			aux[i] = aadv[i];

		for (int j = pos; j < n - 1; j++)
			aux[j] = aadv[j + 1];

		delete aadv[pos];
		n--;
		aadv = aux;
	}
	void mover(Graphics ^g, bool a) {
		for (int i = 0; i < n; i++) {
			aadv[i]->mover(g, a);
		}
	}
	void mostrar(Graphics ^g, Bitmap ^img) {
		for (int i = 0; i < n; i++) {
			aadv[i]->mostrar(g, img);
		}
	}
	void mostrar_obj(Graphics ^g, Bitmap ^img, bool a) {
		for (int i = 0; i < n; i++) {
			aadv[i]->mostrar_obj(g, img, a);
		}
	}
	int get_cantidad()
	{
		return n;
	}
	Adversario* get_adversario(int i)
	{
		return aadv[i];
	}
	
};