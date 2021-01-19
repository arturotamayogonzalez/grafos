//
//  main.c
//  Grafos
//
//  Created by Arturo Tamayo Gonzalez on 18/11/16.
//  Copyright © 2016 Arturo Tamayo Gonzalez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include"grafos.h"
#define SALIR 8

void mostrarMenu();
int seleccionarOpcion();
void ejecutarOpcion(Grafo* g, int opcion);

int main(){
    int opcion;
    Grafo g = grafo_crearGrafo();
    do{
        mostrarMenu();
        opcion = seleccionarOpcion();
        ejecutarOpcion(&g, opcion);
    } while (opcion  != 7);
}

void mostrarMenu(){
    printf("-----Grafos-----\n");
    printf("1.- Agregar vertice\n");
    printf("2.- Agregar arista\n");
    printf("3.- Imprimir grafo\n");
    printf("4.- Revisar arista\n");
    printf("5.- Buscar vertice\n");
    printf("6.- Recorrido DFS\n");
    printf("7.- Recorrido BFS\n");
    printf("%d.- Salir\n", SALIR);
}
int seleccionarOpcion(){
    int opcion;
    printf("Opcion: ");
    scanf("%d", &opcion);
    getchar();
    
    return opcion;
}

void ejecutarOpcion (Grafo* g, int opcion){
    Nodo* n, *m;
    int dato, origen , destino, vertice, inicial ;
    
    switch (opcion) {
        case 1:
            n = malloc(sizeof(Nodo));
            printf("Vertice a agregar: ");
            scanf("%d", &dato);
            n = grafo_crearNodo(dato);
            grafo_agregarVertice(n, g);
            break;
        case 2:
            m = malloc(sizeof(Nodo));
            n = malloc(sizeof(Nodo));
            printf("Dato del que desea agregar arista: ");
            scanf("%d", &origen);
            n = grafo_crearNodo(origen);
            printf("Arista: ");
            scanf("%d", &destino);
            m = grafo_crearNodo(destino);
            grafos_agregarArista(g, n, m);
            break;
        case 3:
            grafo_imprimirGrafo(*g);
            break;
        case 4:
            printf("Arista que desea encontrar:  ");
            scanf("%d", &origen);
            printf("Destino: ");
            scanf("%d", &destino);
            grafo_existeArista(*g, origen, destino);
            break;
        case 5:
            printf("Vertice que desea buscar: ");
            scanf("%d", &vertice);
            grafo_BuscarVertice(*g, vertice);
            break;
        case 6:
            printf("Recorrido DFS\n");
            n= malloc(sizeof(Nodo));
            printf("Dato inicial: ");
            scanf("%d", &inicial);
            n = grafo_crearNodo(inicial);
            grafo_DFS(*g, n);
            break;
        case 7:
            printf("Recorrido BFS\n");
            n=malloc(sizeof(Nodo));
            printf("Nodo inicial: ");
            scanf("%d", &inicial);
            n = grafo_crearNodo(inicial);
            grafo_BFS(*g, *n);
            break;
        case 8:
            break;
    }
}

