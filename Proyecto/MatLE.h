
#ifndef __MD_LISTA
#define __MD_LISTA

#include <iostream>
#include <vector>

using namespace std;

class Nodo{
   public:
     int dato;
     int columna;
     int fila;

   	 Nodo* sig;
};

class MatLE{
	private:
    	int colMat;
      int filMat;

  public:
   	  vector<Nodo> mdLista;

      // Constructoras
   		MatLE();

   		// Modificadoras
      void crearMatDispersa(vector< vector<int> > mat);
   		vector< vector<int> > obtenerMatriz();
   		int obtenerElemento(int fil, int col);
   		vector<int> obtenerFila(int fil);
      vector<int> obtenerColumna(int col);
      vector<int> obtenerFilaD(int fil);
      vector<int> obtenerColumnaD(int col);
      int obtenerNumElem();
      void modificarPosElem(int fil, int col, int elem);

   		// // Analizadoras
   		int obtenerMayorElem();
   		bool verificarElem(int elem);
   		// void sumaMatrices(MatLE &mat);
     //  MatLE matrizVector(vector<int> vec);
     //  MatLE matrizTrans();
};

#endif