#include "MatLE.h"

MatLE::MatLE(){  
}

void MatLE::crearMatDispersa( vector< vector<int> > mat ){

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

vector< vector<int> > MatLE::obtenerMatriz(){
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
  bool isCero = true;
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

vector<int> MatLE::obtenerFilaD(int i){
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

vector<int> MatLE::obtenerColumnaD(int j){
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

int MatLE::obtenerNumElem(){
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

void MatLE::modificarPosElem(int i, int j, int elem){
  Nodo *nuevo = new Nodo;
  nuevo->dato = elem;
  // nuevo->fila = i;
  // nuevo->columna = j;
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
    cout << "PUSH COMPLETADO" << endl;
  }

  else if(isFila){
    tmp = &mdLista[fila];
    cout << "El primer dato sera " << tmp->dato << " ubicado en " << "( " << tmp->fila << " , " << tmp->columna << " )" << endl;
    // cout << "Pos 2,3 " << tmp->dato << endl;
      // cout << "Y su valor siguiente es " << tmp->sig->dato << endl;
    
    if(j < tmp->columna){
      cout << "FLAG!" << endl;
      cout << "El dato a modificar es " << tmp->dato << " ubicado en " << tmp->fila << " , " << tmp->columna << endl;
      Nodo *aux = new Nodo;
      aux->dato = tmp->dato;
      aux->fila = tmp->fila;
      aux->columna = tmp->columna;
      aux->sig = tmp->sig;
      cout << aux->dato << endl;
      
      nuevo->sig = aux;
      nuevo->fila = i;
      nuevo->columna = j;
      cout << "El dato insertado es " << nuevo->dato << " ubicado en " << nuevo->fila << " , " << nuevo->columna << " y va antes de " << tmp->dato << endl;
      
      mdLista[fila] = *nuevo;
      tmp = &mdLista[fila];
      
      cout << aux->dato << endl;
      tmp->sig = aux;
      cout << "END FLAG!" << endl;
      cout << "La fila quedo ( " << tmp->fila << " , " << tmp-> columna << " ) = " << tmp->dato << " ; ( " << tmp->sig->fila << " , " << tmp->sig->columna << " ) = " << tmp->sig->dato << endl; 
    }

    // else if(j == tmp->columna){
    //   if(elem == 0){
    //     tmp->sig = tmp->sig->sig;          
    //   }

    //   else{
    //     nuevo->sig = tmp->sig->sig;
    //     tmp->sig = nuevo;
    //   }
    // }

    else if(tmp->sig == NULL){
      cout << "FLAG!!" << endl;
      if(j == tmp->columna)
        if(elem == 0){
          cout << "FLAG 0" << endl;
          tmp = NULL;
          mdLista[fila] = *tmp;
          cout << "END FLAG 0" << endl;
        }
        else{
          cout << "FLAG!!!" << endl;
          Nodo *borrar = tmp;
          tmp = nuevo;
          tmp->fila = i;
          tmp->columna = j;
          delete borrar;
          mdLista[fila] = *tmp;
          cout << "END FLAG!!!" << endl;
        }
      else{
        nuevo->columna = j;
        nuevo->fila = i;
        tmp->sig = nuevo;
        cout << "FlAGIV" << endl;
      }
      cout << "END FLAG!!" << endl;
    }

    else{
  //   tmp = &mdLista[fila];
      // cout << "FLAG_1" << endl;
      cout << "FLAG!!!! "  << endl;
      if(tmp->sig->columna > j){
        cout << "FLAG V" << endl;
        nuevo->sig = tmp->sig;
        tmp->sig = nuevo;
        nuevo->fila = i;
        nuevo->columna = j; 
        cout << "END FLAG V" << endl;
      } 

      while(tmp->sig->columna < j){
        cout << "CHANGE NODO" << endl;
        tmp = tmp->sig;
      }


      if(tmp->sig->columna == j){
        if(elem == 0){
          cout << "FLAG 0" << endl;
          tmp->sig = tmp->sig->sig;
          cout << "END FLAG 0" << endl;          
        }

        else{
          cout << "FLAG VI" << endl;
          tmp->sig->dato = nuevo->dato;
          cout << "END FLAG VI" << endl;
        }
      }
      cout << "END FLAG!!!!" << endl;
    }
  }
} 

  //   else{
  //     nuevo->sig = tmp;
  //     nuevo->columna = j;
  //     nuevo->fila = i;
  //   }


  //   else{
  //     nuevo->sig = tmp->sig;
  //     tmp->sig = nuevo;
  //     nuevo->columna = j;
  //     nuevo->fila = i;
  //   }
  // }

int MatLE::obtenerMayorElem(){
  Nodo *tmp = &mdLista[0];
  int mayorElem = tmp->dato;
  int n = mdLista.size();

  for (int i = 0; i < n; i++){
    tmp = &mdLista[i];
    if(mayorElem < tmp->dato)
      mayorElem = tmp->dato;           
    while (tmp->sig != NULL){
      tmp = tmp->sig;
      if(mayorElem < tmp->dato)
        mayorElem = tmp->dato;
    }
  }

  return mayorElem;  
}

bool MatLE::verificarElem(int elem){
  bool isElem = false;
  Nodo *tmp;
  int n = mdLista.size();

  if(elem == 0){
    int fil = 0;
    
    for(int i = 0; i < filMat; i++){
      int col = 0;
      tmp = &mdLista[i];
      if(tmp->fila != fil or tmp->columna != col)
        return true;
      while (tmp->sig != NULL){
        col++;
        tmp = tmp->sig;
        if(tmp->columna != col)
          return true; 
      }

      fil++;
    }
  }

  else {
    for (int i = 0; i < n; i++){
      tmp = &mdLista[i];
      if(tmp->dato == elem)
        isElem = true;           
      while (tmp->sig != NULL){
        tmp = tmp->sig;
        if(tmp->dato == elem)
          isElem = true;
      }
    }
  }
  return isElem;
}

// class operacionesMatricesDispersas{

//   public:
//     vector<Nodo> sumaMatrices(MatLE &matriz1, MatLE &matriz2);
//     vector<Nodo> matrizVector(vector<int> vector);
//     vector<Nodo> matrizTrans();
// };

// MatLE sumaMatrices(MatLE &matriz1, MatLE matriz2){

//   vector<Nodo> m2 = matriz2.mdLista;
//   int n = m2.size();

//   for (int i = 0; i < n; i++){
//     Nodo *tmp = &m2[i];

//     if(matriz1.obtenerElemento(i, tmp->columna) == 0)
//       matriz1.modificarPosElem(i, tmp->columna, tmp->dato);
//     else
//       matriz1.modificarPosElem(i, tmp->columna, tmp->dato + matriz1.obtenerElemento(i, tmp->columna));

//     while (tmp->sig != NULL){
//       tmp = tmp->sig;
//       if(matriz1.obtenerElemento(i, tmp->columna) == 0)
//       matriz1.modificarPosElem(i, tmp->columna, tmp->dato);
//       else
//       matriz1.modificarPosElem(i, tmp->columna, tmp->dato + matriz1.obtenerElemento(i, tmp->columna));
//     }
//   }

//   return matriz1;
// }