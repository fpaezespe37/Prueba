#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <iostream>

using namespace std;

/*void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}*/

int main()
{
	int v [20];
	int i;
	srand(time(NULL));
	for(i=0;i<20;i++)
	{
	v[i]=12+rand()%(35-12+1);
	cout << "\t ", v[i];
	}
	
	return 0;
	/*char numAleatorio[100];
    int i = 0, j = 0, x = 0;

    cout<<"Generacion de numeros aleatorios: \n";
    fgets(numAleatorio, 5, stdin);

    srand(time(NULL));
    if (strlen(numAleatorio) > 0) {
        for (j = 0; j < 10; j++) {
            system("cls");
            for (i = 0; i < strlen(numAleatorio); i++) {
                x = (rand() % 4) + j;
                gotoxy(i+1, x);
                if (x < 24) {
                    cout<<numAleatorio[i];
                }
            }
            Sleep(250);
        }
    }
	
	return 0;*/
    
}
