#pragma once
#include"Juego.h"

namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			juego = new Juego();
			for (int i = 0; i < 3; i++) {
				juego->agregar_adversarios_m1();
			}
			img_sanborja = gcnew Bitmap("SanBorja.jpg");
			img_sjl = gcnew Bitmap("SJL.jpg");
			img_jug = gcnew Bitmap("personaje.png");
			img_men = gcnew Bitmap("mensaje.jpeg");
			img_salu = gcnew Bitmap("saludable.png");
			img_asin = gcnew Bitmap("asintomatico.png");
			img_verde = gcnew Bitmap("verde.png");
			img_rojo = gcnew Bitmap("rojo.png");
			img_ambulancia = gcnew Bitmap("ambulancia.png");
			img_policia = gcnew Bitmap("policia.png");
			img_obj = gcnew Bitmap("objeto.png");
			img_ladron = gcnew Bitmap("ladron.png");
			fondo1 = gcnew Bitmap("fondo1.jpg");
			fondo2 = gcnew Bitmap("fondo2.png");
			this->BackgroundImage = fondo1;
			img_j = gcnew Bitmap("J.jpg");
			img_gameover = gcnew Bitmap("over.jpg");
			img_win = gcnew Bitmap("win.jpg");
			img_instrucciones = gcnew Bitmap("instrucciones.jpg");
			music1 = gcnew SoundPlayer("music1.wav");
			music2 = gcnew SoundPlayer("music2.wav");
			music1->PlayLooping();

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  Clock;
	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		Graphics ^g;
		Juego *juego;
		Bitmap ^img_sanborja;
		Bitmap ^img_sjl;
		Bitmap ^img_jug;
		Bitmap ^img_men;
		Bitmap ^img_salu;
		Bitmap ^img_asin;
		Bitmap ^img_verde;
		Bitmap ^img_rojo;
		Bitmap ^img_ambulancia;
		Bitmap ^img_policia;
		Bitmap ^img_obj;
		Bitmap ^img_ladron;
		Bitmap ^fondo1;
		Bitmap ^fondo2;
		Bitmap ^img_j;
		Bitmap ^img_gameover;
		Bitmap ^img_win;
		Bitmap ^img_instrucciones;
		SoundPlayer ^music1;
		SoundPlayer ^music2;
	private: System::Windows::Forms::Timer^  Clock2;
	private: System::Windows::Forms::Button^  btncomenzar;
	private: System::Windows::Forms::Label^  lblvidas;
	private: System::Windows::Forms::Label^  lbltiempo;
	private: System::Windows::Forms::TextBox^  txtvidas;

	private: System::Windows::Forms::TextBox^  txttiempo;
	private: System::Windows::Forms::Label^  lbldificultad;
	private: System::Windows::Forms::Button^  btnprincipiante;
	private: System::Windows::Forms::Button^  btnavanzado;







	private: System::Windows::Forms::Button^  btninstrucciones;
			 /// <summary>
			 /// Variable del diseñador necesaria.
			 /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->Clock = (gcnew System::Windows::Forms::Timer(this->components));
				 this->Clock2 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->btncomenzar = (gcnew System::Windows::Forms::Button());
				 this->btninstrucciones = (gcnew System::Windows::Forms::Button());
				 this->lblvidas = (gcnew System::Windows::Forms::Label());
				 this->lbltiempo = (gcnew System::Windows::Forms::Label());
				 this->txtvidas = (gcnew System::Windows::Forms::TextBox());
				 this->txttiempo = (gcnew System::Windows::Forms::TextBox());
				 this->lbldificultad = (gcnew System::Windows::Forms::Label());
				 this->btnprincipiante = (gcnew System::Windows::Forms::Button());
				 this->btnavanzado = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // Clock
				 // 
				 this->Clock->Tick += gcnew System::EventHandler(this, &MyForm::Clock_Tick);
				 // 
				 // Clock2
				 // 
				 this->Clock2->Tick += gcnew System::EventHandler(this, &MyForm::Clock2_Tick);
				 // 
				 // btncomenzar
				 // 
				 this->btncomenzar->BackColor = System::Drawing::SystemColors::Highlight;
				 this->btncomenzar->Font = (gcnew System::Drawing::Font(L"Algerian", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->btncomenzar->Location = System::Drawing::Point(244, 294);
				 this->btncomenzar->Name = L"btncomenzar";
				 this->btncomenzar->Size = System::Drawing::Size(235, 79);
				 this->btncomenzar->TabIndex = 0;
				 this->btncomenzar->Text = L"Comenzar";
				 this->btncomenzar->UseVisualStyleBackColor = false;
				 this->btncomenzar->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::btncomenzar_MouseClick);
				 // 
				 // btninstrucciones
				 // 
				 this->btninstrucciones->BackColor = System::Drawing::SystemColors::Highlight;
				 this->btninstrucciones->Font = (gcnew System::Drawing::Font(L"Algerian", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->btninstrucciones->Location = System::Drawing::Point(646, 290);
				 this->btninstrucciones->Name = L"btninstrucciones";
				 this->btninstrucciones->Size = System::Drawing::Size(235, 83);
				 this->btninstrucciones->TabIndex = 1;
				 this->btninstrucciones->Text = L"Instrucciones";
				 this->btninstrucciones->UseVisualStyleBackColor = false;
				 this->btninstrucciones->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::btninstrucciones_MouseClick);
				 // 
				 // lblvidas
				 // 
				 this->lblvidas->AutoSize = true;
				 this->lblvidas->Enabled = false;
				 this->lblvidas->Font = (gcnew System::Drawing::Font(L"Algerian", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lblvidas->Location = System::Drawing::Point(438, 87);
				 this->lblvidas->Name = L"lblvidas";
				 this->lblvidas->Size = System::Drawing::Size(103, 30);
				 this->lblvidas->TabIndex = 2;
				 this->lblvidas->Text = L"Vidas: ";
				 this->lblvidas->Visible = false;
				 // 
				 // lbltiempo
				 // 
				 this->lbltiempo->AutoSize = true;
				 this->lbltiempo->Enabled = false;
				 this->lbltiempo->Font = (gcnew System::Drawing::Font(L"Algerian", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lbltiempo->Location = System::Drawing::Point(427, 182);
				 this->lbltiempo->Name = L"lbltiempo";
				 this->lbltiempo->Size = System::Drawing::Size(114, 30);
				 this->lbltiempo->TabIndex = 3;
				 this->lbltiempo->Text = L"Tiempo:";
				 this->lbltiempo->Visible = false;
				 // 
				 // txtvidas
				 // 
				 this->txtvidas->Enabled = false;
				 this->txtvidas->Font = (gcnew System::Drawing::Font(L"Algerian", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->txtvidas->Location = System::Drawing::Point(552, 83);
				 this->txtvidas->Name = L"txtvidas";
				 this->txtvidas->Size = System::Drawing::Size(100, 39);
				 this->txtvidas->TabIndex = 4;
				 this->txtvidas->Visible = false;
				 // 
				 // txttiempo
				 // 
				 this->txttiempo->Enabled = false;
				 this->txttiempo->Font = (gcnew System::Drawing::Font(L"Algerian", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->txttiempo->Location = System::Drawing::Point(552, 178);
				 this->txttiempo->Name = L"txttiempo";
				 this->txttiempo->Size = System::Drawing::Size(100, 39);
				 this->txttiempo->TabIndex = 5;
				 this->txttiempo->Visible = false;
				 // 
				 // lbldificultad
				 // 
				 this->lbldificultad->AutoSize = true;
				 this->lbldificultad->Enabled = false;
				 this->lbldificultad->Font = (gcnew System::Drawing::Font(L"Algerian", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lbldificultad->Location = System::Drawing::Point(481, 290);
				 this->lbldificultad->Name = L"lbldificultad";
				 this->lbldificultad->Size = System::Drawing::Size(159, 30);
				 this->lbldificultad->TabIndex = 6;
				 this->lbldificultad->Text = L"Dificultad";
				 this->lbldificultad->Visible = false;
				 // 
				 // btnprincipiante
				 // 
				 this->btnprincipiante->BackColor = System::Drawing::Color::MediumPurple;
				 this->btnprincipiante->Enabled = false;
				 this->btnprincipiante->Font = (gcnew System::Drawing::Font(L"Garamond", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btnprincipiante->Location = System::Drawing::Point(293, 343);
				 this->btnprincipiante->Name = L"btnprincipiante";
				 this->btnprincipiante->Size = System::Drawing::Size(159, 55);
				 this->btnprincipiante->TabIndex = 7;
				 this->btnprincipiante->Text = L"Principiante";
				 this->btnprincipiante->UseVisualStyleBackColor = false;
				 this->btnprincipiante->Visible = false;
				 this->btnprincipiante->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::btnprincipiante_MouseClick);
				 // 
				 // btnavanzado
				 // 
				 this->btnavanzado->BackColor = System::Drawing::Color::MediumPurple;
				 this->btnavanzado->Enabled = false;
				 this->btnavanzado->Font = (gcnew System::Drawing::Font(L"Garamond", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btnavanzado->Location = System::Drawing::Point(671, 343);
				 this->btnavanzado->Name = L"btnavanzado";
				 this->btnavanzado->Size = System::Drawing::Size(172, 55);
				 this->btnavanzado->TabIndex = 8;
				 this->btnavanzado->Text = L"Avanzado";
				 this->btnavanzado->UseVisualStyleBackColor = false;
				 this->btnavanzado->Visible = false;
				 this->btnavanzado->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::btnavanzado_MouseClick);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1147, 518);
				 this->Controls->Add(this->btnavanzado);
				 this->Controls->Add(this->btnprincipiante);
				 this->Controls->Add(this->lbldificultad);
				 this->Controls->Add(this->txttiempo);
				 this->Controls->Add(this->txtvidas);
				 this->Controls->Add(this->lbltiempo);
				 this->Controls->Add(this->lblvidas);
				 this->Controls->Add(this->btninstrucciones);
				 this->Controls->Add(this->btncomenzar);
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
				 this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void Clock_Tick(System::Object^  sender, System::EventArgs^  e) {

		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->DrawImage(img_sanborja, 0, 0, 1173, 597);


		juego->mover_m1(bf->Graphics);
		juego->mostrar_m1(bf->Graphics, img_jug, img_men, img_salu, img_verde, img_policia);
		juego->mostrar_obj_m1(bf->Graphics, img_obj);

		juego->tiempo();
		juego->mostrar_datos(bf->Graphics);

		juego->Colision_msg_salu();
		juego->colision_jug_saludable();
		juego->atrapar_poli_verde();
		juego->colision_policia_verde();
		juego->colision_obj_jugador_m1();

		if (juego->get_puntos() == 30 && juego->get_cantidad_verde() == 0) {
			Clock->Enabled = false;
			BackgroundImage = img_j;
		}
		if (juego->get_vidas() == 0 || juego->get_tiempo() == 0) {
			this->Clock->Enabled = false;
			BackgroundImage = img_gameover;
		}

		bf->Render(g);
	}
	private: System::Void Clock2_Tick(System::Object^  sender, System::EventArgs^  e) {
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->DrawImage(img_sjl, 0, 0, 1163, 557);

		juego->mover_m2(bf->Graphics);
		juego->mostrar_m2(bf->Graphics, img_jug, img_men, img_salu, img_asin, img_verde, img_rojo, img_ambulancia, img_policia, img_ladron);
		juego->mostrar_obj_m2(bf->Graphics, img_obj);

		juego->tiempo();
		juego->mostrar_datos(bf->Graphics);


		juego->Colision_msg_salu();
		juego->Colision_msg_asin();
		juego->colision_jug_saludable();
		juego->colision_jug_asintomatico();
		juego->atrapar_ambu_rojo();
		juego->colision_amb_rojo();
		juego->atrapar_poli_verde();
		juego->colision_policia_verde();
		juego->colision_obj_jugador_m2();
		juego->atrapar_ladron_jugador();

		if (juego->get_cantidad_rojo() == 0 && juego->get_cantidad_verde() == 0 &&
			juego->get_cantidad_saludable() == 0 && juego->get_cantidad_asintomatico() == 0) {
			Clock2->Enabled = false;
			BackgroundImage = img_win;
		}
		if (juego->get_vidas() == 0 || juego->get_tiempo() == 0) {
			Clock2->Enabled = false;
			BackgroundImage = img_gameover;
		}

		bf->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		const int v = 8;
		if (e->KeyCode == Keys::Down) {
			juego->jugador_dy(v);
			juego->movimiento_jugador(Abajo);
		}
		if (e->KeyCode == Keys::Up) {
			juego->jugador_dy(-v);
			juego->movimiento_jugador(Arriba);
		}
		if (e->KeyCode == Keys::Left) {
			juego->jugador_dx(-v);
			juego->movimiento_jugador(Izquierda);
		}
		if (e->KeyCode == Keys::Right) {
			juego->jugador_dx(v);
			juego->movimiento_jugador(Derecha);
		}
		if (e->KeyCode == Keys::Space)
			juego->disparar();

		if (e->KeyCode == Keys::J) {
			BackgroundImage = nullptr;
			for (int i = 0; i < 3; i++) {
				juego->agregar_adversarios_m2();
			}
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Right || e->KeyCode == Keys::Left) {
			juego->jugador_dx(0);
		}

		if (e->KeyCode == Keys::Down || e->KeyCode == Keys::Up) {
			juego->jugador_dy(0);
		}
		if (e->KeyCode == Keys::J) {
			Clock2->Enabled = true;
		}
	}
	private: System::Void btncomenzar_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		btncomenzar->Enabled = false;
		btninstrucciones->Enabled = false;
		btncomenzar->Visible = false;
		btninstrucciones->Visible = false;
		BackgroundImage = fondo2;
		lblvidas->Visible = true;
		lblvidas->Enabled = true;
		lbltiempo->Visible = true;
		lbltiempo->Enabled = true;
		txtvidas->Visible = true;
		txtvidas->Enabled = true;
		txttiempo->Visible = true;
		txttiempo->Enabled = true;
		lbldificultad->Visible = true;
		lbldificultad->Enabled = true;
		btnprincipiante->Visible = true;
		btnprincipiante->Enabled = true;
		btnavanzado->Visible = true;
		btnavanzado->Enabled = true;
	}
	private: System::Void btnprincipiante_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		juego->set_a(false);
		juego->set_tiempo(Convert::ToInt32(txttiempo->Text));
		juego->set_vidas(Convert::ToInt32(txtvidas->Text));
		lblvidas->Visible = false;
		lblvidas->Enabled = false;
		lbltiempo->Visible = false;
		lbltiempo->Enabled = false;
		txtvidas->Visible = false;
		txtvidas->Enabled = false;
		txttiempo->Visible = false;
		txttiempo->Enabled = false;
		lbldificultad->Visible = false;
		lbldificultad->Enabled = false;
		btnprincipiante->Visible = false;
		btnprincipiante->Enabled = false;
		btnavanzado->Visible = false;
		btnavanzado->Enabled = false;
		Clock->Enabled = true;
		music1->Stop();
		music2->PlayLooping();
	}
	private: System::Void btnavanzado_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		juego->set_a(true);
		juego->set_tiempo(Convert::ToInt32(txttiempo->Text));
		juego->set_vidas(Convert::ToInt32(txtvidas->Text));
		lblvidas->Visible = false;
		lblvidas->Enabled = false;
		lbltiempo->Visible = false;
		lbltiempo->Enabled = false;
		txtvidas->Visible = false;
		txtvidas->Enabled = false;
		txttiempo->Visible = false;
		txttiempo->Enabled = false;
		lbldificultad->Visible = false;
		lbldificultad->Enabled = false;
		btnprincipiante->Visible = false;
		btnprincipiante->Enabled = false;
		btnavanzado->Visible = false;
		btnavanzado->Enabled = false;
		Clock->Enabled = true;
		music1->Stop();
		music2->PlayLooping();
	}
	private: System::Void btninstrucciones_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		BackgroundImage = img_instrucciones;
	}
	};
}
