#include "Cjt_paisos.hpp"

Cjt_paisos::Cjt_paisos(int n, int c){
  mon = vector<Pais> (n);
  comanda = vector<int> (c);
}


Cjt_paisos::~Cjt_paisos(){
  
}


void Cjt_paisos::llegir_xarxa(Arbre<int> &a, int marca){
  Arbre<int> a1;
  Arbre<int> a2;
  int x;
  cin >> x;
  if (x!= marca) {
    llegir_xarxa(a1, marca);
    llegir_xarxa(a2, marca);
    a.plantar(x,a1,a2);
  }
}


void Cjt_paisos::modificar_energia_pais(int pais, int energia){
  if (0 < pais and mon.size() >= pais) mon[pais-1].modificar_energia(energia);
  else throw PRO2Excepcio("El pais no existeix");
}


void Cjt_paisos::modificar_unitats_prod_pais(int pais, int sector, int stock){
  if (0 < pais and mon.size() >= pais) mon[pais-1].modificar_unitats_prod(sector,stock);
  else throw PRO2Excepcio("El pais no existeix");
}
      
      
void Cjt_paisos::func2 (Arbre<int>& a, int &ets, int &pedido){
  if (not a.es_buit()) {
    if (a.arrel() <= comanda.size()){
      Arbre<int> dre;
      Arbre<int> esq;
      Arbre<int> copia(a);
      copia.fills(esq, dre);
      if (not esq.es_buit() and dre.es_buit()){
	pedido = 0;
	func2(esq, ets, pedido);
	if (ets > 0) {
	  if (comanda[a.arrel()-1] <= ets){
	    mon[a.arrel()-1].modificar_energia(comanda[a.arrel()-1]);
	    pedido += comanda[a.arrel()-1];
	    ets -= comanda[a.arrel()-1];
	  }
	  else {
	    mon[a.arrel()-1].modificar_energia(ets);
	    pedido += ets;
	    ets = 0;
	  }
	}
      }
      else if (not esq.es_buit() and not dre.es_buit()) {
	int ets_esq;
	if (ets%2 != 0) {
	  ets_esq = ets/2;
	  ++ets_esq;
	}
	else ets_esq = ets/2;
	int ets_dre = ets/2;
	int pedido_esq = 0;
	int pedido_dre = 0;
	func2(esq, ets_esq, pedido_esq);
	func2(dre, ets_dre, pedido_dre);
	ets = ets_esq + ets_dre;
	pedido = pedido_esq + pedido_dre;
	if (ets > 0) {
	  if (comanda[a.arrel()-1] <= ets) {
	    mon[a.arrel()-1].modificar_energia(comanda[a.arrel()-1]);
	    pedido += comanda[a.arrel()-1];
	    ets -= comanda[a.arrel()-1];
	  }
	  else {
	    mon[a.arrel()-1].modificar_energia(ets);
	    pedido += ets;
	    ets = 0;
	  }
	}
      }
      else if (esq.es_buit() and dre.es_buit()) {
	if (comanda[a.arrel()-1] <= ets){
	  mon[a.arrel()-1].modificar_energia(comanda[a.arrel()-1]);
	  pedido += comanda[a.arrel()-1];
	  ets -= comanda[a.arrel()-1];
	}
	else {
	  mon[a.arrel()-1].modificar_energia(ets);
	  pedido += ets;
	  ets = 0;
	}
      }
    }
    else {
      Arbre<int>copia(a);
      Arbre<int>esq;
      Arbre<int>dre;
      copia.fills(esq,dre);
      if (not esq.es_buit() and dre.es_buit()) {
	ets += mon[a.arrel()-1].consultar_energia();
	pedido = 0;
	func2(esq, ets, pedido);
	if (pedido > 0) {
	  if (mon[a.arrel()-1].consultar_energia() >= pedido) {
	    mon[a.arrel()-1].modificar_energia(-pedido);
	    pedido = 0;
	  }
	  else {
	    pedido -= mon[a.arrel()-1].consultar_energia();
	    mon[a.arrel()-1].modificar_energia(-mon[a.arrel()-1].consultar_energia());
	  }
	}
      }
      else if (not esq.es_buit() and not dre.es_buit()) {
	int ets_esq = (ets+mon[a.arrel()-1].consultar_energia());
	if (ets_esq%2 != 0) {
	  ets_esq /= 2;
	  ++ets_esq;
	}
	else ets_esq /= 2;
	int ets_dre = (ets+mon[a.arrel()-1].consultar_energia())/2;
	int pedido_esq = 0;
	int pedido_dre = 0;
	func2(esq, ets_esq, pedido_esq);
	func2(dre, ets_dre, pedido_dre);
	pedido = pedido_esq + pedido_dre;
	if (pedido > 0) {
	  int energ_esq = mon[a.arrel()-1].consultar_energia()/2;
	  int energ_dre = mon[a.arrel()-1].consultar_energia()/2;
	  if (mon[a.arrel()-1].consultar_energia()%2 != 0) ++energ_esq;
	  if (energ_esq >= pedido_esq) {
	    mon[a.arrel()-1].modificar_energia(-pedido_esq);
	    pedido_esq = 0;
	  }
	  else {
	    pedido_esq -= energ_esq;
	    mon[a.arrel()-1].modificar_energia(-energ_esq);
	  }
	  if (energ_dre >= pedido_dre) {
	    mon[a.arrel()-1].modificar_energia(-pedido_dre);
	    pedido_dre = 0;
	  }
	  else {
	    pedido_dre -= energ_dre;
	    mon[a.arrel()-1].modificar_energia(-energ_dre);
	  }
	}
	pedido = pedido_esq + pedido_dre;
      }
    }
  }
}


