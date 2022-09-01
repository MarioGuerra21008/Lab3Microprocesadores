/*
* Universidad del Valle de Guatemala
* Programación de Microprocesadores - Sección: 20
* Mario Antonio Guerra Morales - Carné: 21008
* Ejercicio1_Lab3.cpp
* Programa que permita calcular y determinar los números primos entre 0 y un
* valor máximo.
*/

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <cstdint>
using namespace std;

void *calculoNumeros(void *) 

int main() {
    int valMax = 0;
    int hilos = 0;
    int N = 0;
    int res = 0;

    cout<<"Ingrese el valor máximo de su rango de números:"<<endl;
    cin>>valMax;
    cout<<"Ingrese la cantidad de hilos de su programa:"<<endl;
    cin>>hilos;
    
    N = valMax / hilos;
    res = valMax % hilos;
    
    cout<<"Cantidad de valores a evaluar: "<<N<<"\nResiduo: "<<res<<endl;
    
}
