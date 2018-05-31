#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include"MatrizDispersa.h"
#include"OperacionesMatrizDispersa.h"

using namespace std;

int main(){
	vector< vector<int> > ex {{0,0,4,0},{1,0,0,0},{4,4,4,4},{3,2,1,0},{0,0,0,0}};
    vector< vector<int> > ex2 {{2,4,0,2,},{3,2,1,3},{0,0,0,0},{1,2,3,4},{3,4,4,4}};
    Coordenada c, c1;
    c.crearMatrizDispersa(ex);
    c1.crearMatrizDispersa(ex2);
    c.obtenerMatrizCompleta();
    c1.obtenerMatrizCompleta();
    
	return 0;
}
