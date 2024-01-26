#include <iostream.h>
#include <windows.h>
#include <conio.h>

void cursorinvisible()
{
	CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gameover(int l)
{
	system("cls");
	cout<<"game over"<<" point = "<<l;
    Sleep(1000);
}

void gameplay()
{
 int l=0;
 int x=60,y=13;
 bool w,s,a=true,d;
 COORD crd;
	srand(time(0));
	crd.X=rand()%60;
	crd.Y=rand()%13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	cout<<'0';
	while(1){
 if (kbhit())
 {
	 switch(_getch())
	 {
		 case 'w':
		 w=true;
		 s=false;
		 a=false;
		 d=false;
		 break;
		 case 's':
		 w=false;
		 s=true;
		 a=false;
		 d=false;
		 break;
		 case 'a':
		 w=false;
		 s=false;
		 a=true;
		 d=false;
		 break;
		 case 'd':
		 w=false;
		 s=false;
		 a=false;
		 d=true;
		 break;
	 }
 }
 COORD coord;
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 if(a==true)
 {
 x--;
 }
 if(s==true)
 {
 y++;
 }
 if(d==true)
 {
 x++;
 }
 if(w==true)
 {
 y--;
 }
 cout<<'a';
 if(y==-1)
 {
 system("cls");
 gameover(l);
 break;
 }
 if(y==30)
 {
 system("cls");
 gameover(l);
 break;
 }
 if(x==120)
 {
 system("cls");
 gameover(l);
 break;
 }
 if(x==crd.X&&y==crd.Y){ l++;
 gameover(l);
 break;
 }
 Sleep(100);
 cout<<"\b ";

 COORD coo;
 coo.X=0;
 coo.Y=0;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coo);
 cout<<l;
 }
}

main()
{
 cursorinvisible();
 gameplay();
}
