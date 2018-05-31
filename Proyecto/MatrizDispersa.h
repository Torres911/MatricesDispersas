#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

class MatrizDispersa{
	private:
		int filMat;
		int colMat;
	public:
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
