#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<string>


class MatrizDispersa{
	public:
		vector<vector<int>> ObtenerMatrizCompleta();
		vector<int> ObtenerFilas();
		vector<int> ObtenerColumnas();
		vector<int> ObtenerFilaDispersas();
		vector<int> ObtenerColumnasDispersa();
		int ObtenerNumeroElementos();
		void ModificarPosicion(int x, int y, int v);

};