#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

class MatrizCoordenada{
	private:
		vector<int> valores;
		vector<int> filas;
		vector<int> columnas;
		int x, y;
	public:
		MatrizCoordenada(vector< vector<int> > &matriz);
		vector< vector<int> > ObtenerMatrizCompleta();
		vector<int> ObtenerFilas();
		vector<int> ObtenerColumnas();
		vector<int> ObtenerFilaDispersas();
		vector<int> ObtenerColumnasDispersa();
		int ObtenerNumeroElementos();
		void ModificarPosicion(int x, int y, int v);
	
};
