#pragma once
#include <stdlib.h>
#include <string.h>
#include <algorithm>
//#include <vector>

//219114630 Nkosi LM CC1
namespace My219114630NkosiCC1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		//Variables Used Publicly
		int Dice1;
		int Dice2;
		int Dice3;
		int length;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ button4;

		Random^ ran = gcnew Random();//Random Code in Public
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::ListBox^ lstResults;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtTimes;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lstResults = (gcnew System::Windows::Forms::ListBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtTimes = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// lstResults
			// 
			this->lstResults->FormattingEnabled = true;
			this->lstResults->Location = System::Drawing::Point(505, 32);
			this->lstResults->Name = L"lstResults";
			this->lstResults->Size = System::Drawing::Size(288, 407);
			this->lstResults->TabIndex = 24;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(39, 334);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(162, 48);
			this->button3->TabIndex = 23;
			this->button3->Text = L"Guess Until Correct";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(39, 256);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(162, 47);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Try Guess N Times";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(39, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(430, 53);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Throw Three Dice";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// txtTimes
			// 
			this->txtTimes->Location = System::Drawing::Point(330, 256);
			this->txtTimes->Name = L"txtTimes";
			this->txtTimes->Size = System::Drawing::Size(139, 20);
			this->txtTimes->TabIndex = 20;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(39, 115);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(122, 106);
			this->pictureBox1->TabIndex = 25;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(196, 115);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(122, 106);
			this->pictureBox2->TabIndex = 26;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(347, 115);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(122, 106);
			this->pictureBox3->TabIndex = 27;
			this->pictureBox3->TabStop = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(809, 32);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(94, 23);
			this->button4->TabIndex = 28;
			this->button4->Text = L"Clear";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(905, 464);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lstResults);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtTimes);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//219114630 Nkosi LM CC1
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Dice1 = ran->Next(1, 7);//Randomising dice number display
		Dice2 = ran->Next(1, 7);//Randomising dice number display
		Dice3 = ran->Next(1, 7);//Randomising dice number display

		lstResults->Items->Add("Thrown Dice Values = " + " " + System::Convert::ToString(Dice1) + System::Convert::ToString(Dice2) + System::Convert::ToString(Dice3));

		int arr1[3] = { Dice1,Dice2,Dice3 };//storing the dice values in an array
		int n = sizeof(arr1) / sizeof(arr1[0]);
		std::sort(arr1, arr1 + n);//sorting the dice sequence

		lstResults->Items->Add("Sorted Dice Values = " + " " + arr1[0] + "" + arr1[1] + "" + arr1[2]);//Sorted Dice Sequence

		pictureBox1->Image = Image::FromFile("dice" + System::Convert::ToString(Dice1) + ".png");//Assigning Dice picture1 to The dice1 Variable
		pictureBox2->Image = Image::FromFile("dice" + System::Convert::ToString(Dice2) + ".png");//Assigning Dice picture2 to The dice2 Variable
		pictureBox3->Image = Image::FromFile("dice" + System::Convert::ToString(Dice3) + ".png");//Assigning Dice picture3 to The dice3 Variable
		
		lstResults->Items->Add("==========================");
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
		int Random1;
		int Random2;
		int Random3;
		String^ Times;
		String^ Dubz;
		String^ D;
		String^ T;

		bool Double = false;//Boolean Values for the Double and Triple
		bool Triple = false;
		bool Even = false;//Boolean Values for the Even and Odd
		bool Odd = false;

		Times = txtTimes->Text;//Assigning input from textbox to a variable

		length = System::Convert::ToInt32(Times) + 1;
		
		for (size_t i = 1 ; i < length; i++)
		{
			Random1 = ran->Next(1,7);//Randomising dice number display
			Random2 = ran->Next(1,7);//Randomising dice number display
			Random3 = ran->Next(1,7);//Randomising dice number display

			if (Random1 == Random2 && Random2 == Random3)//iterator used to determine Doubles & triples of the dice sequence
			{
				Triple = true;
				if (Random1 % 2 == 0 || Random2 % 2 == 0 || Random3 % 2 == 0)//Determining Triple Odd or Even
				{
					Even = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Triple" + " " + "Even");
				}
				if ((Random1 % 2 != 0 || Random2 % 2 != 0 || Random3 % 2 != 0))
				{
					Odd = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Triple" +" " + "Odd");
				}
				this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Triple");
			}

			if (Random1 == Random2 || Random1 == Random3 || Random2 == Random3)//iterator used to determine Doubles of the dice sequence
			{
				Double = true;

				if (Random2 % 2 == 0 && Random3 % 2 == 0)//Determining Double Odd or Even
				{
					Even = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Double" + " " + "Even");
				}
				if (Random1 % 2 == 0 && Random2 % 2 == 0 )//Determining Double Odd or Even
				{
					Even = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Double" + " " + "Even");
				}
				if (Random1 % 2 == 0 && Random3 % 2 == 0)//Determining Double Odd or Even
				{
					Even = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Double" + " " + "Even");
				}

				if ((Random2 % 2 != 0 && Random3 % 2 != 0))
				{
					Odd = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Double" + " " + "Odd");
				}
				if ((Random1 % 2 != 0 && Random2 % 2 != 0))
				{
					Odd = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Double" + " " + "Odd");
				}
				if ((Random1 % 2 != 0 && Random3 % 2 != 0))
				{
					Odd = true;
					this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Double" + " " + "Odd");
				}
				this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3) + " " + "Double");
			}
			this->lstResults->Items->Add("Guess" + " " + i + " " + "= " + System::Convert::ToString(Random1) + System::Convert::ToString(Random2) + System::Convert::ToString(Random3));
		}
		lstResults->Items->Add("==========================");
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		lstResults->Items->Add("Guessing Until Exact Match");
	    lstResults->Items->Add("==========================");


		for (size_t i = 1; i < length; i++)
		{
			this->lstResults->Items->Add("Guess" + " " + i + " ");
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		lstResults->Items->Clear();//Clear Button if user needs to clear the stats in the list box
	}
};
}
	




