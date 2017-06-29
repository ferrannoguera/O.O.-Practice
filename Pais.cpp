#include "Pais.hpp"

Pais::Pais(){
  int m = readint();
  stock = vector<int>(m);
  energia = 0;
}

Pais::~Pais(){
  
}


void Pais::modificar_energia(int energia){
  if ((this->energia + energia) >= 0) this->energia += energia;
  else throw PRO2Excepcio("L'energia no pot ser negativa");
}


void Pais::modificar_unitats_prod(int sector, int stock){
  if (0 < sector and sector <= this->stock.size()) {
    if ((this->stock[sector-1] + stock) >= 0) this->stock[sector-1] += stock;
    else throw PRO2Excepcio("L'stock no pot ser negatiu");
  }
  else throw PRO2Excepcio("El sector no pertany a l'industria");
}


int Pais::consultar_energia() const{
  return energia;
}


int Pais::consultar_industria() const{
  return stock.size();
}


int Pais::consultar_stock(int sector) const{
  if (0 < sector and sector <= stock.size()) return stock[sector-1];
  else throw PRO2Excepcio("El sector no pertany a l'industria");
}


void Pais::escriure_stock(){
  for (int i = 0; i<stock.size(); ++i){
    cout << stock[i];
    if (i+1 != stock.size()) cout << " ";
  }
  cout << endl;
}


void Pais::lectura_conds_ini(){
  energia = readint();
  for (int i = 0; i<stock.size(); ++i){
    cin >> stock[i];
  }
}