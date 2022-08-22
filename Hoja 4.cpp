#include "pch.h"
#include <iostream>
#include <fstream> 
#include <conio.h>
#include <locale.h>

using namespace System;
using namespace std;

struct empleado {
    char nombre[10] = { "Rodrigo" };
    int edad = 27;
    double salario = 1092.54;
};

int main()
{
 
    ofstream archivo1;
    ifstream archivo2;

    empleado emp1, emp2;

    archivo1.open("empleados.dat", ios::out | ios::binary);
    if (archivo1.is_open())
    {
        archivo1.write((char*)&emp1, sizeof(empleado));

        archivo1.close();
    }
    archivo2.open("empleados.dat", ios::in | ios::binary);

    if (archivo2.is_open())
    {

        archivo2.read((char*)&emp2, sizeof(empleado));
        cout << "Nombre del empleado: " << emp2.nombre << endl;
        cout << "Sueldo del empleado: " << emp2.salario << endl;
        cout << "Edad del empleado: " << emp2.edad << endl;

        archivo2.close();
    }
       
    return 0;
}
