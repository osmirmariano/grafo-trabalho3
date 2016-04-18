#include <iostream>
#include <cstdlib>

using namespace std;

class Grafos{
	public:
        int origem, destino, vertice;
        int **matriz, **matrizD, **matrizL, **matrizI, *vetorAresta1, *vetorAresta2;

    public:
    //Construtor
    Grafos(){
    	//void grafo(int nVertice);
    	/*
    	void adicionarVertice(int nVertice);
    	void adicionarAresta(int origem, int destino);*/
    };

    Grafos(int origem, int destino, int vertice){
    	this->origem = origem;
    	this->destino = destino;   	
    	this->vertice = vertice;
    	this->matrizD = matrizD;
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
		if (origem == destino)//Teste para não ter laço em um vértice 
			cout << "Primeiro e segundo vértices são iguais, não é permitido!" << endl;
		else{//Verifica se a aresta já existe
			if((matriz[origem][destino] == 1) || (matriz[destino][origem] == 1))
				cout << "ARESTA: (" << origem << ", " << destino << ") já existe" << endl;
			else{//Cria aresta na matriz
				matriz[origem][destino] = 1;
				matriz[destino][origem] = 1;
				cout << "\t \n ARESTA: (" << origem << ", " << destino << ")" << endl;
			}
		}
    };
	
	/*---------------------------FUNÇÃO MOSTRAR ARESTAS--------------------------*/
    void mostrarArestas(int nVertice){
		for(int x = 1; x <= nVertice; x++){
            for(int y = 1; y <= nVertice; y++){
                if(matriz[y][x] == 1){
                    if (x < y){
                        cout << "(" << x+1 << ", " << y+1 << "); "; 
                    }
                }                       
            }
        }
	};

	void mostarVetoresArestas(int nVertice){
		int k = 0;
		vetorAresta1 = (int*) malloc(nVertice*sizeof(int));
		vetorAresta2 = (int*) malloc(nVertice*sizeof(int));
		for(int x = 1; x <= nVertice; x++){
		    for(int y = 1; y <= nVertice; y++){
		        if(matriz[y][x] == 1){
		            if (x < y){
						vetorAresta1[k] = x;
						vetorAresta2[k] = y;
						k++;
		            }
		        }  
		    }
		}
		
	};

	/*---------------------------FUNÇÃO MOSTRAR MATRIZ ADJACÊNCIA--------------------------*/
	void mostrarAdjacencia(int nVertice){
		for (int x = 1; x <= nVertice; x++){
			cout << "" << endl;
			for (int y = 1; y <= nVertice; y++){
				cout << "     " << matriz[x][y];
			}
			cout << "" << endl;
		}		
	};

	/*---------------------------FUNÇÃO MOSTRAR MATRIZ DIAGONAL---------------------------*/
	void mostrarDiagonal(int nVertice){
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

	void mostrarDiagonalL(int nVertice){
		int cont = 0;
		matrizD = (int **) malloc(nVertice*sizeof(int*));
		for (int x = 1; x <= nVertice; x++){
			matrizD[x] = (int *) malloc(nVertice*sizeof(int));
			for (int y = 1; y <= nVertice; y++){
				matrizD[x][y] = matriz[x][y];
				if(matrizD[x][y] == 1)
					cont++;
			}
			for (int y = 1; y <= nVertice; y++){
				if(x == y){
					matrizD[x][y] = cont;
				}
				else{
					matrizD[x][y] = 0;
				}
			}
			cont = 0;
		}
	};

	/*---------------------------FUNÇÃO MOSTRAR MATRIZ LAPLACIANA---------------------------*/
	void mostrarLaplaciana(int nVertice){
		mostrarDiagonalL(nVertice);
		matrizL = (int **) malloc(nVertice*sizeof(int*));
		for(int x = 1; x <= nVertice; x++){
			cout << "" << endl;
			matrizL[x] = (int *) malloc(nVertice*sizeof(int));
			for (int y = 1; y <= nVertice; y++){
				matrizL[x][y] = (matrizD[x][y]-matriz[x][y]);
				cout << "     " << matrizL[x][y];
			}
			cout << "" << endl;
		}
	};

	
	/*---------------------------FUNÇÃO MOSTRAR MATRIZ INCIDÊNCIA---------------------------*/
	void mostrarIncidencia(int nVertice, int mArestas){
		mostarVetoresArestas(nVertice);
		int  w = 0;
		matrizI = (int **) malloc(nVertice*sizeof(int*));
		for(int x = 1; x <= nVertice; x++){
			matrizI[x] = (int *) malloc(nVertice*sizeof(int));
			cout << " " << endl;
			for(int y = 1; y <= mArestas; y++){
				if( x == vetorAresta1[w] || x == vetorAresta2[w] )
					matrizI[x][y] = 1;
				else
					matrizI[x][y] = 0;
				cout << "     " << matrizI[x][y];
				//cout << "(" << vetorAresta1[w] << ",  " << vetorAresta2[w] << ") ";
				w++;
			}
			w=0;
			cout << " " << endl;
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


















