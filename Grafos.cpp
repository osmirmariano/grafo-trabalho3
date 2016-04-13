#include <iostream>
#include <cstdlib>

using namespace std;

class Grafos{
	public:
        int origem, destino, vertice, inicio;
        int **matriz, **matrizD, **matrizL, **matrizI;

    public:
    //Construtor
    Grafos(){
    	//void grafo(int nVertice);
    	void adicionarVertice(int nVertice);
    	void adicionarAresta(int origem, int destino);
    };

    Grafos(int origem, int destino, int vertice){
    	this->origem = origem;
    	this->destino = destino;   	
    	this->vertice = vertice;
    }
    
    /*---------------------------FUNÇÃO ADICIONAR VÉRTICES--------------------------*/
    int adicionarVertice(int nVertice){
    	int x, y;
    	matriz = (int **) malloc(nVertice*sizeof(int*));
    	if (matriz == NULL){
    		cout << "Não foi alocado" << endl;
    	}
    	else{
    		for (x = 1; x <= nVertice; x++){
    			matriz[x] = (int *) malloc(nVertice*sizeof(int));
	    		for (y = 1; y <= nVertice; y++){
	    			matriz[x][y] = 0;
	    		}
	    	}
    	}
    };

    /*---------------------------FUNÇÃO ADICIONAR ARESTAS--------------------------*/
    void adicionarAresta(int origem, int destino, int nVertice, int mArestas){
		/*matriz = adicionarVertice(nVertice);*/
		if (origem == destino){
			 //Teste para não ter laço em um vértice 
			cout << "Primeiro e segundo vértices são iguais, não é permitido!" << endl;
		}
		//Verifica se a aresta já existe
		else{
			if((matriz[origem][destino] == 1) || (matriz[destino][origem] == 1))
				cout << "A aresta " << origem << " ----------- " << destino << " já existe" << endl;
			else{
				//Cria aresta na matriz
				matriz[origem][destino] = 1;
				matriz[destino][origem] = 1;
				inicio++;
				cout << "Aresta " << origem << " ----------- " << destino << " criada com sucesso" << endl;
			}
		}
    };
	
	/*---------------------------FUNÇÃO MOSTRAR ARESTAS--------------------------*/
    void mostrarArestas(int origem, int destino, int nVertice, int mArestas){
		if(origem != destino){
			for(origem = 1; origem <= nVertice; origem++){
				for(destino = 1; destino <= mArestas; destino++){
					if(matriz[origem][destino] == 1 && matriz[destino][origem] == 1) 
						cout << "(" << origem << ", " << destino << "); ";
				}

			}
		}
	}

	/*---------------------------FUNÇÃO MOSTRAR MATRIZ ADJACÊNCIA--------------------------*/
	int mostrarAdjacencia(int nVertice){
		for (int x = 1; x <= nVertice; x++){
			cout << "" << endl;
			for (int y = 1; y <= nVertice; y++){
				cout << "     " << matriz[x][y];
			}
			cout << "" << endl;
		}		

	};

	/*---------------------------FUNÇÃO MOSTRAR MATRIZ DIAGONAL---------------------------*/
	int mostrarDiagonal(int nVertice){
		int cont = 0;
		matrizD = (int **) malloc(nVertice*sizeof(int*));
		for (int x = 1; x <= nVertice; x++){
			cout << "" << endl;
			matrizD[x] = (int *) malloc(nVertice*sizeof(int));
			for (int y = 1; y <= nVertice; y++){
				matrizD[x][y] = matriz[x][y];
				if(matrizD[x][y] == 1)
					cont++;
			}
			for (int y = 1; y <= nVertice; y++){
				if(x == y){
					matrizD[x][y] = cont;
					cout << "     " << matrizD[x][y];
				}
				else{
					matrizD[x][y] = 0;
					cout << "     " << matrizD[x][y];
				}
			}
			cont = 0;
			cout << "" << endl;
		}
	};

	/*---------------------------FUNÇÃO MOSTRAR MATRIZ LAPLACIANA---------------------------*/
	int mostrarLaplaciana(int nVertice){
		//matrizLa = mostrarDiagonal(nVertice);
		int x, y;
		matrizL = (int **) malloc(nVertice*sizeof(int*));
		for(x = 1; x <= nVertice; x++){
			matrizL[x] = (int *) malloc(nVertice*sizeof(int));
			cout << "" << endl;
			for (y = 1; y <= nVertice; y++){
				matrizL[x][y] = (matrizD[x][y]-matriz[x][y]);
				cout << "     " << matrizL[x][y];
			}
			cout << "" << endl;
		}
	};

	/*---------------------------FUNÇÃO MOSTRAR MATRIZ INCIDÊNCIA---------------------------*/
	int mostrarIncidencia(int nVertice, int mArestas){
		int x, y;
		matrizI = (int **) malloc(nVertice*sizeof(int*));
		for(x = 1; x <= nVertice; x++){
			matrizI[x] = (int *) malloc(nVertice*sizeof(int));
			for(y = 1; y <= mArestas; y++){
				matrizI[x][y] = matriz[x][y];
				if(matrizI[x][y]==1){
					matrizI[x][y-1] = 1;
				}
				else{
					matrizI[x][y] = 0;
				}
				cout << "     " << matrizI[x][y];
			}
			cout << "" << endl;
		}
	};

	/*---------------------------------FUNÇÃO GRAU VÉRTICE---------------------------------*/
	void grauVertice(int nVertice, int vertice){
		int cont = 0, linha = 0;

		for (int x = 1; x <= nVertice; x++){
			for (int y = 1; y <= nVertice; y++){
				if(matriz[x][y] == 1)
					cont++;
			}
			linha++;
			
			if (vertice == linha){
				cout << "Grau:   " << cont << endl;
			}
			cont = 0;
		}
	};

	/*---------------------------------FUNÇÃO VIZINHANÇA---------------------------------*/
	void vizinhancaVertice(int nVertice, int vertice){
		int linha = 1;
		int vizinho;
		cout << endl << "-------------------------------------------------------"<< endl;
		cout << "Vizinhos: ";
		for(int x = 1; x <= nVertice; x++){
			for(int y = 1; y <= nVertice; y++){
				if(matriz[x][y] == 1 && vertice == linha){
					cout << " " << y;
				}
			}
			linha++;		
		}
	};
};


















