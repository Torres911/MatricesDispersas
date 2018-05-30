#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<string>


class MatrizCoordenada{
	private:
		vector<int> valores;
		vector<int> filas;
		vector<int> columnas;
		int x, y;
	public:
		vector<int> ObtenerFilas();
		vector<int> ObtenerColumnas();
		vector<int> ObtenerFilaDispersas();
		vector<int> ObtenerColumnasDispersa();
		int ObtenerNumeroElementos();
		void ModificarPosicion(int x, int y, int v);

};