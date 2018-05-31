#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<string>


class MatrizDispersa{
	public:
		vector<vector<int>> obtenerMatrizCompleta();
		vector<int> obtenerFilas();
		vector<int> obtenerColumnas();
		vector<int> obtenerFilaDispersas();
		vector<int> obtenerColumnasDispersa();
		int obtenerNumeroElementos();
		void modificarPosicion(int x, int y, int v);

};