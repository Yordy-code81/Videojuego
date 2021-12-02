#pragma once
#include"ArregloAdversario.h"
#include"Jugador.h"
#include"Ambulancia.h"
#include"Policia.h"
#include"Ladron.h"
#include"time.h"

class Juego {
private:
	Jugador *jugador;
	ArregloAdversario *saludable;
	ArregloAdversario *asintomatico;
	ArregloAdversario *verde;
	ArregloAdversario *rojo;
	Ambulancia *ambulancia;
	Policia *policia;
	Ladron *ladron;
	int itv, seg, min;
	int puntos;
	bool a;
	
public:
	Juego() {
		jugador = new Jugador();
		saludable = new ArregloAdversario();
		asintomatico = new ArregloAdversario();
		verde = new ArregloAdversario();
		rojo = new ArregloAdversario();
		ambulancia = new Ambulancia();
		policia = new Policia();
		ladron = new Ladron(350 + rand() % 1000, 90 + rand() % 450, 2, 2);
		puntos = 0;
		itv = 0; seg = 60; min = 5;
		a = false;
	}
	~Juego() {
		delete jugador;
	}
	void set_a(bool pa) {
		a = pa;
	}
	void set_vidas(int v) {
		jugador->set_vidas(v);
	}
	int get_vidas() {
		return jugador->get_vidas();
	}
	void set_tiempo(int t) {
		min = t;
	}
	int get_tiempo() {
		return min;
	}
	int get_puntos() {
		return puntos;
	}
	int get_cantidad_verde() {
		return verde->get_cantidad();
	}
	int get_cantidad_rojo() {
		return rojo->get_cantidad();
	}
	int get_cantidad_saludable() {
		return saludable->get_cantidad();
	}
	int get_cantidad_asintomatico() {
		return asintomatico->get_cantidad();
	}
	void jugador_dx(int dx) {
		jugador->set_dx(dx);
	}
	void jugador_dy(int dy) {
		jugador->set_dy(dy);
	}
	void movimiento_jugador(Movimiento accion) {
		jugador->set_movimiento(accion);
	}
	void tiempo() {
		itv = itv + 100;
		if (itv == 1000) {
			itv = 0;
			seg--;
			if (seg == 0) {
				seg = 60;
				min--;
			}
		}
	}
	void mostrar_datos(Graphics ^g) {
		Font ^f = gcnew Font("Arial", 25);
		g->DrawString("Tiempo " + Convert::ToString(min - 1) + ":" + Convert::ToString(seg) + "    Vidas: " + Convert::ToString(jugador->get_vidas()) + "    Puntos: " + Convert::ToString(puntos), f, Brushes::Black, 150, 2);
	}
	void Colision_msg_salu(){
		ArregloMensaje* mensajes = jugador->get_mensajes();
		for (int m = 0; m < mensajes->get_cantidad(); m++)
			for (int a = 0; a < saludable->get_cantidad(); a++)
			{
				Mensaje* msj = mensajes->get_mensaje(m);
				Adversario* adv = saludable->get_adversario(a);
				if (msj->Area().IntersectsWith(adv->Area()))
				{
					verde->agregar_a(new Adversario(adv->get_x(), adv->get_y(), adv->get_dx(), adv->get_dy()));
					saludable->eliminar_a(a--);
					mensajes->eliminar_m(m--);
					puntos += 10;
					break;
				}
			}
	}
	void Colision_msg_asin(){
		ArregloMensaje* mensajes = jugador->get_mensajes();
		for (int m = 0; m < mensajes->get_cantidad(); m++)
			for (int a = 0; a < asintomatico->get_cantidad(); a++)
			{
				Mensaje* msj = mensajes->get_mensaje(m);
				Adversario* adv = asintomatico->get_adversario(a);
				if (msj->Area().IntersectsWith(adv->Area()))
				{
					rojo->agregar_a(new Adversario(adv->get_x(), adv->get_y(), adv->get_dx(), adv->get_dy()));
					asintomatico->eliminar_a(a--);
					mensajes->eliminar_m(m--);
					puntos += 10;
					break;
				}
			}
	}
	void colision_jug_saludable() {
		for (int a = 0; a < saludable->get_cantidad(); a++){
			Adversario* adv = saludable->get_adversario(a);
			if (jugador->Area().IntersectsWith(adv->Area()))
			{
				jugador->set_x(2);
				jugador->set_y(100);
				jugador->set_vidas(jugador->get_vidas() - 1);
				break;
			}
		}
	}
	void colision_jug_asintomatico() {
		for (int a = 0; a < asintomatico->get_cantidad(); a++) {
			Adversario* adv = asintomatico->get_adversario(a);
			if (jugador->Area().IntersectsWith(adv->Area()))
			{
				jugador->set_x(2);
				jugador->set_y(100);
				jugador->set_vidas(jugador->get_vidas() - 1);
				break;
			}
		}
	}
	void atrapar_ambu_rojo() {
		for (int a = 0; a < rojo->get_cantidad(); a++) {
			Adversario* adv = rojo->get_adversario(a);
			if (adv->get_x() > ambulancia->get_x()) {
				ambulancia->set_dx(5);
				ambulancia->set_movimiento(Derecha);
			}
			if (adv->get_x() < ambulancia->get_x()) {
				ambulancia->set_dx(-5);
				ambulancia->set_movimiento(Izquierda);
			}
			if (adv->get_y() > ambulancia->get_y()) {
				ambulancia->set_dy(5);
			}
			if (adv->get_y() < ambulancia->get_y()) {
				ambulancia->set_dy(-5);
			}
		}
	}
	void colision_amb_rojo() {
		for (int a = 0; a < rojo->get_cantidad(); a++) {
			Adversario* adv = rojo->get_adversario(a);
			if (ambulancia->Area().IntersectsWith(adv->Area()))
			{
				rojo->eliminar_a(a--);
				ambulancia->set_dx(-5);
				ambulancia->set_dy(5);
				ambulancia->set_movimiento(Izquierda);
				break;
			}
		}
	}
	void atrapar_poli_verde() {
		for (int a = 0; a < verde->get_cantidad(); a++) {
			Adversario* adv = verde->get_adversario(a);
			if (adv->get_x() > policia->get_x()) {
				policia->set_dx(5);
				policia->set_movimiento(Derecha);
			}
			if (adv->get_x() < policia->get_x()) {
				policia->set_dx(-5);
				policia->set_movimiento(Izquierda);
			}
			if (adv->get_y() > policia->get_y()) {
				policia->set_dy(5);
			}
			if (adv->get_y() < policia->get_y()) {
				policia->set_dy(-5);
			}
		}
	}
	void colision_policia_verde() {
		for (int a = 0; a < verde->get_cantidad(); a++) {
			Adversario* adv = verde->get_adversario(a);
			if (policia->Area().IntersectsWith(adv->Area()))
			{
				verde->eliminar_a(a--);
				policia->set_dx(-5);
				policia->set_dy(5);
				policia->set_movimiento(Izquierda);
				break;
			}
		}
	}
	void colision_obj_jugador_m1() {
		for (int i = 0; i < saludable->get_cantidad(); i++)
		{
			ArregloMensaje* objetos = saludable->get_adversario(i)->get_obj();

			for (int j = 0; j < objetos->get_cantidad(); j++)
			{
				Mensaje* obj = objetos->get_mensaje(j);
				if (obj->Area().IntersectsWith(jugador->Area()))
				{
					jugador->set_vidas(jugador->get_vidas() - 1);
					objetos->eliminar_m(j--);
					jugador->set_x(2);
					jugador->set_y(90 + rand() % 400);
				}
			}
		}
	}
	void colision_obj_jugador_m2() {
		for (int i = 0; i < saludable->get_cantidad(); i++) 
		{
			ArregloMensaje* objetos = saludable->get_adversario(i)->get_obj();

			for (int j = 0; j < objetos->get_cantidad(); j++)
			{
				Mensaje* obj = objetos->get_mensaje(j);
				if (obj->Area().IntersectsWith(jugador->Area()))
				{
					jugador->set_vidas(jugador->get_vidas() - 1);
					objetos->eliminar_m(j--);
					jugador->set_x(2);
					jugador->set_y(90 + rand() % 400);
				}
			}
		}
		for (int i = 0; i < asintomatico->get_cantidad(); i++)
		{
			ArregloMensaje* objetos = asintomatico->get_adversario(i)->get_obj();

			for (int j = 0; j < objetos->get_cantidad(); j++)
			{
				Mensaje* obj = objetos->get_mensaje(j);
				if (obj->Area().IntersectsWith(jugador->Area()))
				{
					jugador->set_vidas(jugador->get_vidas() - 1);
					objetos->eliminar_m(j--);
					jugador->set_x(2);
					jugador->set_y(90 + rand() % 400);
				}
			}
		}
	}
	void atrapar_ladron_jugador() {
		if (jugador->get_x() > ladron->get_x()) {
			ladron->set_dx(2);
			ladron->set_movimiento(Derecha);
		}
		if (jugador->get_x() < ladron->get_x()) {
			ladron->set_dx(-2);
			ladron->set_movimiento(Izquierda);
		}
		if (jugador->get_y() > ladron->get_y()) {
			ladron->set_dy(2);
		}
		if (jugador->get_y() < ladron->get_y()) {
			ladron->set_dy(-2);
		}
		if (jugador->Area().IntersectsWith(ladron->Area())) {
			jugador->set_x(2);
			jugador->set_y(90 + rand() % 400);
			jugador->set_vidas(jugador->get_vidas() - 1);
		}
	}
	void disparar(){
		jugador->Disparo();
	}
	void agregar_adversarios_m1() {
		Random r;
		saludable->agregar_a(new Adversario(r.Next(350, 1000), r.Next(90, 450), r.Next(4)*-1, r.Next(4)*-1));
		System::Threading::Thread::Sleep(400);
	}
	void agregar_adversarios_m2(){
		Random r;
		saludable->agregar_a(new Adversario(r.Next(350, 1000), r.Next(90, 450), r.Next(4)*-1, r.Next(4)*-1));
		System::Threading::Thread::Sleep(400);
		asintomatico->agregar_a(new Adversario(r.Next(350, 1000), r.Next(90, 450), r.Next(4)*-1, r.Next(4)*-1));
		System::Threading::Thread::Sleep(400);
	}
	void mover_m1(Graphics^ g) {
		jugador->mover(g);
		saludable->mover(g, a);
		verde->mover(g, a);
		policia->mover(g);
	}
	void mover_m2(Graphics^ g){
		jugador->mover(g);
		saludable->mover(g, a);
		asintomatico->mover(g, a);
		verde->mover(g, a);
		rojo->mover(g, a);
		ambulancia->mover(g);
		policia->mover(g);
		ladron->mover(g);
	}
	void mostrar_obj_m1(Graphics^ g, Bitmap^ obj) {
		saludable->mostrar_obj(g, obj, a);
	}
	void mostrar_obj_m2(Graphics^ g, Bitmap^ obj) {
		saludable->mostrar_obj(g, obj, a);
		asintomatico->mostrar_obj(g, obj, a);
	}
	void mostrar_m1(Graphics^ g, Bitmap^ jugador, Bitmap^ mensajes,Bitmap^ saludable,
		Bitmap^ verde, Bitmap ^policia) {
		this->jugador->mostrar(g, jugador);
		this->jugador->mostrar_msg(g, mensajes);
		this->saludable->mostrar(g, saludable);
		this->verde->mostrar(g, verde);
		this->policia->mostrar(g, policia);
	}
	void mostrar_m2(Graphics^ g, Bitmap^ jugador, Bitmap^ mensajes, Bitmap^ saludable, Bitmap^ asintomatico,
		Bitmap^ verde, Bitmap^ rojo, Bitmap^ ambulancia, Bitmap ^policia, Bitmap ^ladron) {
		this->jugador->mostrar(g, jugador);
		this->jugador->mostrar_msg(g, mensajes);
		this->saludable->mostrar(g, saludable);
		this->asintomatico->mostrar(g, asintomatico);
		this->verde->mostrar(g, verde);
		this->rojo->mostrar(g, rojo);
		this->ambulancia->mostrar(g, ambulancia);
		this->policia->mostrar(g, policia);
		this->ladron->mostrar(g, ladron);
	}
};