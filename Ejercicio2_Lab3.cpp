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

void *serieNumeros(void *numeros){
    int i;
    int N;
    int valorMax;
    int resultado = 0;
    int sumatoria = 0;
    long tid;
    tid = (long)numeros;
    
    for(int i=0;i<valorMax;i++){
        resultado = 3 / 2^(N);
        cout<<"El resultado es: "<<resultado<<endl;
        sumatoria += resultado;
        N++;
        if(N == valorMax){
            cout<<"La sumatoria total es de: "<<sumatoria<<endl;
            pthread_exit(NULL);
        }
    }
    pthread_exit(NULL);
}

int main() {
    int valorMax;
    pthread_t tid;
    int i;
    
    cout<<"Ingrese el valor máximo para su serie: "<<endl;
    cin>>valorMax;
    
    for(int i=0;i<valorMax;i++){
        pthread_create(&tid, NULL, serieNumeros, (void*)NULL);
        
        pthread_join(tid,NULL);
        if(i==valorMax){
            pthread_exit(NULL);
        }
    }
    
}
