#include <iostream>
#include "Grafos.cpp"

using namespace std;

int main(int argc, char const *argv[]){
	int op, origem, destino, nVertice, mArestas, vertice; 
	
    Grafos *grafos = new Grafos(origem, destino, vertice);


    cout << endl << "INFORME A QUANTIDADE DE VÉRTICE: " << endl;
    cin >> nVertice;
    
    grafos->adicionarVertice(nVertice);
    
    cout << "INFORME A QUANTIDADE DE ARESTAS: " << endl;
    cin >> mArestas;
    
    for(int x = 0; x < mArestas; x++){
        cout << "-------------------------------------------------------" << endl;
        cout << "INFORME O PRIMEIRO VÉRTICE: " << endl;
        cin >> origem;

        cout << "INFORME O SEGUNDO VÉRTICE: " << endl;
        cin >> destino;
        if((origem > nVertice) || (destino > nVertice))
            cout << "\tO VALOR INFORMADO É SUPERIOR A QUANTIDADE DE VÉRTICES!" << endl;
        else
           grafos->adicionarAresta(origem, destino, nVertice, mArestas); 
    }

    do{
        cout << endl << "-------------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÕES/VISUALIZAÇÕES" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << " 1 -- VISUALIZAR MATRIZ DE ADJACÊNCIA " << endl;
        cout << " 2 -- VISUALIZAR MATRIZ DIAGONAL " << endl;
        cout << " 3 -- VISUALIZAR MATRIZ DE INCIDÊNCIA " << endl;
        cout << " 4 -- VISUALIZAR MATRIZ LAPLACIANA " << endl;
        cout << " 5 -- VISUALIZAR O GRAU DE UM VÉRTICE " << endl;
        cout << " 6 -- VISUALIZAR VIZINHANÇA DE UM VÉRTICE " << endl;
        cout << " 7 -- VISUALIZAR TODAS AS ARESTAS " << endl;
        cout << " 0 -- SAIR " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "OPÇÃO: ";
        cout << endl << "-------------------------------------------------------" << endl;
        cin >> op;

        switch(op){
            case 1:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MATRIZ DE ADJACÊNCIA" << endl;
                cout << "-------------------------------------------------------" << endl;
                if (nVertice == 0 || mArestas == 0)
                    cout << " NÃO FOI DEFINIDO NENHUM TIPO DE GRAFO" << endl;
                else
                    grafos->mostrarAdjacencia(nVertice);
                break;
            case 2:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MATRIZ DIAGONAL" << endl;
                cout << "-------------------------------------------------------" << endl;
                if (nVertice == 0 || mArestas == 0)
                    cout << " NÃO FOI DEFINIDO NENHUM TIPO DE GRAFO" << endl;
                else
                    grafos->mostrarDiagonal(nVertice);
                break;
            case 3:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MATRIZ DE INCIDÊNCIA" << endl;
                cout << "-------------------------------------------------------" << endl;
                if (nVertice == 0 || mArestas == 0)
                    cout << " NÃO FOI DEFINIDO NENHUM TIPO DE GRAFO" << endl;
                else
                    grafos->mostrarIncidencia(nVertice, mArestas);
                break;
            case 4:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t MATRIZ LAPLACIANA" << endl;
                cout << "-------------------------------------------------------" << endl;
                if (nVertice == 0 || mArestas == 0)
                    cout << " NÃO FOI DEFINIDO NENHUM TIPO DE GRAFO!" << endl;
                else
                   grafos->mostrarLaplaciana(nVertice);
                break;
            case 5:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t GRAU DE VÉRTICE" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "INFORME O VÉRTICE QUE DESEJA SABER SEU GRAU: " << endl;
                cin >> vertice;
                if (vertice > nVertice || mArestas == 0 || nVertice == 0)
                    cout << " NÃO FOI DEFINIDO NENHUM TIPO DE GRAFO!" << endl;
                else
                    grafos->grauVertice(nVertice, vertice);
                break;
            case 6:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t VIZINHANÇA DE VÉRTICE" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "INFORME O VÉRTICE QUE DESEJA SABER SUA VIZINHANÇA: " << endl;
                cin >> vertice;
                if (vertice > nVertice || mArestas == 0 || nVertice == 0)
                    cout << endl << " O VALOR ULTRAPASSA O NÚMERO DE VÉRTICES \n OU NÃO FOI DEFINIDO NENHUM GRAFO!" << endl << endl;
                else
                    grafos->vizinhancaVertice(nVertice, vertice);
                break;
            case 7:
                cout << endl << "-------------------------------------------------------" << endl;
                cout << "\t ARESTAS DEFINIDAS" << endl;
                cout << "-------------------------------------------------------" << endl << endl;
                if(mArestas == 0)
                    cout << " NÃO EXISTE NENHUMA ARESTA!" << endl;
                else
                    grafos->mostrarArestas(nVertice);
                break;
            case 0:
                cout << "\t PROGRAMA ENCERRADO COM SUCESSO!\n \t VOLTE EM BREVE!" << endl;
                break;
            default:
                cout << "OPÇÃO INVÁLIDA, DIGITE UMA VÁLIDA POR FAVOR!" << endl;
        };
    }while(op != 0);

	return 0;
};