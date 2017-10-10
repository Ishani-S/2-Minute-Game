#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>

void rules();
void grid();
void goti();
void rightmove1();
void rightmove2();
void leftmove1();
void leftmove2();
void colors();
void out();
void win();

float X=22.5, Y=417.5;

void main()
{
	int gd = DETECT, gm,i,j;
	time_t start, end;

	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");

	rules();

	start = time(NULL);

	grid();
	colors();
	goti();

	fflush(stdin);
	printf("Enter 1/2: ");

maingame:

	while(1)
	{
		scanf("%d",&i);
	//when goti moves right
		if(Y==67.5 || Y==137.5 || Y==207.5 || Y==277.5 || Y==347.5 || Y==417.5 )
		{
			if(i==1)
				rightmove1();

			if(i==2)
				rightmove2();
		}
	//when goti moves left
		else
		{
			if(i==1)
				leftmove1();

			if(i==2)
				leftmove2();
		}

		if(i!=1 && i!=2)
			exit(0);

		out();

		end = time(NULL);

		if((end-start)>=55)
		{
			cleardevice();
			settextstyle(4,0,4);
			outtextxy(250,200,"TIME-OUT!!!!");
			delay(800);
			exit(0);
		}
		if(X == 372.5 && Y == 67.5)
		{
			win();
		}
	}

	getch();
	closegraph();
}

void grid()
{
	rectangle(5,50,390,435);

	//vertical lines:
	line(40,50,40,435);
	line(75,50,75,435);
	line(110,50,110,435);
	line(145,50,145,435);
	line(180,50,180,435);
	line(215,50,215,435);
	line(250,50,250,435);
	line(285,50,285,435);
	line(320,50,320,435);
	line(355,50,355,435);

	//horizontal lines:
	line(5,85,390,85);
	line(5,120,390,120);
	line(5,155,390,155);
	line(5,190,390,190);
	line(5,225,390,225);
	line(5,260,390,260);
	line(5,295,390,295);
	line(5,330,390,330);
	line(5,365,390,365);
	line(5,400,390,400);
}

void goti()
{
	circle(X,Y,10);
}

void rightmove1()
{
	clearviewport();
	grid();
	colors();
	if( X <= 337.5 )
		X=X+35;
	else
		Y=Y-35;
	circle(X,Y,10);
}

void rightmove2()
{
	clearviewport();
	grid();
	colors();
	if( X <= 302.5 )
			X=X+70;

	else if( X == 337.5 )
		{
			X=X+35;
			Y=Y-35;
		}
	else
		{
			X=X-35;
			Y=Y-35;
		}

	circle(X,Y,10);
}

void leftmove1()
{
	clearviewport();
	grid();
	colors();
	if( X >= 57.5 )
		X=X-35;
	else
		Y=Y-35;
	circle(X,Y,10);
}

void leftmove2()
{
	clearviewport();
	grid();
	colors();
	if( X >= 92.5 )
			X=X-70;

	else if( X == 57.5 )
		{
			X=X-35;
			Y=Y-35;
		}
	else
		{
			X=X+35;
			Y=Y-35;
		}

	circle(X,Y,10);
}
void colors()
{
	setfillstyle(SOLID_FILL , BLUE);
	floodfill(50,425,WHITE);
	floodfill(150,425,WHITE);
	floodfill(230,425,WHITE);
	floodfill(310,425,WHITE);

	floodfill(380,380,WHITE);
	floodfill(270,380,WHITE);
	floodfill(200,380,WHITE);
	floodfill(80,380,WHITE);
	floodfill(20,380,WHITE);

	floodfill(50,350,WHITE);
	floodfill(120,350,WHITE);
	floodfill(230,350,WHITE);
	floodfill(310,350,WHITE);
	floodfill(380,350,WHITE);

	floodfill(310,320,WHITE);
	floodfill(230,320,WHITE);
	floodfill(150,320,WHITE);
	floodfill(50,320,WHITE);

	floodfill(310,280,WHITE);
	floodfill(380,280,WHITE);
	floodfill(230,280,WHITE);
	floodfill(120,280,WHITE);
	floodfill(20,280,WHITE);

	floodfill(80,240,WHITE);
	floodfill(150,240,WHITE);
	floodfill(270,240,WHITE);
	floodfill(340,240,WHITE);

	floodfill(80,200,WHITE);
	floodfill(20,200,WHITE);
	floodfill(200,200,WHITE);
	floodfill(310,200,WHITE);

	floodfill(50,160,WHITE);
	floodfill(120,160,WHITE);
	floodfill(200,160,WHITE);
	floodfill(270,160,WHITE);
	floodfill(380,160,WHITE);

	floodfill(50,140,WHITE);
	floodfill(150,140,WHITE);
	floodfill(230,140,WHITE);
	floodfill(340,140,WHITE);

	floodfill(340,100,WHITE);
	floodfill(270,100,WHITE);
	floodfill(200,100,WHITE);
	floodfill(80,100,WHITE);
	floodfill(20,100,WHITE);

	floodfill(80,60,WHITE);
	floodfill(150,60,WHITE);
	floodfill(230,60,WHITE);
	floodfill(310,60,WHITE);

	setcolor(WHITE);
}

void out()
{
	if(Y== 417.5 )
		{
			if(X==57.5 || X==162.5 || X==232.5 || X==302.5)
			{  	cleardevice();
				settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if( Y==382.5 )
		{
			if(X==22.5 || X==92.5 || X==197.5 || X==267.5 || X==372.5)
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y== 347.5)
		{
			if(X==57.5 || X==127.5 || X==232.5 || X==302.5 || X==372.5)
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==312.5)
		{
			if(X==57.5 || X==162.5 || X==232.5 || X==302.5)
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==277.5)
		{
			if(X==22.5 || X==127.5 || X==232.5 || X==302.5 || X==372.5)
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==242.5)
		{
			if(X==92.5 || X==162.5 || X==267.5 || X==337.5)
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==207.5)
		{
			if(X==22.5 || X==92.5 || X==197.5 || X==302.5 )
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==172.5)
		{
			if(X==57.5 || X==127.5 || X==267.5 || X==197.5 || X==372.5)
			{
			cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==137.5)
		{
			if(X==57.5 || X==162.5 || X==232.5 || X==337.5 )
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==102.5)
		{
			if(X==22.5 || X==92.5 || X==197.5 || X==267.5 || X==337.5)
			{  	cleardevice();
			settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");

				delay(1500);
				exit(0);
			}
		}
	if(Y==67.5)
		{
			if(X==92.5 || X==162.5 || X==232.5 || X==302.5)
			{
				cleardevice();
				settextstyle(4,0,4);
				outtextxy(250,200,"GAME OVER...");
				delay(1500);
				exit(0);
			}
		}
}
void rules()
{
	printf("RULES:");
	cleardevice();
}
void win()
{

}