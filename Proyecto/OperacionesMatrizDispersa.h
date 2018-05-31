#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include"MatrizDispersa.h"

using namespace std;

class OperacionesMatrizDispersa{
	public:
		bool verificarElemento(MatrizDispersa m1, int v);
		vector<int> productoMatrizVector(MatrizDispersa m1, vector<int> temp);
		MatrizDispersa sumaMatrices(MatrizDispersa m1, MatrizDispersa m2);
		int obtenerMayorElemento(MatrizDispersa m1);
		MatrizDispersa matrizTranspuesta(MatrizDispersa m1);
};
