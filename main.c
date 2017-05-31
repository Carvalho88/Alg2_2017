#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kruskal.h"

int main()
{
	int V = 5;
	int A = 6;
	struct Grafo* grafo = criaGrafo(V, A);

	grafo->aresta[0].origem = 0;
	grafo->aresta[0].destino = 1;
	grafo->aresta[0].peso = 10;

	grafo->aresta[1].origem = 0;
	grafo->aresta[1].destino = 2;
	grafo->aresta[1].peso = 6;

	grafo->aresta[2].origem = 0;
	grafo->aresta[2].destino = 3;
	grafo->aresta[2].peso = 5;

	grafo->aresta[3].origem = 1;
	grafo->aresta[3].destino = 3;
	grafo->aresta[3].peso = 15;

	grafo->aresta[4].origem = 2;
	grafo->aresta[4].destino = 3;
	grafo->aresta[4].peso = 4;

	grafo->aresta[5].origem = 3;
	grafo->aresta[5].destino = 4;
	grafo->aresta[5].peso = 7;

    Kruskal(grafo);

	return 0;
}
