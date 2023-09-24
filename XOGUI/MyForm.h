#pragma once
#include "XO_H.h"

/*
	 button->Enabled = false	----	To turn off the button for the user so that computer wont play.
	 button->Text = ""			----	To change the text of the cell (X / O).
	 button->Visible = false	----	Hides the button.

	 Button click functions have replicated functions for each different button ...
	 so the documentation for buttons click are done for first one (Button_Click 1) and
	 it's the same for all other buttons.

	 Note that: in Player vs Player mode ... Player 1 plays as opponent and Player 2 as computer for the mainboard functions.
*/

//// Gui Header////




namespace XOGUI {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	tictactoe game;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:

		bool playerPlayer = true;			// to check if it's Player vs Player mode.

		// to check if it's player 1 or player 2 turn.
		// Only in Player vs Player mode.
		bool turn;
		bool type = false;					// Playing vs Computer.

	private: System::Windows::Forms::Button^ NewGame;
	public:

		bool difficulty;		// Choosing difficulty (Easy - Nightmare)

		// Restarts the same match again.
		void restart_match()
		{
			Restart->Visible = false;
			NewGame->Visible = false;
			label1->Text = "";
			button_reset();
			Symbol->Visible = true;
			game.Empty();
		}

		// Restarts the game from beginning (To Selection menu).
		void restart_game()
		{
			Restart->Visible = false;
			NewGame->Visible = false;
			label1->Text = "";
			button_reset();
			button_visibility(false);
			game.Empty();
			player->Visible = true;
			computer->Visible = true;
			type = false;
		}

		// used to set a specific button by the computer (Easy or Nightmare)
		// based on the value which comes from the row & column equation.
		// and also to check if it's game over.
		void setButton(int button_no) {
			switch (button_no)			// To check which cell on the GUI to change.
			{
			case 1:
				if (game.computer == 'X')
					but1->Text = symX;
				else
					but1->Text = symO;
				but1->Enabled = false;
				break;

			case 2:
				if (game.computer == 'X')
					but2->Text = symX;
				else
					but2->Text = symO;
				but2->Enabled = false;
				break;

			case 3:
				if (game.computer == 'X')
					but3->Text = symX;
				else
					but3->Text = symO;
				but3->Enabled = false;
				break;

			case 4:
				if (game.computer == 'X')
					but4->Text = symX;
				else
					but4->Text = symO;
				but4->Enabled = false;
				break;

			case 5:
				if (game.computer == 'X')
					but5->Text = symX;
				else
					but5->Text = symO;
				but5->Enabled = false;
				break;

			case 6:
				if (game.computer == 'X')
					but6->Text = symX;
				else
					but6->Text = symO;
				but6->Enabled = false;
				break;

			case 7:
				if (game.computer == 'X')
					but7->Text = symX;
				else
					but7->Text = symO;
				but7->Enabled = false;
				break;

			case 8:
				if (game.computer == 'X')
					but8->Text = symX;
				else
					but8->Text = symO;
				but8->Enabled = false;
				break;

			case 9:
				if (game.computer == 'X')
					but9->Text = symX;
				else
					but9->Text = symO;
				but9->Enabled = false;
				break;
			}

			// Instantly check after computer plays ... if game is over.
			if ((game.Over() == 10) || (game.Over() == inf) || (game.Over() == -10))
			{
				Restart->Visible = true;
				NewGame->Visible = true;
				button_State(false);		// disables all the buttons.

				if (game.Over() == 10)
				{
					label1->Text = "Computer won !!!";
				}
				else if (game.Over() == inf)
				{
					label1->Text = "Tie !!!";
				}
				else if (game.Over() == -10)
				{
					label1->Text = "Congratulations !!! ... You Won";
				}
			}
		}

