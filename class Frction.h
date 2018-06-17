#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <typeinfo>
#define pos 2147483647
#define neg -214748 3648
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TComboBox *ComboBox1;
	TBitBtn *BitBtn1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label5;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
class Fraction
{
		private:
				int numerator;    //chiselnyk
				int denominator; //znamennyk
		public:

				class DivisionByZero
				{
					public:
						int num;
						DivisionByZero(index): num(index) {}
				};


				// int overflow
 /*			   class xPerepovnennya
				 {

				  public:
				  int chis;
				  int znam;

//xPerepovnennya(numerator,denominator):chis(numerator),znam(denominator) {}
  xPerepovnennya(chis,znam):numerator(chis),denominator(znam){}



				 }; */
			  //	void Fraction_size(itsNum,itsDenom):numerator(itsNum)denominator(itsDenom){}
				Fraction () : numerator(0), denominator(0) {}
				Fraction(int a, int b): numerator(a), denominator(b) {}
				int SetNumerator () {return numerator;}
				int SetDenominator () {return denominator;}
				void Fraction_Size(Fraction )
				void GetNumerator (int a)
				{numerator = a;}
				void GetDenominator (int b) {denominator = b;}

				int Nod (int c, int d) const
				{
					if (!c || !d)
					{
						return 0;
					}
					c = abs(c);
					d = abs(d);
					while(d != c)
					{
						if(d > c)
						{
							d = d - c;
						}
						else
						{
							c = c - d;
						}
					}
					return c;
				}
				Fraction operator+ (const Fraction& num)
				{
				/*if (denominator>sizeof(int))   //sizeof(int)
				{
				 throw xPerepovnennya();
				} */
				if (numerator>sizeof(int)){throw xPerepovnennya();}
				if (chis.numerator>sizeof(int)){throw xPerepovnennya();}

					if (denominator == 0)
					{
						  throw DivisionByZero(0);
					}
					else if (num.denominator == 0)
					{
						throw DivisionByZero(1);
					}
					else
						return Fraction(numerator*num.denominator+
					num.numerator*denominator, denominator*num.denominator);
				}
				Fraction operator- (const Fraction& num)
				{
					if (denominator == 0)
					{
						  throw DivisionByZero(0);
					}
					else if (num.denominator == 0)
					{
						throw DivisionByZero(1);
					}
					else
						return Fraction(numerator*num.denominator -
					num.numerator*denominator, denominator*num.denominator);
				}
				Fraction operator* (const Fraction& num)
				{
					if (denominator == 0)
					{
						  throw DivisionByZero(0);
					}

					else if (num.denominator == 0)
					{
						throw DivisionByZero(1);
					}
					else
						return Fraction(numerator*num.numerator,
					denominator*num.denominator);
				}
				Fraction operator/ (const Fraction& num)
				{
					if (denominator == 0)
					{
						  throw DivisionByZero(0);
					}
					else if (num.denominator == 0)
					{
						throw DivisionByZero(1);
					}
					else
						return Fraction(numerator*num.denominator,
					denominator*num.numerator);
				}
				/*Fraction Fraction_Size (const Fraction& chis){

				 if (chis>pos){
					 throw  xPerepovnennya(1);

				 }
				  else return 1;

				}  */
};
/*Fraction::Fraction_Size(const Fraction) {

   if (itsDenominator > sizeof(int)|| itsNumerator>sizeof(int) )
   {
	throw xTooBig();
   }

	if (itsDenominator <sizeof(int)|| itsNumerator<sizeof(int) )
   {
	throw xTooSmall();
   }

	*/


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
