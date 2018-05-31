#include"ColumnaCompresa.h"

void crearMatrizDispersa(vector< vector<int> > &mat){
	filMat = mat.size();
	colMat = mat[0].size();
	vector<int> val;
	vector<int> fil;
	vector<int> colComp;
	int temp = 0;
	for(int i = 0; i < mat.size(); i++){
		colComp.push_back(temp);
		for(int j = 0; i < mat.size[i]; j++){
			if(mat[i][j] != 0){
				val.push_back(mat[i][j]);
				fila.push_back(mat[i]);
				temp++;
			}
		}
	}
	valores = val;
	filas = fil;
	comprC = colComp;

}
vector<vector<int>> obtenerMatrizCompleta(){

}
vector<int> obtenerFila(int x){

}
vector<int> obtenerColumna(int x){

}
vector<int> obtenerFilaDispersa(int x){

}
vector<int> obtenerColumnaDispersa(int x){

}
int obtenerNumeroElementos(){

}
int obtenerElemento(int x, int y){

}
void modificarPosicion(int x, int y, int v){

}

