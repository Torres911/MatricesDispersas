#include"ColumnaCompresa.h"

void ColumnaCompresa::crearMatrizDispersa(vector< vector<int> > &mat){
	filMat = mat.size();
	colMat = mat[0].size();
	vector<int> val;
	vector<int> fil;
	vector<int> colComp;
	int temp = 0;
	for(int j = 0; j < colMat; j++){
		colComp.push_back(temp);
		for(int i = 0; i < filMat; i++){
			if(mat[i][j] != 0){
				val.push_back(mat[i][j]);
				fil.push_back(mat[i]);
				temp++;
			}
		}
	}
	valores = val;
	filas = fil;
	comprC = colComp;

}
vector<vector<int>> ColumnaCompresa::obtenerMatrizCompleta(){
	vector<int> ref (colMat, 0);
	vector<vector<int>> matC (filMat, ref);

}
vector<int> ColumnaCompresa::obtenerFila(int x){

}
vector<int> ColumnaCompresa::obtenerColumna(int x){

}
vector<int> ColumnaCompresa::obtenerFilaDispersa(int x){

}
vector<int> ColumnaCompresa::obtenerColumnaDispersa(int x){

}
int ColumnaCompresa::obtenerNumeroElementos(){

}
int ColumnaCompresa::obtenerElemento(int x, int y){

}
void ColumnaCompresa::modificarPosicion(int x, int y, int v){

}

