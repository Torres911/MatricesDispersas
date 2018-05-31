#include"MatrizDispersa.h"

class ColumnaCompresa: public MatrizDispersa{
	private:
		vector<int> valores;
		vector<int> columnas;
		vector<int> compr;
	public:
		vector<vector<int>> obtenerMatrizCompleta();
		vector<int> obtenerFila(int x);
		vector<int> obtenerColumna(int x);
		vector<int> obtenerFilaDispersa(int x);
		vector<int> obtenerColumnaDispersa(int x);
		int obtenerNumeroElementos();
		int obtenerElemento(int x, int y);
		void modificarPosicion(int x, int y, int v);
};