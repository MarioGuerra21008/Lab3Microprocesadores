/*
* Universidad del Valle de Guatemala
* Programación de Microprocesadores - Sección: 20
* Mario Antonio Guerra Morales - Carné: 21008
* Ejercicio2_Lab3.cpp
* Programa que permita calcular el valor de convergencia de una serie geométrica.
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

struct {
    double i;
    double N;
    double resultado;
    double sumatoria;
} listaVariables;

void *serieNumeros(void *numeros){
    listaVariables.i = 0;
    long tid;
    tid = (long)numeros;
    double valorMax;
    
    for(int i=0;i<valorMax;i++){
        listaVariables.resultado = 1/(listaVariables.N * (listaVariables.N + 1));
        cout<<"El resultado es: "<<listaVariables.resultado<<endl;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;
    double valorMax;
    listaVariables.i = 0;
    listaVariables.N = 1;
    
    cout<<"Ingrese el valor máximo para su serie: "<<endl;
    cin>>valorMax;
    
    for(int i=0;i<valorMax;i++){
        pthread_create(&tid, NULL, serieNumeros, (void*)NULL);
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
        pthread_join(tid,NULL);
        listaVariables.N = listaVariables.N+1;
        listaVariables.sumatoria += listaVariables.resultado;
        if(listaVariables.N==(valorMax+1)){
            cout<<"La sumatoria es: "<<listaVariables.sumatoria<<endl;
        }
    }
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
}
