#pragma once
#include<iostream>
using namespace std;


/*
Gustavo Perez
0901-16-420
Ingenieria en Sitemas
Programacion III
Seccion A
Proyecto: Arbol de Calculo
*/
#include<iostream>
#include<fstream>
#include<String>
#include <sstream>
#include <stdio.h>
#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS
void Leer();
void Cargar();
void Crear_Vector();

using namespace std;

ofstream esc;
ifstream leer;
string sel;
string nom;
string oper[100];//string
int tam = 0;

void menu6() { // ESTE ERA EL MAIN
	int opc = 0;
	do
	{
		system("cls");
		cout << "\n\n\t\t=========== -| OPCIONES |- ===========" << endl;
		cout << "\t\t| 1) Seleccionar Archivo y Operacion.|" << endl;
		cout << "\t\t| 2) Cargar Operacion al Arbol.      |" << endl;
		cout << "\t\t| 3) Mostrar Operacion.              |" << endl;
		cout << "\t\t=====================================" << endl;
		cout << "\t\tPresione ( 0 ) Para salir" << endl;
		cout << "\t\tSeleccione una Opcion -> ";
		cin >> opc;
		switch (opc)
		{
		case 0:
			system("cls");
			cout << "\n\n\n\t\tSALIENDO...";
			Sleep(1500);
			break;
		case 1:
			system("cls");
			cout << "\n\t\tARCHIVO Y OPERACION" << endl;
			cout << "\t\t===================" << endl;
			Leer();
			system("pause>nul");
			break;
		case 2:
			system("cls");
			cout << "\n\t\tCARGANDO OPERACION" << endl;
			cout << "\t\t===================" << endl;
			Cargar();
			system("pause>nul");
			break;
		case 3:
			system("cls");
			cout << "\n\t\t\tOPERACION" << endl;
			cout << "\t\t\t=====" << endl;
			for (int i = 0; i<tam; i++)
			{
				cout << oper[i] << " | ";
			}
			system("pause>nul");
			break;

		default:
			system("cls");
			cout << "\n\n\t\tOPCION NO VALIDA... ";
			Sleep(1500);

			break;
		}

	} while (opc != 0);

}

void Leer() {
	int select = 0;
	string opr;
	string op[100];
	int i = 0, cnt = 0, num = 0;
	if (nom == "")
	{
		cout << "\t\tIngrese el nombre del archivo -> (op)";
		cin >> nom;
	}
	else
	{
		cout << "\t\tDesea Cambiar de Archivo?\n\t\tNo = ( 0 ) -> ";
		cin >> select;
		if (select != 0)
		{
			cout << "\t\tIngrese el nombre del archivo -> (op)";
			cin >> nom;
		}
	}
	leer.open(nom + ".txt", ios::in);
	if (leer.good())
	{

		do {
			leer >> op[i];
			i++;
			cnt++;
		} while (!leer.eof());
		cout << "\t\tOPERACIONES\n";
		for (int i = 0; i < cnt - 1; i++)
		{
			cout << "\t\t" << i + 1 << ".  " << op[i] << endl;
		}

		cout << "\t\tSeleccione una Operacion -> "; cin >> num;
		system("cls");
		leer.close();
		leer.open(nom + ".txt", ios::in);
		cnt = 0;
		do {
			cnt++;
			leer >> opr;
			if (cnt == num)
			{
				sel = opr;
			}
		} while (!leer.eof());
		cout << "\n\t\tOperacion Seleccionada" << endl;
		cout << "\t\t-> " << sel << endl;

	}
	else
	{
		cout << "\t\tError en el archivo -> " << nom + ".txt" << endl;
	}


	leer.close();
}

void Cargar()
{


	Crear_Vector();



}
void Crear_Vector() {
	string num;//STRING
	string num2, caracter, caracteraux1, caracteraux2;
	char operC[100];//char
	int i = 0, j = 0, ok = 0, ok2 = 0, salir = 0, corr = 0, k = 0, cnt = 0, multi = 0;
	strcpy_s(operC, sel.c_str());
	cout << "\t\t ";
	while (operC[k] != NULL)
	{
		cout << operC[k] << " "; k++;
	}

	while (operC[i] != NULL)
	{
		do
		{
			if (multi != 0)
			{
				i--;
				multi = 0;
				ok2 = 1;
			}
			caracter = operC[i];
			caracteraux1 = operC[i + 1];
			caracteraux2 = operC[i - 1];
			if (caracter == "")
			{
				ok = 0; salir = 1; corr++; i++;
			}
			else if (caracter == "+" || caracter == "-" || caracter == "*" || caracter == "/" || caracter == "^"
				|| caracter == " " || caracter == "(" || caracter == ")" || caracter == "[ " || caracter == " ]"
				|| caracter == "{" || caracter == "}")
			{
				//apertura
				if (caracter == "(" || caracter == "[ " || caracter == "{")
				{

					if (ok2 != 0)
					{
						ok = 0;
						num2 = caracter; salir = 1;
						multi = 0;
					}
					else
					{
						//anterior

						if (caracteraux2 != "+" || caracteraux2 != "-" || caracteraux2 != "*" || caracteraux2 != "/" || caracteraux2 != "^"
							|| caracteraux2 != " " || caracteraux2 != "(" || caracteraux2 != ")" || caracteraux2 != "[ " || caracteraux2 != " ]"
							|| caracteraux2 != "{" || caracteraux2 != "}")
						{
							num2 = "*"; salir = 1; multi = 1;

						}
						else
						{
							num2 = caracter; salir = 1;

						}

					}
					//cerradura	
				}
				else if (caracter == ")" || caracter == " ]" || caracter == "}")
				{

					if (ok2 != 0)
					{
						ok = 0;
						num2 = caracter; salir = 1;
						multi = 0;
					}
					else
					{
						//siguiente


						if (caracteraux1 >= "0")
						{
							num2 = "*"; salir = 1; multi = 1;
						}
						else
						{
							num2 = caracter; salir = 1;
						}

					}

				}
				else
				{
					num2 = caracter; salir = 1;
				}

			}
			else
			{
				if (caracter >= "0"  &&  caracter <= "9")
				{
					ok = 0; corr++; num2 = caracter; num = num + num2; i++;
				}
				else { salir = 1; }
			}
		} while (salir == 0);
		salir = 0;
		//ingreso
		if (ok == 0)
		{
			if (corr == 0)
			{
				oper[j] = num2; i++;
			}
			else
			{
				oper[j] = num; ok = 1;
			}
		}
		else
		{
			oper[j] = num2; ok = 0; i++;
		}
		num = ""; corr = 0; j++;
	}
	tam = j;

	cout << "\n\t\tOPERACION FINAL\n\t\t ";
	for (int i = 0; i<tam; i++)
	{
		cout << oper[i] << " ";
	}
	cout << endl << caracteraux2 << caracteraux1;
}
/*
Gustavo Perez
0901-16-420
Ingenieria en Sitemas
Programacion III
Seccion A
Proyecto: Arbol de Calculo
*/
