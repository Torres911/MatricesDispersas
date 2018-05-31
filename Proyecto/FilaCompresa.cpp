#include"FilaCompresa.h"

void FilaCompresa::crearMatrizDispersa(vector< vector<int> > &mat){
	filMat = mat.size();
	colMat = mat[0].size();
	vector<int> val;
	vector<int> col;
	vector<int> filComp;
	int temp = 0;
	for(int i = 0; i < filMat; i++){
		filComp.push_back(temp);
		for(int j = 0; j < colMat; j++){
			if(mat[i][j] != 0){
				val.push_back(mat[i][j]);
				col.push_back(j);
				temp++;
			}
		}
	}
	filComp.push_back(temp);
	valores = val;
	columnas = col;
	comprF = filComp;

}
vector<vector<int>> FilaCompresa::obtenerMatrizCompleta(){
	vector<int> ref (colMat, 0);
	vector<vector<int>> matC;
	for(int k = 0; k < filMat; k++){
		matC.push_back(ref);
	}
	int a = 0;
	int b = 0;
	for(int i = 0; i < comprF.size(); i++){
		a = comprF[i + 1] - comprF[i];
		for(int j = 0; j < a; j++){
			matC[i][columnas[b]] = valores[b];
			b++;
		}
	}
	return matC;
}
vector<int> FilaCompresa::obtenerFila(int x){
	vector<int> fil;
	for(int i = comprF[x-1]; i < comprF[x]; i++){
		fil[i] = valores[i];
	}
	return fil;

}
vector<int> FilaCompresa::obtenerColumna(int x){
	vector<int> col;
	for(int i = 0; i < colMat; i++){
		if(columnas[i] == x){
			col.push_back(valores[i]);
		}
	}
	return col;
}
vector<int> FilaCompresa::obtenerFilaDispersa(int x){
	vector<int> filaDis (colMat, 0);
	int a = comprF[x + 1] - comprF[x];
	for(int i = 0; i < a; i++){
		filaDis[columnas[i]] = valores[i];
	}

}
vector<int> FilaCompresa::obtenerColumnaDispersa(int x){
	vector<int> colDis (colMat, 0);

}
int FilaCompresa::obtenerNumeroElementos(){
	return valores.size();
}
int FilaCompresa::obtenerElemento(int x, int y){
	int v = 0;
	int a = comprF[x + 1] - comprF[x];
	if(a != 0){
		for(int i = 0; i < a; i++){
			if(columnas[i] == y){
				v = valores[i];
			}
		}
	}
}
void FilaCompresa::modificarPosicion(int x, int y, int v){
	int a = comprF[x + 1] - comprF[x];
	for(int i = 0; i < a; i++){
		if(columnas[i] == y){
			valores[i] = v;
			if(v == 0 and valores[i] != 0){

			}
		}
	}
}


int main(){
	vector< vector<int> > ex {{0,0,4,0},
							  {1,0,0,0},
							  {4,4,4,4},
							  {3,2,1,0},
							  {0,0,0,0}};
    vector< vector<int> > ex2 {{2,4,0,2,},{3,2,1,3},{0,0,0,0},{1,2,3,4},{3,4,4,4}};
    FilaCompresa c, c1;
    c.crearMatrizDispersa(ex);
    c1.crearMatrizDispersa(ex2);
    c.obtenerMatrizCompleta();
    c1.obtenerMatrizCompleta();
	return 0;
}