void Cjt_paisos::realitzacio_comanda(){
  Arbre<int>copia(ar_p);
  Arbre<int>dre;
  Arbre<int>esq;
  copia.fills (esq, dre);
  if (not esq.es_buit() and not dre.es_buit()) {
    int ets_esq = mon[ar_p.arrel()-1].consultar_energia()/2;
    int ets_dre = mon[ar_p.arrel()-1].consultar_energia()/2;
    int pedido_esq = 0;
    int pedido_dre = 0;
    if (mon[ar_p.arrel()-1].consultar_energia()%2 != 0) ++ets_esq;
    func2(esq, ets_esq, pedido_esq);
    func2(dre, ets_dre, pedido_dre);
    int pedido = pedido_esq + pedido_dre;
    if (pedido > 0) {
      int energ_esq = mon[ar_p.arrel()-1].consultar_energia()/2;
      int energ_dre = mon[ar_p.arrel()-1].consultar_energia()/2;
      if (mon[ar_p.arrel()-1].consultar_energia()%2 != 0) ++energ_esq;
      if (energ_esq >= pedido_esq) {
	mon[ar_p.arrel()-1].modificar_energia(-pedido_esq);
	pedido_esq = 0;
      }
      else {
	pedido_esq -= energ_esq;
	mon[ar_p.arrel()-1].modificar_energia(-energ_esq);
      }
      if (energ_dre >= pedido_dre) {
	mon[ar_p.arrel()-1].modificar_energia(-pedido_dre);
	pedido_dre = 0;
      }
      else {
	pedido_dre -= energ_dre;
	mon[ar_p.arrel()-1].modificar_energia(-energ_dre);
      }
    }
  }
  else if (not esq.es_buit() and dre.es_buit()) {
    int ets = mon[ar_p.arrel()-1].consultar_energia();
    int pedido = 0;
    func2(esq, ets, pedido);
    if (pedido > 0) {
      if (mon[ar_p.arrel()-1].consultar_energia() >= pedido) {
	mon[ar_p.arrel()-1].modificar_energia(-pedido);
	pedido = 0;
      }
      else {
	pedido -= mon[ar_p.arrel()-1].consultar_energia();
	mon[ar_p.arrel()-1].modificar_energia(-mon[ar_p.arrel()-1].consultar_energia());
      }
    }
  }
}
      


int Cjt_paisos::total_paisos() const{
  return mon.size();
}


int Cjt_paisos::consulta_energia_pais(int pais) const{
  if (0 <= pais and mon.size() > pais) return mon[pais].consultar_energia();
  else throw PRO2Excepcio("El pais no existeix");
}


int Cjt_paisos::consultar_mida_industria() const{
  return mon[0].consultar_industria();
}


int Cjt_paisos::consulta_stock_pais(int pais, int sector) const{
  if (0<= pais and mon.size() > pais) return mon[pais].consultar_stock(sector);
  else throw PRO2Excepcio("El pais no existeix");
}


void Cjt_paisos::crear_xarxa(){
  llegir_xarxa(ar_p, 0);
}


void Cjt_paisos::llegir_cond_inicials(){
  for (int i = 0; i<mon.size(); ++i){
    mon[i].lectura_conds_ini();
  }
}


void Cjt_paisos::llegir_comanda(){
  for (int i = 0; i<comanda.size(); ++i){
    comanda[i] = readint();
  }
}


void Cjt_paisos::escriure_energia_paisos(){
  for (int i = 0; i<mon.size(); ++i){
    cout << mon[i].consultar_energia();
    if (i+1 != mon.size()) cout << " ";
  }
  cout << endl;
}


void Cjt_paisos::escriure_stock_pais(int pais){
  if (0 < pais and mon.size() >= pais) mon[pais-1].escriure_stock();
  else throw PRO2Excepcio("El pais no existeix");
}


  