/*
1. El juego de la lotería: Simular un juego de lotería utilizando variables estáticas y
automáticas en C.
2. La Carrera de Coches: Variables de registro (register) en C para simular una
carrera de coches.
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
void act1()
{
    contador_intentos++;
    int numero_jugador;
    generarNumeroLoteria(&numero_jugador, 1, 100);
    if (numero_jugador == numero_ganador)
    {
        printf("Felicidades, ganaste la loteria!\n");
        printf("%d %d\n", numero_ganador, numero_jugador);
        printf("Numero de intentos: %d\n", contador_intentos);
    }
    else
    {
        printf("Lo siento, no ganaste esta vez.\n");
        printf("%d %d\n", numero_ganador, numero_jugador);
    }
}
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
void generarNumeroLoteria(int *numerodeloteria, int ri, int rs)
{
    int x;
    x = (rs - ri) + 1;
    *numerodeloteria = (rand() % x) + ri;
}
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
            printf("Felicidades, ganaste la loteria!\n");
            printf("%d %d\n", numero_ganador, numero_jugador);
            printf("Numero de intentos: %d\n", contador_intentos);
            n = 1;
        }
    } while (n == 0);
}
