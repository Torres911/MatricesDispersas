#include "Coordenada.h"

Coordenada::Coordenada(){
}

void Coordenada::crearMatrizDispersa(vector< vector<int> > &mat){
	for(int i = 0; i < mat.size(); i++){
		for(int j = 0; j < mat[i].size(); j++){
			if(mat[i][j] != 0){
				valores.push_back(mat[i][j]);
				columna.push_back(j);
				fila.push_back(i);
			}
		}
	}
}

vector< vector<int> > Coordenada::obtenerMatrizCompleta(){
	int h = 0;
    vector<vector<int> >matriz(fila.size());
    for (int i = 0; i < fila.size(); i++){
            matriz[i].resize(columna.size());
    }
    for (int i = 0; i < fila.size(); i++){
        for (int j = 0; j < columna.size(); j++){
            if (fila[h] == i && columna[h] == j){
                matriz[i][j] = valores[h];
                h++;
            }else{
            	matriz[i][j] = 0;
			}
        }
    }
    return matriz;
}

vector<int> Coordenada::obtenerFila(int x){
	vector<int> temp;
	int j = 0;
	for(int i = 0; i < fila.size(); i++){
		if(fila[i] == x){
			temp.push_back(valores[i]);
			j++;
		}
	}

	return temp;
}

vector<int> Coordenada::obtenerColumna(int x){
	vector<int> temp;
	int j = 0;
	for(int i = 0; i < columna.size(); i++){
		if(columna[i] == x){
			temp.push_back(valores[i]);
			j++;
		}
	}

	return temp;
}

vector<int> Coordenada::obtenerFilaDispersa(int x){
	vector<int> temp;
	for(int i = 0; i < fila.size(); i++){
		temp[i] = 0;
	}

	for(int i = 0; i < fila.size(); i++){
		if(fila[i] == x){
			temp.push_back(valores[i]);
		}
	}

	return temp;
}

vector<int> Coordenada::obtenerColumnaDispersa(int x){
	vector<int> temp;
	for(int i = 0; i < columna.size(); i++){
		temp[i] = 0;
	}

	for(int i = 0; i < columna.size(); i++){
		if(columna[i] == x){
			temp.push_back(valores[i]);
		}
	}

	return temp;
}

int Coordenada::obtenerNumeroElementos(){
	return valores.size();
}

int Coordenada::obtenerElemento(int x, int y){
	int temp;
	for(int i = 0; i < valores.size(); i++){
		if(fila[i] == x && columna[i] == y){
			temp = valores[i];
		}
	}
	return temp;
}

void Coordenada::modificarPosicion(int x, int y, int v){
	bool flag = false;
	for(int i = 0; i < valores.size(); i++){
		if(fila[i] == x && columna[i] == y){
			valores[i] = v;
			flag = true;			
		}
	}
	
	if(!flag){
		valores.push_back(v);
		columna.push_back(y);
		fila.push_back(x);
	}	
}
