/*
Nombre del archivo: practica5.c
Descripción: programa que tiene 3 opciones, juego de loteria, carrera de coches y ganar loteria y ver intentos.
Autor: Daniel Rios Rodriguez
Fecha de creación: 12 de Noviembre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RRD.h"
static int numero_ganador = 43;
static int contador_intentos = 0;
void generarNumeroLoteria(int *numerodeloteria, int ri, int rs);
void act1();
void act2();
void act3();

int main()
{
    srand(time(NULL));
    int act, menu;
    do
    {
        act = validarnumeros("1.-El juego de la loterIa\n2.-La Carrera de Coches\n3.-Ganar loteria y ver intentos\n", 1, 3);
        switch (act)
        {
        case 1:
            act1();
            menu = repetir();
            system("cls");
            break;
        case 2:
            act2();
            menu = repetir();
            system("cls");
            break;
        case 3:
            act3();
            menu = repetir();
            system("cls");

            break;
        }
    } while (menu == 1);
}
/*
Función: generarNumeroLoteria
Descripción: Genera un número aleatorio entre un rango dado y lo asigna a la variable numerodeloteria.
Parámetros:
- numerodeloteria: Puntero a la variable donde se almacenará el número generado.
- ri: Límite inferior del rango.
- rs: Límite superior del rango.
Valor de retorno: Ninguno.
*/
void generarNumeroLoteria(int *numerodeloteria, int ri, int rs)
{
    int x;
    x = (rs - ri) + 1;
    *numerodeloteria = (rand() % x) + ri;
}

/*
Función: act1
Descripción: Simula el juego de la lotería, generando un número aleatorio para el jugador y comparándolo con un número ganador predefinido.
Incrementa el contador de intentos.
Parámetros: Ninguno.
Valor de retorno: Ninguno.
*/
void act1()
{
    contador_intentos++;
    int numero_jugador;
    generarNumeroLoteria(&numero_jugador, 1, 100);
    if (numero_jugador == numero_ganador)
    {
        printf("Felicidades, ganaste la lotería!\n");
        printf("%d %d\n", numero_ganador, numero_jugador);
        printf("Número de intentos: %d\n", contador_intentos);
    }
    else
    {
        printf("Lo siento, no ganaste esta vez.\n");
        printf("%d %d\n", numero_ganador, numero_jugador);
    }
}

/*
Función: act2
Descripción: Simula una carrera de coches, generando velocidades aleatorias para tres coches y calculando el tiempo que les toma recorrer 1000 metros.
Imprime los resultados y determina el ganador basándose en el tiempo más bajo.
Parámetros: Ninguno.
Valor de retorno: Ninguno.
*/
void act2()
{
    register int coche1, coche2, coche3;
    coche1 = rand() % 101 + 100; // Velocidad entre 100 y 200 km/h
    coche2 = rand() % 101 + 100;
    coche3 = rand() % 101 + 100;

    // Calcular el tiempo que le toma a cada coche recorrer 1000 metros
    float tiempo1, tiempo2, tiempo3;

    tiempo1 = 1000.0 / (coche1 / 3.6); // Convertir km/h a m/s
    tiempo2 = 1000.0 / (coche2 / 3.6);
    tiempo3 = 1000.0 / (coche3 / 3.6);
    printf("DISTANCIA 1000 metros\n");
    printf("coche1 a %d km/h tarda %.2f segundos\n", coche1, tiempo1);
    printf("coche2 a %d km/h tarda %.2f segundos\n", coche2, tiempo2);
    printf("coche3 a %d km/h tarda %.2f segundos\n", coche3, tiempo3);

    if (tiempo1 < tiempo2 && tiempo1 < tiempo3)
    {
        printf("coche 1 Ganara la carrera\n");
    }
    if (tiempo2 < tiempo1 && tiempo2 < tiempo3)
    {
        printf("coche 2 Ganara la carrera\n");
    }
    if (tiempo3 < tiempo1 && tiempo3 < tiempo2)
    {
        printf("coche 3 Ganara la carrera\n");
    }
}

/*
Función: act3
Descripción: Similar a act1, pero repite el proceso hasta que el jugador gane la lotería.
Incrementa el contador de intentos en cada intento.
Parámetros: Ninguno.
Valor de retorno: Ninguno.
*/
void act3()
{
    int numero_jugador, n;
    do
    {
        n = 0;
        contador_intentos++;

        generarNumeroLoteria(&numero_jugador, 1, 100);
        if (numero_jugador == numero_ganador)
        {
            printf("Felicidades, ganaste la lotería!\n");
            printf("%d %d\n", numero_ganador, numero_jugador);
            printf("Número de intentos: %d\n", contador_intentos);
            n = 1;
        }
    } while (n == 0);
}
