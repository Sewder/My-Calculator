#pragma once
#include "hashmap_elements.h"
#include <msclr/marshal_cppstd.h>
#include <algorithm>
#include <cctype>

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			create_hashmap();

			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ click;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ Proportions;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;




	protected:

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				5));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				10));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint3 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				15));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->click = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Proportions = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(49, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(272, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Give the compound or element";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// click
			// 
			this->click->BackColor = System::Drawing::Color::DarkTurquoise;
			this->click->Cursor = System::Windows::Forms::Cursors::Hand;
			this->click->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->click->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->click->Location = System::Drawing::Point(392, 67);
			this->click->Name = L"click";
			this->click->Size = System::Drawing::Size(94, 51);
			this->click->TabIndex = 1;
			this->click->Text = L"---->";
			this->click->UseVisualStyleBackColor = false;
			this->click->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(53, 70);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(251, 44);
			this->textBox1->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(58, 150);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 35);
			this->label4->TabIndex = 5;
			this->label4->Text = L"ANs";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Visible = false;
			// 
			// Proportions
			// 
			this->Proportions->AutoSize = true;
			this->Proportions->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold));
			this->Proportions->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->Proportions->Location = System::Drawing::Point(56, 200);
			this->Proportions->Name = L"Proportions";
			this->Proportions->Size = System::Drawing::Size(63, 35);
			this->Proportions->TabIndex = 7;
			this->Proportions->Text = L"ANS";
			this->Proportions->Visible = false;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(53, 266);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			dataPoint1->AxisLabel = L"A";
			dataPoint2->AxisLabel = L"B";
			dataPoint3->AxisLabel = L"C";
			series1->Points->Add(dataPoint1);
			series1->Points->Add(dataPoint2);
			series1->Points->Add(dataPoint3);
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(209, 155);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(617, 446);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->Proportions);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->click);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HelpButton = true;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"The mass calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string equation = msclr::interop::marshal_as<std::string>(textBox1->Text);
		create_elements_hashmap(equation);
		double mass = return_mass();
		String^ proportions= msclr::interop::marshal_as<String^>(reduceProportions());
		chart1->Series->Clear();
		if (mass == 0) {
			String^ message = "please write a valid compound or element";
			MessageBox::Show(message);
		}
		else {
			label4->Text = "mass of compound is " + gcnew String(std::to_string(mass).c_str());
			label4->Visible = true;
			Proportions->Text = "proportions for elements is " + proportions;
			Proportions->Visible = true;
			chart1->Series->Add("ElementProportions");
			for (const auto& pair : elements_numbers) {
				String^ key = msclr::interop::marshal_as<String^>(pair.first);
				int value = pair.second;
				System::Windows::Forms::DataVisualization::Charting::DataPoint^ dataPoint = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0, (hashmap[pair.first]/mass)*100));
				dataPoint->AxisLabel = key;
				chart1->Series["ElementProportions"]->Points->Add(dataPoint);
				chart1->Series["ElementProportions"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
				chart1->Titles->Clear();
				chart1->Titles->Add("Element Proportions in " + textBox1->Text);
				chart1->Legends->Clear();
				chart1->Legends->Add(gcnew System::Windows::Forms::DataVisualization::Charting::Legend());

			}
			chart1->Visible = true;


		}
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
