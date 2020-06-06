//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TShape *linia[4];
int i=0;
String obrazek;
int znaczek;
TImage *znak[9];
int x=0;
int y=0;
int wek[3][3];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::poczatek(TObject *Sender)
{

for(int n=0;n<3;n++){
for(int m=0;m<3;m++){
wek[m][n]=3;
}}

 Timer1->Enabled=true;
 linia[1]=new TShape(this);
 linia[1]->Parent=Form1;
 linia[1]->Shape=stRectangle;
 linia[1]->Left=0;
 linia[1]->Top=75;
 linia[1]->Height=2;
 linia[1]->Width=2;
  linia[2]=new TShape(this);
 linia[2]->Parent=Form1;
 linia[2]->Shape=stRectangle;
 linia[2]->Left=0;
 linia[2]->Top=175;
 linia[2]->Height=2;
 linia[2]->Width=2;
  linia[3]=new TShape(this);
 linia[3]->Parent=Form1;
 linia[3]->Shape=stRectangle;
 linia[3]->Left=95;
 linia[3]->Top=0;
 linia[3]->Height=2;
 linia[3]->Width=2;
  linia[4]=new TShape(this);
 linia[4]->Parent=Form1;
 linia[4]->Shape=stRectangle;
 linia[4]->Left=195;
 linia[4]->Top=0;
 linia[4]->Height=2;
 linia[4]->Width=2;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if(linia[1]->Width!=300){
  linia[1]->Width=linia[1]->Width+1;
  linia[2]->Width=linia[2]->Width+1;
  linia[3]->Height=linia[3]->Height+1;
  linia[4]->Height=linia[4]->Height+1;
}
}
//---------------------------------------------------------------------------
void clear()
{
 system("cls");
 
}
//---------------------------------------------------------------------------
void komunikat(int x)
{
if(x==1)
Application->MessageBoxA("Wygrali krzyzacy! Chcesz grac jeszcze raz ?","WINNER!", MB_OKCANCEL |  MB_ICONQUESTION);
else
Application->MessageBoxA("Wygrali kolka! Chcesz grac jeszcze raz ?","WINNER!", MB_OKCANCEL |  MB_ICONQUESTION);
}

//---------------------------------------------------------------------------
void sprawdzanie()
{
if(wek[0][0]==1 && wek[0][1]==1 && wek[0][2]==1){
komunikat(1);
}
if(wek[1][0]==1 && wek[1][1]==1 && wek[1][2]==1){
komunikat(1);
}
if(wek[2][2]==1 && wek[2][1]==1 && wek[2][2]==1){
komunikat(1);
}
if(wek[0][0]==1 && wek[1][0]==1 && wek[2][0]==1){
komunikat(1);
}
if(wek[0][1]==1 && wek[1][1]==1 && wek[2][1]==1){
komunikat(1);
}
if(wek[0][2]==1 && wek[1][2]==1 && wek[2][2]==1){
komunikat(1);
}
if(wek[0][0]==1 && wek[1][1]==1 && wek[2][2]==1){
komunikat(1);
}
if(wek[2][0]==1 && wek[1][1]==1 && wek[0][1]==1){
komunikat(1);
}
//---------
if(wek[0][0]==0 && wek[0][1]==0 && wek[0][2]==0){
komunikat(0);
}
if(wek[1][0]==0 && wek[1][1]==0 && wek[1][2]==0){
komunikat(0);
}
if(wek[2][2]==0 && wek[2][1]==0 && wek[2][2]==0){
komunikat(0);
}
if(wek[0][0]==0 && wek[1][0]==0 && wek[2][0]==0){
komunikat(0);
}
if(wek[0][1]==0 && wek[1][1]==0 && wek[2][1]==0){
komunikat(0);
}
if(wek[0][2]==0 && wek[1][2]==0 && wek[2][2]==0){
komunikat(0);
}
if(wek[0][0]==0 && wek[1][1]==0 && wek[2][2]==0){
komunikat(0);
}
if(wek[2][0]==0 && wek[1][1]==0 && wek[0][1]==0){
komunikat(0);
}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::klikniecie(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(Button==mbLeft){
 if(i%2==0){
  obrazek="krzyz.bmp";
  znaczek=1;
 }
 else{
    obrazek="kolko.bmp";
    znaczek=0;
 }
 znak[i]=new TImage(this);
 znak[i]->Parent=this;
 znak[i]->Picture->LoadFromFile(obrazek);

 if(X>0 && X<95 && Y>0 && Y<75)
 {x=10; y=2; wek[0][0]=znaczek;}
 if(X>96 && X<195 && Y>0 && Y < 75)
               {x=107; y=2;wek[1][0]=znaczek;}
         if(X>195 && Y>0 && Y < 75)
               {x=207; y=2;wek[2][0]=znaczek;}
         if(X>0 && X<95 && Y>76 && Y < 175)
               {x=10; y=87;wek[0][1]=znaczek;}
         if(X>96 && X<195 && Y>76 && Y < 175)
               {x=107; y=87;wek[1][1]=znaczek;}
         if(X>195 && Y>76 && Y < 175)
               {x=207; y=87;wek[2][1]=znaczek;}
         if(X>0 && X<95 && Y>176)
               {x=10; y=187;wek[0][2]=znaczek;}
         if(X>96 && X<195 && Y>176)
               {x=107; y=187;wek[1][2]=znaczek;}
         if(X>195 && Y>176)
               {x=207; y=187;wek[2][2]=znaczek;}

 znak[i]->Top=y;
 znak[i]->Left=x;
 znak[i]->Stretch=true;
 znak[i]->Width=72;
 znak[i]->Height=72;
 i++;
 sprawdzanie();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
clear();
}
//---------------------------------------------------------------------------