		// To check if player wins (to overcome computer playing after user wins).
		// Also very important and useful for Player vs Player.
		bool player_wins()
		{
			if ((game.Over() == 10) || (game.Over() == inf) || (game.Over() == -10))
			{
				Restart->Visible = true;
				NewGame->Visible = true;
				button_State(false);

				if (game.Over() == 10)
				{
					label1->Text = "Player 2 wins !!!";
				}
				else if (game.Over() == inf)
				{
					label1->Text = "Tie !!!";
				}
				else if (game.Over() == -10)
				{
					label1->Text = "Player 1 wins";
				}
				return true;
			}
			return false;
		}

		void button_State(bool state)		// sets all buttons (True / False).
		{
			but1->Enabled = state;
			but2->Enabled = state;
			but3->Enabled = state;
			but4->Enabled = state;
			but5->Enabled = state;
			but6->Enabled = state;
			but7->Enabled = state;
			but8->Enabled = state;
			but9->Enabled = state;
		}

		void button_visibility(bool state)	// sets all buttons visibility (True / False).
		{
			but1->Visible = state;
			but2->Visible = state;
			but3->Visible = state;
			but4->Visible = state;
			but5->Visible = state;
			but6->Visible = state;
			but7->Visible = state;
			but8->Visible = state;
			but9->Visible = state;
		}

		// Resets all the text (X / O) inside the cells.
		void button_reset()
		{
			but1->Text = "";
			but2->Text = "";
			but3->Text = "";
			but4->Text = "";
			but5->Text = "";
			but6->Text = "";
			but7->Text = "";
			but8->Text = "";
			but9->Text = "";
		}

		// When game starts ...showing and hiding buttons.
		void start_game()
		{
			// Hides all these buttons.
			player->Visible = false;
			computer->Visible = false;
			start->Visible = false;
			easy->Visible = false;
			nightmare->Visible = false;

			// Shows all buttons.
			button_visibility(true);

			label1->Visible = true;
			label1->Text = "";
			Symbol->Visible = true;
		}

		MyForm(void)								// GUI Form Constructor
		{

			InitializeComponent();
			button_State(false);
			label1->Text = "";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}





	protected:

	protected:












	private: System::Windows::Forms::RadioButton^ X;
	private: System::Windows::Forms::RadioButton^ O;
	private: System::Windows::Forms::GroupBox^ Symbol;
	private: System::Windows::Forms::Button^ Ready;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Restart;
	private: System::Windows::Forms::Button^ but1;
	private: System::Windows::Forms::Button^ but4;
	private: System::Windows::Forms::Button^ but7;
	private: System::Windows::Forms::Button^ but2;
	private: System::Windows::Forms::Button^ but5;
	private: System::Windows::Forms::Button^ but8;
	private: System::Windows::Forms::Button^ but3;
	private: System::Windows::Forms::Button^ but6;
	private: System::Windows::Forms::Button^ but9;
	private: System::Windows::Forms::Button^ player;
	private: System::Windows::Forms::Button^ computer;



	private: System::Windows::Forms::Label^ start;
	private: System::Windows::Forms::Button^ easy;
	private: System::Windows::Forms::Button^ nightmare;


















	private: System::ComponentModel::IContainer^ components;










