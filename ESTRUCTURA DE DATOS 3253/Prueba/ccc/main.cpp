#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void mostrarAleatorio();

int main()
{
	char numAleatorio[100];
    int i = 0, j = 0, x = 0;

	do{
    cout<<"\nGeneracion de numeros aleatorios: \n";
    mostrarAleatorio();
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
            Sleep(100);
        }
    }
	}while(*numAleatorio < 100);
	return 0;
}

void mostrarAleatorio(){
	int num, c;
    srand(time(NULL));

    for(c = 1; c <= 6; c++)
    {
        num = 1 + rand() % (11 - 1);
        cout << num<< " "<<endl;
    }
}
