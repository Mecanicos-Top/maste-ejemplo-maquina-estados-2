#include "mbed.h"
 
/*
   Maquina sencilla de dos estados. Estado ledApagado y estado ledEncendido.
   El led se tiene que encender durante dos segundos cuando se pulse 
   El boton de la placa funciona por nivel bajo
*/
enum estados {apagado, encendido} estado;
 
Timer temporizador;
 
 
DigitalOut led(LED1);
DigitalIn boton(PC_13);
 
void estadoApagado()
{
    if(boton==0) {
        temporizador.reset();
        led=1;
        estado=encendido;
    }
}
 
void estadoEncendido()
{
    if(temporizador.read()>2.0f) {
        led=0;
        estado=apagado;
    }
}
 
int main()
{
    led=0;
    estado=apagado;
    temporizador.reset();
    temporizador.start();
    while(1) {
        switch(estado) {
            case apagado:
                estadoApagado();
                break;
            case encendido:
                estadoEncendido();
                break;
        }
 
    }
}