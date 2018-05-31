#include "OperacionesMatrizDispersa"

bool MatLE::verificarElem(matrizDispersa m1, int v){
  bool isElem = false;
  int tmp;

  for(int i = 0; i < m1.filMat; i++){
  	for(int j = 0; j < m1.colMat; i++){
  		tmp = m1.obtenerElemento(i, j);
  		if(tmp == v)
  			isElem = true;
  	}
  }
  return isElem;
}

int MatLE::obtenerMayorElem(matrizDispersa m1){
	int mayorElem;
	mayorElem = m1.obtenerElemento(0, 0);

	for(int i = 0; i < m1.filMat; i++){
		for(int j = 0; j < m1.colMat; i++){
			if(m1.obtenerElemento(i, j) < mayorElem)
				mayorElem = m1.obtenerElemento(i, j);
		}
	}

	return mayorElem;  
}
