#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<iterator>

using namespace std;

class MatrizDispersa{
	public:
		int colMat;
		int filMat;
		void crearMatrizDispersa(vector< vector<int> > &mat);
		vector< vector<int> > obtenerMatrizCompleta();
		vector<int> obtenerFila(int x);
		vector<int> obtenerColumna(int x);
		vector<int> obtenerFilaDispersa(int x);
		vector<int> obtenerColumnaDispersa(int x);
		int obtenerNumeroElementos();
		int obtenerElemento(int x, int y);
		void modificarPosicion(int x, int y, int v);
};
