#pragma once
#include "Controlador.h"

namespace Bombardeador {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	private:

		SoundPlayer^ Musicadenivel;
		CControlador* objControlador;
		Bitmap^ bmpSolido = gcnew Bitmap("imagenes\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("imagenes\\bmpDestruible.png");
		Bitmap^ bmpSuelo = gcnew Bitmap("imagenes\\bmpSuelo.png");
		Bitmap^ bmpJugador = gcnew Bitmap("imagenes\\Jugador.png");
		Bitmap^ bmpBomba = gcnew Bitmap("imagenes\\bomba.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("imagenes\\explosion.png");
		Bitmap^ bmpMejoras = gcnew Bitmap("imagenes\\bmpMejoras.png");
		Bitmap^ bmpEnemigo = gcnew Bitmap("imagenes\\bmpEnemigo.png");
	
	public:

		Juego(void)
		{
			objControlador = new CControlador();
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ LabelNivel;
	private: System::Windows::Forms::ProgressBar^ progressBarCarga;
	private: System::Windows::Forms::Timer^ timerCarga;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->LabelNivel = (gcnew System::Windows::Forms::Label());
			this->progressBarCarga = (gcnew System::Windows::Forms::ProgressBar());
			this->timerCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// LabelNivel
			// 
			this->LabelNivel->AutoSize = true;
			this->LabelNivel->Font = (gcnew System::Drawing::Font(L"Ink Free", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelNivel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LabelNivel->Location = System::Drawing::Point(212, 237);
			this->LabelNivel->Name = L"LabelNivel";
			this->LabelNivel->Size = System::Drawing::Size(73, 26);
			this->LabelNivel->TabIndex = 0;
			this->LabelNivel->Text = L"Nivel :";
			// 
			// progressBarCarga
			// 
			this->progressBarCarga->Location = System::Drawing::Point(191, 279);
			this->progressBarCarga->Name = L"progressBarCarga";
			this->progressBarCarga->Size = System::Drawing::Size(161, 23);
			this->progressBarCarga->TabIndex = 1;
			// 
			// timerCarga
			// 
			this->timerCarga->Enabled = true;
			this->timerCarga->Interval = 2500;
			this->timerCarga->Tick += gcnew System::EventHandler(this, &Juego::timerCarga_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(848, 736);
			this->Controls->Add(this->progressBarCarga);
			this->Controls->Add(this->LabelNivel);
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::MantenerTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::UltimaTecla);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void MusicaNivel()
		{
			Musicadenivel = gcnew SoundPlayer("Audio\\ModoSolitario.wav");
			Musicadenivel->PlayLooping();

		}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		objControlador->Dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpDestruible, bmpJugador, bmpBomba, bmpExplosion, bmpMejoras, bmpEnemigo);
		this->Text = "VIDAS: " + objControlador->getobjJugador()->getvidas();
		buffer->Render(g);
		delete buffer, espacio, g;
	}

	private: System::Void Juego_Load(System::Object^  sender, System::EventArgs^  e) {
		LabelNivel->Text = "Nivel: " + objControlador->getNivel();
		objControlador->NuevoNivel();
	}
	private: System::Void Mantener(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
	private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			objControlador->getobjJugador()->setDireccion(Direcciones::Arriba);
			break;
		case Keys::Down:
			objControlador->getobjJugador()->setDireccion(Direcciones::Abajo);
			break;
		case Keys::Right:
			objControlador->getobjJugador()->setDireccion(Direcciones::Derecha);
			break;
		case Keys::Left:
			objControlador->getobjJugador()->setDireccion(Direcciones::Izquierda);
			break;
		default:
			break;
		}
	}
	private: System::Void UltimaTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Space:
			objControlador->AgregarBombas();
			break;
		default:
			objControlador->getobjJugador()->setDireccion(Direcciones::Ninguna);
			break;
		}
	}
private: System::Void timerCarga_Tick(System::Object^ sender, System::EventArgs^ e) {
	LabelNivel->Text = "Nivel: " + objControlador->getNivel();
	progressBarCarga->Increment(10);
	if (timerCarga->Interval == 2500 && objControlador->getobjArrEnemigos()->getvector_enemigos().size() < objControlador->getNivel())
	{
		objControlador->CrearEnemigoyMejora();
	}
	else
	{
		timerCarga->Enabled = false;
		timer1->Enabled = true;
		MusicaNivel();
		LabelNivel->Visible = false;
		LabelNivel->Enabled = false;
		progressBarCarga->Visible = false;
		progressBarCarga->Enabled = false;
	}
}
};
}
