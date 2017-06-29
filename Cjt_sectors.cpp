#include "Cjt_sectors.hpp"


Cjt_sectors::Cjt_sectors(const Cjt_paisos &cp){
  int m = cp.consultar_mida_industria();
  ind = vector<Sector> (m);
}


Cjt_sectors::~Cjt_sectors(){
  
}


void Cjt_sectors::cicle_de_produccio(Cjt_paisos &cp){
  for (int i = 0; i<cp.total_paisos(); ++i){
    queue<int>copia(prioritat);
    int energia_modificar = 0;
    vector<int> v(ind.size(),0);
    while (not copia.empty()){
      int sect = copia.front();
      vector<pair <int,int> > dependencies = ind[sect-1].consultar_dependencies();
      int energia_disponible = ((cp.consulta_energia_pais(i)*ind[sect-1].consultar_tantxcent_energia())/100);
      int eup = ind[sect-1].consultar_EUP();
      int max_cant_prod = ind[sect-1].consultar_max_cant_prod();
      bool stop = false;
      while (not stop) {
	if (eup > energia_disponible){
	  stop = true;
	}
	else if (max_cant_prod == v[sect-1]){
	  stop = true;
	}
	else {
	  int j = 0;
	  while (j<dependencies.size() and not stop) {
	    if (cp.consulta_stock_pais(i, dependencies[j].first) < dependencies[j].second){
	      stop = true;
	    }
	    else ++j;
	  }
	}
	if (not stop) {
	  ++v[sect-1];
	  energia_disponible -= eup;
	  energia_modificar += eup;
	  for (int j = 0; j<dependencies.size(); ++j) {
	    cp.modificar_unitats_prod_pais(i+1, dependencies[j].first, -dependencies[j].second);
	  }
	}
      }
      copia.pop();
    }
    for (int j = 0; j<v.size(); ++j) {
      cp.modificar_unitats_prod_pais(i+1, j+1, v[j]);
    }
    cp.modificar_energia_pais(i+1, -energia_modificar);
  }
}



void Cjt_sectors::llegir_prioritat(){
  for (int i = 0; i<ind.size(); ++i){
    int n = readint();
    prioritat.push(n);
  }
}


void Cjt_sectors::llegir_cond_sectors(){
  for (int i = 0; i<ind.size(); ++i){
    ind[i].llegir_cond_inicials_sector();
  }
}