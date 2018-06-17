//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <fstream>
#include <ctime>
#define pos 2147483647
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Fraction num_1 (0,0);
Fraction num_2 (0,0);
Fraction res (0,0);
time_t tTimer = time(NULL);
ofstream mefile;
int a ;
//1.choose operator
//2.division by 0
//3.no possible symbol (you entered 4 ) symbol
//4.enter values
//perepovnennya int



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	  ComboBox1->Style = csDropDownList;
	  mefile.open("logfile.txt");
	  mefile << ctime(&tTimer) << "File has opened.\n\n";
	  mefile << ctime(&tTimer) << "Programe has started.\n\n";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	try
	{


		if (ComboBox1->Text == "")
		{
			ShowMessage("Choose operator!");
			mefile << ctime(&tTimer) << "Error. User hasn't chosen operator.\n\n";
		}
		else if (Edit1->Text != "" && Edit2->Text != "" && Edit3->Text != ""
			&& Edit4->Text != "")
		{
			num_1 = Fraction(Edit1->Text.ToInt(), Edit2->Text.ToInt());
			num_2 = Fraction(Edit3->Text.ToInt(), Edit4->Text.ToInt());

			mefile << ctime(&tTimer) << "User has entered two fractions: "
			<< Edit1->Text.ToInt() << "/" << Edit2->Text.ToInt() << " and "
			<< Edit3->Text.ToInt() << "/" << Edit4->Text.ToInt() << "\n\n";

			if (ComboBox1->Text == "+")
			{
				res = num_1 + num_2;
				mefile << ctime(&tTimer) << "User has added two numbers.\n\n";
			}
			if (ComboBox1->Text == "-")
			{
				res = num_1 - num_2;
				mefile << ctime(&tTimer) << "User has subtracted two numbers.\n\n";
			}
			if (ComboBox1->Text == "*")
			{
				res = num_1 * num_2;
				mefile << ctime(&tTimer) << "User has multyplied two numbers.\n\n";
			}
			if (ComboBox1->Text == "/")
			{
				res = num_1 / num_2;
				mefile << ctime(&tTimer) << "User has divided two numbers.\n\n";
			}
			Edit5->Text = res.SetNumerator();
			Edit6->Text = res.SetDenominator();
			mefile << ctime(&tTimer) << "User has got result "<< res.SetNumerator()
			<< "/" << res.SetDenominator() << ".\n\n";
			int number = res.Nod(res.SetDenominator(),res.SetNumerator());
			if (number != 0)
			{
				Edit7->Text = res.SetNumerator()/number;
				Edit8->Text = res.SetDenominator()/number;
			}
			mefile << ctime(&tTimer) << "User has got result "<<
			res.SetNumerator()/number << "/" <<
			res.SetDenominator()/number << ".\n\n";
			 a=Edit2->Text.ToInt();
			 if (a>sizeof(int)){
				mefile << ctime(&tTimer) << "PEREPOVNENNYA";
			 }
		}
		else
		{
			ShowMessage("Enter values!");
			mefile << ctime(&tTimer) << "Error. User hasn't entered some values.\n\n";
		}
	}
	catch(Fraction::DivisionByZero x)
	{
		if (x.num == 0)
			ShowMessage("Division by zero in first number!");
		if (x.num == 1)
			ShowMessage("Division by zero in second number!");
		mefile << ctime(&tTimer) << "Error. Division by zero.\n\n";
	}

	/*catch (Fraction::xPerepovnennya p){

	if (p.chis>sizeof(int)){
	ShowMessage("Perepovnennya int v chis");}

	if (p.znam>sizeof(int)){
	ShowMessage("Perepovn v znam ");
	}
	}  */


	catch ( ... ){}
 /*catch(Fraction::xPerepovnennya per)
 {
	a=StrToInt(Edit1->Text);
	if (per.a>=pos){

	 ShowMessage("Perepovnennya!");

	}
 }
	*/

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if ((Key >= '0') && (Key <= '9'))
	return;

    if (Key == VK_BACK)
	return;

	if (Key == '-')
	return;

	Beep();
	Key = 0;
	ShowMessage("You have entered no possible symbol!");
	mefile << ctime(&tTimer) << "Error. User has enered no possible symbol.\n\n";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	mefile << ctime(&tTimer) << "File has closed.\n\n";
	mefile.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{

 /*catch(Fraction::xPerepovnennya oops){
	if (oops.num>sizeof(int)){
   ShowMessage("Perepovnennya int in first drib");
	 }
   }
       */



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
  /*catch(Fraction::xTooBig){
   ShowMessage("Perepovnennya int");

   }

   catch(Fraction::xTooSmall){
   ShowMessage("Nadto malanke chislo");

   } */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
  /*	  catch(Fraction::xTooBig){
   ShowMessage("Perepovnennya int");

   }

   catch(Fraction::xTooSmall){
   ShowMessage("Nadto malanke chislo");

   }*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)
{
  /*	 catch(Fraction::xTooBig){
   ShowMessage("Perepovnennya int");

   }

   catch(Fraction::xTooSmall){
   ShowMessage("Nadto malanke chislo");
   } */
}
//---------------------------------------------------------------------------
