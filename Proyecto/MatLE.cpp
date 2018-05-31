#include "MatLE.h"

MatLE::MatLE(){  
}

void MatLE::crearMatDispersa( vector< vector<int> > &mat){

  filMat = mat.size();
  colMat = mat[0].size();

  for (int i = 0; i < filMat; i++){
    Nodo* lista = NULL;
    for (int j = 0; j < colMat; j++){
      if(mat[i][j] != 0){
        Nodo* aux = new Nodo;
        aux->dato = mat[i][j];
        aux->columna = j;
        aux->fila = i;
        aux->sig = NULL;

        if (lista == NULL){
          lista = aux;
        }
        else{
          Nodo* tmp = lista;
          while(tmp->sig != NULL)
            tmp = tmp->sig;
          tmp->sig = aux;
        }
      }
    }
    if(lista != NULL){
      mdLista.push_back(*lista);
    }
  }
}

vector< vector<int> > MatLE::obtenerMatrizCompleta(){
  vector<int> columnaTotal;
  for (int i = 0; i < colMat; i++)
    columnaTotal.push_back(0);

  vector< vector<int> > matrizFinal;
  for(int i = 0; i < filMat; i++)
    matrizFinal.push_back(columnaTotal);

  int n = mdLista.size();

  for (int i = 0; i < n; i++){
    Nodo *tmp = &mdLista[i];
    matrizFinal[tmp->fila][tmp->columna] = tmp->dato;
    
    while (tmp->sig != NULL){
      tmp = tmp->sig;
      matrizFinal[tmp->fila][tmp->columna] = tmp->dato;
    }
  }

  return matrizFinal;
}

int MatLE::obtenerElemento(int i, int j){
  Nodo *tmp;
  bool isFila = false;
  int fila;
  
  for(int n = 0; n < mdLista.size(); n++){
    tmp = &mdLista[n];
    if(tmp->fila == i){
      fila = n;
      isFila = true;
    }
  }

  if(!isFila){
    return 0;
  }

  else{
    tmp = &mdLista[fila];
    if(tmp->columna < j){
      while(tmp->sig != NULL){
        tmp = tmp->sig;
        if(tmp->columna == j)
          return tmp->dato;
      }
      return 0;
    }
    else if(tmp->columna == j)
      return tmp->dato;
    else
      return 0;
  }
}

vector<int> MatLE::obtenerFila(int i){
  Nodo *tmp;
  bool isFila = false;
  int fila;

  for(int n = 0; n < mdLista.size(); n++){
    tmp = &mdLista[n];
    if(tmp->fila == i){
      isFila = true;
      fila = n;
    }
  }

  vector<int> filaF;

  if(isFila){
    tmp = &mdLista[fila];
    filaF.push_back(tmp->dato);

    while(tmp->sig != NULL){
      tmp = tmp->sig;
      filaF.push_back(tmp->dato);
    }
  }
  return filaF;
}

vector<int> MatLE::obtenerColumna(int j){
  int n = mdLista.size();
  vector<int> columna;

  for(int i = 0; i < n; i++){
    Nodo *tmp = &mdLista[i];
    
    if(tmp->columna != j){
      while(tmp->sig != NULL){
        tmp = tmp->sig;

        if(tmp->columna == j)
          columna.push_back(tmp->dato);
      }
    }

    else{
      columna.push_back(tmp->dato);
    }
  }

  return columna;
}

vector<int> MatLE::obtenerFilaDispersa(int i){
  vector<int> filaD;
  for(int n = 0; n < colMat; n++){
    filaD.push_back(0);
  }

  Nodo *tmp;
  bool isFila = false;
  int fila;

  for(int n = 0; n < mdLista.size(); n++){
    tmp = &mdLista[n];
    if(tmp->fila == i){
      isFila = true;
      fila = n;
    }
  }

  if(isFila){

    tmp = &mdLista[fila];
    filaD[tmp->columna] = tmp->dato;

    while(tmp->sig != NULL){
      tmp = tmp->sig;
      filaD[tmp->columna] = tmp->dato;
    }
  }
  return filaD;
}

vector<int> MatLE::obtenerColumnaDispersa(int j){
  vector<int> colD;
  for(int n = 0; n < filMat; n++){
    colD.push_back(0);
  }

  int n = mdLista.size();
  for(int i = 0; i < n; i++){
    Nodo *tmp = &mdLista[i];
    
    if(tmp->columna != j){

      while(tmp->sig != NULL){
        tmp = tmp->sig;

        if(tmp->columna == j){
          colD[tmp->fila] = tmp->dato;
        }
      }
    }

    else{
      colD[tmp->fila] = tmp->dato;
    }
  }

  return colD;  
}

int MatLE::obtenerNumeroElementos(){
  int n = mdLista.size();
  int count = 0;
  for(int i = 0; i < n; i++){
    Nodo *tmp = &mdLista[i];
    count++;
    while(tmp->sig != NULL){
      tmp = tmp->sig;
      count++;
    }
  }

  return count;
}

void MatLE::modificarPosicion(int i, int j, int elem){
  Nodo *nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  
  Nodo *tmp;
  bool isFila = false;
  int fila;

  for(int n = 0; n < mdLista.size(); n++){
    tmp = &mdLista[n];
    if(tmp->fila == i){
      isFila = true;
      fila = n;
    }
  }

  if(!isFila){
    nuevo->fila = i;
    nuevo->columna = j;
    mdLista.push_back(*nuevo);
  }

  else if(isFila){
    tmp = &mdLista[fila];
    
    if(j < tmp->columna){
      Nodo *aux = new Nodo;
      aux->dato = tmp->dato;
      aux->fila = tmp->fila;
      aux->columna = tmp->columna;
      aux->sig = tmp->sig;
      cout << aux->dato << endl;
      
      nuevo->sig = aux;
      nuevo->fila = i;
      nuevo->columna = j;
      
      mdLista[fila] = *nuevo;
      tmp = &mdLista[fila];
      
      cout << aux->dato << endl;
      tmp->sig = aux;
    }

    else if(tmp->sig == NULL){
      if(j == tmp->columna)
        if(elem == 0){
          tmp = NULL;
          mdLista[fila] = *tmp;
        }
        else{
          Nodo *borrar = tmp;
          tmp = nuevo;
          tmp->fila = i;
          tmp->columna = j;
          delete borrar;
          mdLista[fila] = *tmp;
        }
      else{
        nuevo->columna = j;
        nuevo->fila = i;
        tmp->sig = nuevo;
      }
    }

    else{
      if(tmp->sig->columna > j){
        nuevo->sig = tmp->sig;
        tmp->sig = nuevo;
        nuevo->fila = i;
        nuevo->columna = j; 
      } 

      while(tmp->sig->columna < j){
        tmp = tmp->sig;
      }


      if(tmp->sig->columna == j){
        if(elem == 0){
          tmp->sig = tmp->sig->sig;
        }

        else{
          tmp->sig->dato = nuevo->dato;
        }
      }
    }
  }
} 