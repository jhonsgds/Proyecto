#pragma once
#include "Juego.h"

namespace Bombardeador {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ Music;
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ btninstruccionesoff;
	private: System::Windows::Forms::Button^ btninstruccioneson;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btninstruccionesoff = (gcnew System::Windows::Forms::Button());
			this->btninstruccioneson = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(27, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(506, 244);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btninstruccionesoff
			// 
			this->btninstruccionesoff->Location = System::Drawing::Point(429, 320);
			this->btninstruccionesoff->Name = L"btninstruccionesoff";
			this->btninstruccionesoff->Size = System::Drawing::Size(83, 28);
			this->btninstruccionesoff->TabIndex = 1;
			this->btninstruccionesoff->Text = L"Instrucciones";
			this->btninstruccionesoff->UseVisualStyleBackColor = true;
			this->btninstruccionesoff->Click += gcnew System::EventHandler(this, &MenuPrincipal::btninstruccionesoff_Click);
			// 
			// btninstruccioneson
			// 
			this->btninstruccioneson->Location = System::Drawing::Point(429, 321);
			this->btninstruccioneson->Name = L"btninstruccioneson";
			this->btninstruccioneson->Size = System::Drawing::Size(83, 27);
			this->btninstruccioneson->TabIndex = 2;
			this->btninstruccioneson->Text = L"Instrucciones";
			this->btninstruccioneson->UseVisualStyleBackColor = true;
			this->btninstruccioneson->Click += gcnew System::EventHandler(this, &MenuPrincipal::btninstruccioneson_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(575, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(256, 256);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MenuPrincipal::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(611, 294);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(200, 151);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(668, 294);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 30);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Arriba";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(745, 334);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 30);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Derecha";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(675, 415);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 30);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Abajo";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(570, 334);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 30);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Izquierda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(429, 370);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Jugar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(556, 453);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btninstruccioneson);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btninstruccionesoff);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void Musica()
	{
		Music = gcnew SoundPlayer("Audio\\MusicaIntro.wav");
		Music->PlayLooping();
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btninstruccionesoff_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Width = 572;
	btninstruccionesoff->Visible = false;
	btninstruccioneson->Visible = true;
}
private: System::Void btninstruccioneson_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Width = 980;
	btninstruccionesoff->Visible = true;
	btninstruccioneson->Visible = false;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Juego^ frm = gcnew Juego();
	this->Visible = false;
	frm->Show();
	Music->Stop();
}
private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	Musica();
}
};
}
