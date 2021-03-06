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
				fil.push_back(i);
				temp++;
			}
		}
	}
	colComp.push_back(temp);
	valores = val;
	filas = fil;
	comprC = colComp;

}
vector<vector<int>> ColumnaCompresa::obtenerMatrizCompleta(){
	vector<int> ref (colMat, 0);
	vector<vector<int>> matC;
	for(int i = 0; i < filMat; i++){
		matC.push_back(ref);
	}

	int a = 0;
	int b = 0;
	for(int i = 0; i < comprC.size(); i++){
		a = comprC[i + 1] - comprC[i];
		for(int j = 0; j < a; j++){
			matC[filas[b]][i] = valores[b];
			b++;
		}
	}
	for(int i = 0; i < colMat; i++){
		for(int j = 0; i < filMat; j++){
			cout << matC[i][j];
		}
		cout << endl;
	}
	return matC;
}
vector<int> ColumnaCompresa::obtenerFila(int x){
	vector<int> fil;
	for(int i = 0; i < filMat; i++){
		if(filas[i] == x){
			fil.push_back(valores[i]);
		}
	}
	return fil;
}
vector<int> ColumnaCompresa::obtenerColumna(int x){
	vector<int> col;
	for(int i = comprC[x-1]; i < comprC[x]; i++){
		col[i] = valores[i];
	}
}
vector<int> ColumnaCompresa::obtenerFilaDispersa(int x){
	vector<int> filDis;

}
vector<int> ColumnaCompresa::obtenerColumnaDispersa(int x){
	vector<int> colDis (filMat, 0);
	int a = comprC[x + 1] - comprC[x];
	for(int i = 0; i < a; i++){
		colDis[filas[i]] = valores[i];
	}
}
int ColumnaCompresa::obtenerNumeroElementos(){
	return valores.size();
}
int ColumnaCompresa::obtenerElemento(int x, int y){
	int v = 0;
	int a = comprC[y + 1] - comprC[y];
	if(a != 0){
		for(int i = 0; i < a; i++){
			if(filas[i] == x){
				v = valores[i];
			}
		}
	}
	return v;
}
void ColumnaCompresa::modificarPosicion(int x, int y, int v){
	int a = comprC[y + 1] - comprC[y];
	for(int i = 0; i < a; i++){
		if(filas[i] == x){
			valores[i] = v;
		}
	}
}
