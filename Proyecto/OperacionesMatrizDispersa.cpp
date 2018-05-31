#include "OperacionesMatrizDispersa"

bool OperacionesMatrizDispersa::verificarElemento(MatrizDispersa m1, int v){
	bool isElem = false;
	int tmp;
	
	for(int i = 0; i < m1.filMat; i++){
		for(int j = 0; j < m1.colMat; i++){
			tmp = m1.obtenerElemento(i, j);
			if(tmp == v){
				isElem = true;
			}
		}
	}
  return isElem;
}

int OperacionesMatrizDispersa::obtenerMayorElemento(MatrizDispersa m1){
	int mayorElem;
	mayorElem = m1.obtenerElemento(0,0);

	for(int i = 0; i < m1.filMat; i++){
		for(int j = 0; j < m1.colMat; i++){
			if(m1.obtenerElemento(i, j) < mayorElem){
				mayorElem = m1.obtenerElemento(i, j);
			}
		}
	}

	return mayorElem;  
}

MatrizDispersa OperacionesMatrizDispersa::matrizTranspuesta(MatrizDispersa m1){
	MatrizDispersa temp;
	
	for(int i = 0; i < m1.filMat; i++){
		for(int j = 0; j < m1.colMat; j++){
			temp.modificarPosicion(i,j,m1.obtenerElemento(j,i));
		}
	}
	
	return temp;
}

MatrizDispersa OperacionMatrizDispersa::sumarMatrices(MatrizDispersa m1, MatrizDispersa m2){
	MatrizDispersa temp;
	
	for(int i = 0; i < m1.filMat; i++){
		for(int j = 0; j < m1.colMat; j++){
			temp.modificarPosicion( i, j, (m1.obtenerElemento(i,j) + m2.obtenerElemento(i,j)));
		}
	}
	return temp;
}
