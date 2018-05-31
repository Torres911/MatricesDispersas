
#ifndef __MD_LISTA
#define __MD_LISTA

#include "MatrizDispersa.h"


using namespace std;

class Nodo{
   public:
     int dato;
     int columna;
     int fila;

   	 Nodo* sig;
};

class MatLE:public MatrizDispersa{
	 public:
   	  vector<Nodo> mdLista;

      // Constructoras
   		MatLE();

   		// Modificadoras
      void crearMatDispersa(vector< vector<int> > &mat);
   		vector< vector<int> > obtenerMatrizCompleta();
   		int obtenerElemento(int fil, int col);
   		vector<int> obtenerFila(int fil);
      vector<int> obtenerColumna(int col);
      vector<int> obtenerFilaDispersa(int fil);
      vector<int> obtenerColumnaDispersa(int col);
      int obtenerNumeroElementos();
      void modificarPosicion(int fil, int col, int elem);
};

#endif
