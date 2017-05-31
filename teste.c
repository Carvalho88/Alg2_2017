#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aresta
{
	int origem, destino, peso;
};

struct Grafo
{
	int V, A;

	struct Aresta* aresta;
};

struct Grafo* criaGrafo(int V, int A)
{
	struct Grafo* grafo = (struct Grafo*) malloc( sizeof(struct Grafo) );
	grafo->V = V;
	grafo->A = A;

	grafo->aresta = (struct Aresta*) malloc( grafo->A * sizeof( struct Aresta ) );

	return grafo;
}

struct subconjunto
{
	int pai;
	int class;
};

int find(struct subconjunto subconjuntos[], int i)
{
	if (subconjuntos[i].pai != i)
		subconjuntos[i].pai = find(subconjuntos, subconjuntos[i].pai);

	return subconjuntos[i].pai;
}

void Union(struct subconjunto subconjuntos[], int x, int y)
{
	int raiz_x = find(subconjuntos, x);
	int raiz_y = find(subconjuntos, y);

	if (subconjuntos[raiz_x].class < subconjuntos[raiz_y].class)
		subconjuntos[raiz_x].pai = raiz_y;
	else if (subconjuntos[raiz_x].class > subconjuntos[raiz_y].class)
		subconjuntos[raiz_y].pai = raiz_x;

	else
	{
		subconjuntos[raiz_y].pai = raiz_x;
		subconjuntos[raiz_x].class++;
	}
}

int compara(const void* k, const void* w)
{
	struct Aresta* k1 = (struct Aresta*)k;
	struct Aresta* w1 = (struct Aresta*)w;
	return k1->peso > w1->peso;
}


void Kruskal(struct Grafo* grafo)
{
	int V = grafo->V;
	struct Aresta vetor[V];
	int a = 0;
	int i = 0;

	qsort(grafo->aresta, grafo->A, sizeof(grafo->aresta[0]), compara);

	struct subconjunto *subconjuntos =
		(struct subconjunto*) malloc( V * sizeof(struct subconjunto) );

	for (int v = 0; v < V; v++)
	{
		subconjuntos[v].pai = v;
		subconjuntos[v].class = 0;
	} 

	while (a < V - 1)
	{

		struct Aresta prox_aresta = grafo->aresta[i++];

		int x = find(subconjuntos, prox_aresta.origem);
		int y = find(subconjuntos, prox_aresta.destino);

		if (x != y)
		{
			vetor[a++] = prox_aresta;
			Union(subconjuntos, x, y);
		}
	}

	printf("Following are the arestas in the constructed Kruskal\n");
	for (i = 0; i < a; ++i)
		printf("%d -- %d == %d\n", vetor[i].origem, vetor[i].destino,
												vetor[i].peso);
	return;
}

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
