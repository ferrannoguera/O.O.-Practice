#include "Sector.hpp"

Sector::Sector(){
  eup = 0;
  tantxcent_energia = 0;
  max_cant_prod = 0;
}


Sector::~Sector(){
  
}


int Sector::consultar_EUP() const{
  return eup;
}


int Sector::consultar_max_cant_prod() const{
  return max_cant_prod;
}


int Sector::consultar_tantxcent_energia() const{
  return tantxcent_energia;
}


vector<pair <int,int> > Sector::consultar_dependencies() const{
  return dep;
}


void Sector::llegir_cond_inicials_sector(){
  tantxcent_energia = readint();
  eup = readint();
  max_cant_prod = readint();
  int m = readint();
  dep = vector<pair <int,int> >(m);
  for (int i = 0; i<m; ++i){
    dep[i].first = readint();
    dep[i].second = readint();
  }
}

