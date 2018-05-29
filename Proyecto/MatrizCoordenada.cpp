#include 


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
		void ModificarPosicion();
	
};