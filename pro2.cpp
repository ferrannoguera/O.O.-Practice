#include "Cjt_sectors.hpp"
#include "Cjt_paisos.hpp"

/** @mainpage Practica pro2: Energía e Industria.
    El programa principal es troba situat al fitxer <em>pro2.cpp</em>.
    
    Atenent a les dades de l'enunciat necesitarem 4 classes: una per representar la xarxa de
    paisos que serà <em>Cjt_paisos</em> una altre per representar les caracteristiques
    úniques de cada país, ho farem amb la classe <em>Pais</em>, una més per les propietats que té
    l'indústria, representat per la classe <em>Cjt_sectors</em> i, finalment, una per les
    caracteristiques úniques que té cada sector que es representarà amb la classe <em>Sector</em>.
*/

/** @file pro2.cpp
    @brief Programa principal.
*/

int main() {
  int npaisos = readint();
  int cconsumidors = readint(); 
  Cjt_paisos cp(npaisos, cconsumidors);
  Cjt_sectors cs(cp);
  cp.crear_xarxa(); 
  cp.llegir_cond_inicials(); 
  cs.llegir_prioritat(); 
  cs.llegir_cond_sectors(); 
  int centinella = readint();
  while (centinella != -7) {
    if (centinella == -1) {
      cp.llegir_comanda();
      cp.realitzacio_comanda();
    }
    else if (centinella == -2) {
      cs.cicle_de_produccio(cp);
    }
    else if (centinella == -3) {
      int pais = readint();
      int energia = readint();
      cp.modificar_energia_pais(pais, energia);
    }
    else if (centinella == -4) {
      int pais = readint();
      int sector = readint();
      int stock = readint();
      cp.modificar_unitats_prod_pais(pais, sector, stock);
    }
    else if (centinella == -5) {
      int pais = readint();
      cout << "Stocks del pais " << pais << ":" << endl;
      cp.escriure_stock_pais(pais);
      cout << endl;
    }
    else if (centinella == -6) {
      cout << "Energia de todos los paises: " << endl;
      cp.escriure_energia_paisos();
      cout << endl;
    }
    centinella = readint();
  }
}