	private:

		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->X = (gcnew System::Windows::Forms::RadioButton());
			this->O = (gcnew System::Windows::Forms::RadioButton());
			this->Symbol = (gcnew System::Windows::Forms::GroupBox());
			this->Ready = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Restart = (gcnew System::Windows::Forms::Button());
			this->but1 = (gcnew System::Windows::Forms::Button());
			this->but4 = (gcnew System::Windows::Forms::Button());
			this->but7 = (gcnew System::Windows::Forms::Button());
			this->but2 = (gcnew System::Windows::Forms::Button());
			this->but5 = (gcnew System::Windows::Forms::Button());
			this->but8 = (gcnew System::Windows::Forms::Button());
			this->but3 = (gcnew System::Windows::Forms::Button());
			this->but6 = (gcnew System::Windows::Forms::Button());
			this->but9 = (gcnew System::Windows::Forms::Button());
			this->player = (gcnew System::Windows::Forms::Button());
			this->computer = (gcnew System::Windows::Forms::Button());
			this->start = (gcnew System::Windows::Forms::Label());
			this->easy = (gcnew System::Windows::Forms::Button());
			this->nightmare = (gcnew System::Windows::Forms::Button());
			this->NewGame = (gcnew System::Windows::Forms::Button());
			this->Symbol->SuspendLayout();
			this->SuspendLayout();
			// 
			// X
			// 
			this->X->AutoSize = true;
			this->X->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->X->Location = System::Drawing::Point(30, 37);
			this->X->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->X->Name = L"X";
			this->X->Size = System::Drawing::Size(97, 21);
			this->X->TabIndex = 14;
			this->X->TabStop = true;
			this->X->Text = L"Play as X";
			this->X->UseVisualStyleBackColor = true;
			this->X->CheckedChanged += gcnew System::EventHandler(this, &MyForm::X_CheckedChanged);
			// 
			// O
			// 
			this->O->AutoSize = true;
			this->O->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->O->Location = System::Drawing::Point(30, 64);
			this->O->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->O->Name = L"O";
			this->O->Size = System::Drawing::Size(99, 21);
			this->O->TabIndex = 15;
			this->O->TabStop = true;
			this->O->Text = L"Play as O";
			this->O->UseVisualStyleBackColor = true;
			this->O->CheckedChanged += gcnew System::EventHandler(this, &MyForm::O_CheckedChanged);
			// 
			// Symbol
			// 
			this->Symbol->AutoSize = true;
			this->Symbol->Controls->Add(this->Ready);
			this->Symbol->Controls->Add(this->X);
			this->Symbol->Controls->Add(this->O);
			this->Symbol->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Symbol->Location = System::Drawing::Point(616, 244);
			this->Symbol->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Symbol->Name = L"Symbol";
			this->Symbol->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Symbol->Size = System::Drawing::Size(173, 167);
			this->Symbol->TabIndex = 16;
			this->Symbol->TabStop = false;
			this->Symbol->Text = L"Choose Symbol";
			this->Symbol->Visible = false;
			// 
			// Ready
			// 
			this->Ready->AutoSize = true;
			this->Ready->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->Ready->Location = System::Drawing::Point(30, 102);
			this->Ready->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Ready->Name = L"Ready";
			this->Ready->Size = System::Drawing::Size(87, 43);
			this->Ready->TabIndex = 16;
			this->Ready->Text = L"Start";
			this->Ready->UseVisualStyleBackColor = true;
			this->Ready->Click += gcnew System::EventHandler(this, &MyForm::Ready_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(613, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 27);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Computer Won";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// Restart
			// 
			this->Restart->AutoSize = true;
			this->Restart->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->Restart->Location = System::Drawing::Point(618, 131);
			this->Restart->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Restart->Name = L"Restart";
			this->Restart->Size = System::Drawing::Size(171, 37);
			this->Restart->TabIndex = 17;
			this->Restart->Text = L"Restart Game";
			this->Restart->UseVisualStyleBackColor = true;
			this->Restart->Visible = false;
			this->Restart->Click += gcnew System::EventHandler(this, &MyForm::Restart_Click);
			// 
			// but1
			// 
			this->but1->AutoSize = true;
			this->but1->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but1->Location = System::Drawing::Point(19, 33);
			this->but1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but1->Name = L"but1";
			this->but1->Size = System::Drawing::Size(182, 122);
			this->but1->TabIndex = 1;
			this->but1->UseVisualStyleBackColor = true;
			this->but1->Visible = false;
			this->but1->Click += gcnew System::EventHandler(this, &MyForm::but1_Click);
			// 
			// but4
			// 
			this->but4->AutoSize = true;
			this->but4->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but4->Location = System::Drawing::Point(19, 163);
			this->but4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but4->Name = L"but4";
			this->but4->Size = System::Drawing::Size(182, 122);
			this->but4->TabIndex = 4;
			this->but4->UseVisualStyleBackColor = true;
			this->but4->Visible = false;
			this->but4->Click += gcnew System::EventHandler(this, &MyForm::but4_Click);
			// 
			// but7
			// 
			this->but7->AutoSize = true;
			this->but7->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but7->Location = System::Drawing::Point(19, 289);
			this->but7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but7->Name = L"but7";
			this->but7->Size = System::Drawing::Size(182, 122);
			this->but7->TabIndex = 7;
			this->but7->UseVisualStyleBackColor = true;
			this->but7->Visible = false;
			this->but7->Click += gcnew System::EventHandler(this, &MyForm::but7_Click);
			// 
			// but2
			// 
			this->but2->AutoSize = true;
			this->but2->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but2->Location = System::Drawing::Point(207, 33);
			this->but2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but2->Name = L"but2";
			this->but2->Size = System::Drawing::Size(182, 122);
			this->but2->TabIndex = 8;
			this->but2->UseVisualStyleBackColor = true;
			this->but2->Visible = false;
			this->but2->Click += gcnew System::EventHandler(this, &MyForm::but2_Click);
			// 
			// but5
			// 
			this->but5->AutoSize = true;
			this->but5->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but5->Location = System::Drawing::Point(207, 161);
			this->but5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but5->Name = L"but5";
			this->but5->Size = System::Drawing::Size(182, 122);
			this->but5->TabIndex = 9;
			this->but5->UseVisualStyleBackColor = true;
			this->but5->Visible = false;
			this->but5->Click += gcnew System::EventHandler(this, &MyForm::but5_Click);
			// 
			// but8
			// 
			this->but8->AutoSize = true;
			this->but8->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but8->Location = System::Drawing::Point(207, 287);
			this->but8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but8->Name = L"but8";
			this->but8->Size = System::Drawing::Size(182, 122);
			this->but8->TabIndex = 10;
			this->but8->UseVisualStyleBackColor = true;
			this->but8->Visible = false;
			this->but8->Click += gcnew System::EventHandler(this, &MyForm::but8_Click);
			// 
			// but3
			// 
			this->but3->AutoSize = true;
			this->but3->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but3->Location = System::Drawing::Point(399, 35);
			this->but3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but3->Name = L"but3";
			this->but3->Size = System::Drawing::Size(182, 122);
			this->but3->TabIndex = 11;
			this->but3->UseVisualStyleBackColor = true;
			this->but3->Visible = false;
			this->but3->Click += gcnew System::EventHandler(this, &MyForm::but3_Click);
			// 
			// but6
			// 
			this->but6->AutoSize = true;
			this->but6->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but6->Location = System::Drawing::Point(399, 161);
			this->but6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but6->Name = L"but6";
			this->but6->Size = System::Drawing::Size(182, 122);
			this->but6->TabIndex = 12;
			this->but6->UseVisualStyleBackColor = true;
			this->but6->Visible = false;
			this->but6->Click += gcnew System::EventHandler(this, &MyForm::but6_Click);
			// 
			// but9
			// 
			this->but9->AutoSize = true;
			this->but9->Font = (gcnew System::Drawing::Font(L"MV Boli", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->but9->Location = System::Drawing::Point(399, 287);
			this->but9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->but9->Name = L"but9";
			this->but9->Size = System::Drawing::Size(182, 122);
			this->but9->TabIndex = 13;
			this->but9->UseVisualStyleBackColor = true;
			this->but9->Visible = false;
			this->but9->Click += gcnew System::EventHandler(this, &MyForm::but9_Click);
			// 
			// player
			// 
			this->player->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player->Location = System::Drawing::Point(229, 141);
			this->player->Name = L"player";
			this->player->Size = System::Drawing::Size(400, 116);
			this->player->TabIndex = 19;
			this->player->Text = L"Player";
			this->player->UseVisualStyleBackColor = true;
			this->player->Click += gcnew System::EventHandler(this, &MyForm::player_Click);
			// 
			// computer
			// 
			this->computer->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->computer->Location = System::Drawing::Point(229, 281);
			this->computer->Name = L"computer";
			this->computer->Size = System::Drawing::Size(400, 127);
			this->computer->TabIndex = 20;
			this->computer->Text = L"Computer";
			this->computer->UseVisualStyleBackColor = true;
			this->computer->Click += gcnew System::EventHandler(this, &MyForm::computer_Click);
			// 
			// start
			// 
			this->start->AutoSize = true;
			this->start->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start->ForeColor = System::Drawing::Color::DarkRed;
			this->start->Location = System::Drawing::Point(326, 58);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(217, 63);
			this->start->TabIndex = 21;
			this->start->Text = L"Play vs";
			this->start->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// easy
			// 
			this->easy->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 31.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->easy->Location = System::Drawing::Point(147, 35);
			this->easy->Name = L"easy";
			this->easy->Size = System::Drawing::Size(572, 186);
			this->easy->TabIndex = 22;
			this->easy->Text = L"Easy";
			this->easy->UseVisualStyleBackColor = true;
			this->easy->Visible = false;
			this->easy->Click += gcnew System::EventHandler(this, &MyForm::easy_Click);
			// 
			// nightmare
			// 
			this->nightmare->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nightmare->ForeColor = System::Drawing::Color::Maroon;
			this->nightmare->Location = System::Drawing::Point(147, 241);
			this->nightmare->Name = L"nightmare";
			this->nightmare->Size = System::Drawing::Size(572, 178);
			this->nightmare->TabIndex = 23;
			this->nightmare->Text = L"Nightmare";
			this->nightmare->UseVisualStyleBackColor = true;
			this->nightmare->Visible = false;
			this->nightmare->Click += gcnew System::EventHandler(this, &MyForm::nightmare_Click);
			// 
			// NewGame
			// 
			this->NewGame->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NewGame->Location = System::Drawing::Point(618, 182);
			this->NewGame->Name = L"NewGame";
			this->NewGame->Size = System::Drawing::Size(171, 37);
			this->NewGame->TabIndex = 24;
			this->NewGame->Text = L"Restart Selection";
			this->NewGame->UseVisualStyleBackColor = true;
			this->NewGame->Visible = false;
			this->NewGame->Click += gcnew System::EventHandler(this, &MyForm::NewGame_Click);
			// 
			// MyForm
			// 
			this->AccessibleName = L"XO Game";
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(832, 453);
			this->Controls->Add(this->NewGame);
			this->Controls->Add(this->but9);
			this->Controls->Add(this->but6);
			this->Controls->Add(this->but3);
			this->Controls->Add(this->but8);
			this->Controls->Add(this->but5);
			this->Controls->Add(this->but2);
			this->Controls->Add(this->but7);
			this->Controls->Add(this->but4);
			this->Controls->Add(this->but1);
			this->Controls->Add(this->Restart);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Symbol);
			this->Controls->Add(this->start);
			this->Controls->Add(this->computer);
			this->Controls->Add(this->player);
			this->Controls->Add(this->nightmare);
			this->Controls->Add(this->easy);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(850, 500);
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(10);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"XO Game";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Symbol->ResumeLayout(false);
			this->Symbol->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void but1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)		// Checks if it's Player vs Player Mode.
		{
			if (turn == true)			// If it's Player 1's (Opponent) Turn.
			{
				if (game.opponent == 'X')		// if Player 1 chose 'X'.
					but1->Text = symX;
				else if (game.opponent == 'O')	// if Player 2 chose 'O'
					but1->Text = symO;
				game.input(0, 0);		// to insert into the mainboard Player 1.
				turn = !turn;			// Now it's Player 2 turn.
			}
			else						// Player 2's (Computer) Turn.
			{
				if (game.computer == 'X')
					but1->Text = symX;
				else if (game.computer == 'O')
					but1->Text = symO;
				game.input2(0, 0);		// to insert into the mainboard Player 2.
				turn = !turn;			// Now it's Player 1 turn.
			}
		}
		else							// It's Player vs Computer mode.
		{
			game.input(0, 0);			// to insert into the mainboard Player 1.
			if (game.opponent == 'X')
				but1->Text = symX;
			else if (game.opponent == 'O')
				but1->Text = symO;
		}

		// To check if game is over and Player wins after this play.
		// And also important for Player vs Player to check who won after this play.
		if (player_wins())
			return;						// To quit the function and game is over.

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)	// Playing against easy Difficulty of computer.
			{
				setButton(game.easyComputer_turn());		// Computer Plays.
			}
			else						// Playing against nightmare Difficulty of computer.
			{
				setButton(game.nightmareComputer_turn());	// Computer plays.
			}

		}
		but1->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but2_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but2->Text = symX;
				else if (game.opponent == 'O')
					but2->Text = symO;
				game.input(0, 1);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but2->Text = symX;
				else if (game.computer == 'O')
					but2->Text = symO;
				game.input2(0, 1);
				turn = !turn;
			}
		}
		else
		{
			game.input(0, 1);
			if (game.opponent == 'X')
				but2->Text = symX;
			else if (game.opponent == 'O')
				but2->Text = symO;
		}

		if (player_wins())
			return;

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but2->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but3_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but3->Text = symX;
				else if (game.opponent == 'O')
					but3->Text = symO;
				game.input(0, 2);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but3->Text = symX;
				else if (game.computer == 'O')
					but3->Text = symO;
				game.input2(0, 2);
				turn = !turn;
			}
		}
		else
		{
			game.input(0, 2);
			if (game.opponent == 'X')
				but3->Text = symX;
			else if (game.opponent == 'O')
				but3->Text = symO;
		}

		if (player_wins())
			return;
		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but3->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but4_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but4->Text = symX;
				else if (game.opponent == 'O')
					but4->Text = symO;
				game.input(1, 0);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but4->Text = symX;
				else if (game.computer == 'O')
					but4->Text = symO;
				game.input2(1, 0);
				turn = !turn;
			}
		}
		else
		{
			game.input(1, 0);
			if (game.opponent == 'X')
				but4->Text = symX;
			else if (game.opponent == 'O')
				but4->Text = symO;
		}

		if (player_wins())
			return;

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but4->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but5_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but5->Text = symX;
				else if (game.opponent == 'O')
					but5->Text = symO;
				game.input(1, 1);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but5->Text = symX;
				else if (game.computer == 'O')
					but5->Text = symO;
				game.input2(1, 1);
				turn = !turn;
			}
		}
		else
		{
			game.input(1, 1);
			if (game.opponent == 'X')
				but5->Text = symX;
			else if (game.opponent == 'O')
				but5->Text = symO;
		}

		if (player_wins())
			return;

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but5->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but6_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but6->Text = symX;
				else if (game.opponent == 'O')
					but6->Text = symO;
				game.input(1, 2);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but6->Text = symX;
				else if (game.computer == 'O')
					but6->Text = symO;
				game.input2(1, 2);
				turn = !turn;
			}
		}
		else
		{
			game.input(1, 2);
			if (game.opponent == 'X')
				but6->Text = symX;
			else if (game.opponent == 'O')
				but6->Text = symO;
		}

		if (player_wins())
			return;

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but6->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but7_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but7->Text = symX;
				else if (game.opponent == 'O')
					but7->Text = symO;
				game.input(2, 0);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but7->Text = symX;
				else if (game.computer == 'O')
					but7->Text = symO;
				game.input2(2, 0);
				turn = !turn;
			}
		}
		else
		{
			game.input(2, 0);
			if (game.opponent == 'X')
				but7->Text = symX;
			else if (game.opponent == 'O')
				but7->Text = symO;
		}

		if (player_wins())
			return;

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but7->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but8_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but8->Text = symX;
				else if (game.opponent == 'O')
					but8->Text = symO;
				game.input(2, 1);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but8->Text = symX;
				else if (game.computer == 'O')
					but8->Text = symO;
				game.input2(2, 1);
				turn = !turn;
			}
		}
		else
		{
			game.input(2, 1);
			if (game.opponent == 'X')
				but8->Text = symX;
			else if (game.opponent == 'O')
				but8->Text = symO;
		}

		if (player_wins())
			return;

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but8->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}
	private: System::Void but9_Click(System::Object^ sender, System::EventArgs^ e) {

		if (playerPlayer == true)
		{
			if (turn == true)
			{
				if (game.opponent == 'X')
					but9->Text = symX;
				else if (game.opponent == 'O')
					but9->Text = symO;
				game.input(2, 2);
				turn = !turn;
			}
			else
			{
				if (game.computer == 'X')
					but9->Text = symX;
				else if (game.computer == 'O')
					but9->Text = symO;
				game.input2(2, 2);
				turn = !turn;
			}
		}
		else
		{
			game.input(2, 2);
			if (game.opponent == 'X')
				but9->Text = symX;
			else if (game.opponent == 'O')
				but9->Text = symO;
		}

		if (player_wins())
			return;

		if (type == false)				// Playing against computer
		{
			if (difficulty == false)
			{
				setButton(game.easyComputer_turn());
			}
			else
			{
				setButton(game.nightmareComputer_turn());
			}
		}
		but9->Enabled = false;				// To turn off the button for the user so that computer wont play.
	}

		   // Player 1 (Opponent) chooses to go with "X" whether against Computer or player.
	private: System::Void X_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		game.select('X');
	}
		   // Player 1 (Opponent) chooses to go with "O" whether against Computer or player.
	private: System::Void O_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		game.select('O');
	}

		   // To start the match on the pre chosen difficulty.
	private: System::Void Ready_Click(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = "";									// Reset who wins label.
		button_State(true);									// Enable all buttons.
		turn = true;										// Player 1 turn.
		if (game.opponent == 'O')
			if (playerPlayer == false)						// To check if your playing against computer
				setButton(game.nightmareComputer_turn());
			else if (playerPlayer == true)
				turn = false;								// Set the first player to be 'O'
		Symbol->Visible = false;
	}
		   // Not used.
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   // To restart the same match.
	private: System::Void Restart_Click(System::Object^ sender, System::EventArgs^ e) {
		restart_match();
	}
		   // Not used
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   // Player vs Player mode.
	private: System::Void player_Click(System::Object^ sender, System::EventArgs^ e) {
		start_game();										// To start the game.
		type = true;										// Player 1 turn.
		playerPlayer = true;								// Player vs Player mode.
	}
		   // Player vs Computer mode.
	private: System::Void computer_Click(System::Object^ sender, System::EventArgs^ e) {
		player->Visible = false;
		computer->Visible = false;
		start->Visible = false;

		// For choosing difficulty
		easy->Visible = true;
		nightmare->Visible = true;

		playerPlayer = false;
	}
		   // Easy difficulty.
	private: System::Void easy_Click(System::Object^ sender, System::EventArgs^ e) {
		difficulty = false;
		start_game();
	}
		   // Nightmare difficulty
	private: System::Void nightmare_Click(System::Object^ sender, System::EventArgs^ e) {
		difficulty = true;
		start_game();
	}
		   // For restarting the whole game (To the selection again).
	private: System::Void NewGame_Click(System::Object^ sender, System::EventArgs^ e) {
		restart_game();
	}
	};
}
