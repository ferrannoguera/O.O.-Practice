/** @file Cjt_paisos.hpp
    @brief Especificació de la classe Cjt_paisos
*/

#ifndef CJT_PAISOS_HPP
#define CJT_PAISOS_HPP

#include "Pais.hpp"
//#include "Arbre.hpp"
//#include <vector>
//#include <queue>
//#include "utils.PRO2"

/** @class Cjt_paisos
    @brief Representa un conjunt de paisos ordenats en forma de xarxa.

*/
class Cjt_paisos 
{
private:
  
  Arbre<int> ar_p;
  vector<Pais> mon;
  vector<int> comanda;
  /** @brief Lectura de la xarxa de paisos.
      \pre Cert.
      \post Llegeix el conjunt de paisos en forma de xarxa.
  */
  void llegir_xarxa(Arbre<int> &a, int marca);
  /** @brief Realitza una comanda dels Paisos consumidors als paisos productors, actualizant
      l'energia de cadascun d'ells.
      \pre Cert.
      \post S'han realitzat totes les comandes possibles.
  */
  void func2 (Arbre<int>& a, int &ets, int &pedido);

public:
  /*Constructores*/
  /** @brief Constructora de conjunt de paisos.
      S'executa automaticament al crear un Cjt_Paisos
      \pre 0 < c < n.
      \post Crea un conjunt de paisos buit on n determina el nombre de paisos i c el nombre 
      d'aquests que seran consumidors. Cada pais contindra la mida de la seva industria.
  */
  Cjt_paisos(int n, int c);
  

  /** @brief Destructora.
      \pre Cert.
      \post Destrueix l'objecte local.
  */
  ~Cjt_paisos();
  
  /*Modificadores*/
  
  /** @brief Modifica l'energia d'un Pais.
      \pre 0 < pais <= nombre total de paisos.
      \post L'energia del pais augmenta o disminueix en funcio del signe del parametre energia.
  */
  void modificar_energia_pais(int pais, int energia);
  
  
  /** @brief Modifica l'stock del sector del Pais passat per parametres.
      \pre 0 < pais <= nombre total de paisos.
      \post El sector del pais en questio augmenta o disminueix el seu stock en funcio
      del signe del parametre stock.
  */
  void modificar_unitats_prod_pais(int pais, int sector, int stock);
  
  
  /** @brief Realitza una comanda dels Paisos consumidors als paisos productors, actualtizant
      l'energia de cadascun.
      \pre Cert.
      \post S'han realitzat totes les comandes possibles.
  */
  void realitzacio_comanda();
  
  
  /*Consultores*/
  
  /** @brief Consulta el total de paisos que hi ha.
      \pre Cert.
      \post El parametre implicit passa a tenir el valor del total de paisos que hi ha.
  */
  int total_paisos() const;
  
  
  /** @brief Consulta l'energia que te el pais.
      \pre 0 <= pais < total de paisos.
      \post El parametre implicit passa a tenir el valor de l'energia del pais.
  */
  int consulta_energia_pais(int pais) const;
  
  
  /** @brief Consulta el total de sectors.
      \pre Cert.
      \post El parametre implicit passa a tenir el valor del total de sectors que hi ha.
  */
  int consultar_mida_industria() const;
  
  
  /** @brief Consulta l'stock del pais.
      \pre 0 <= pais < total de paisos.
      \post El parametre implicit passa a tenir el valor del stock del pais.
  */
  int consulta_stock_pais(int pais, int sector) const;

  
  /*Entrada i sortida*/
  
  /** @brief Operacio de lectura dels paisos.
      \pre S'organitzen els paisos en forma de xarxa.
      \post El parametre implicit conte el conjunt de paisos llegits pel canal estandard
  */
  void crear_xarxa();
  
  
  /** @brief Operacio de lectura de l'energia i stocks inicials per cada pais
      \pre Llegeix l'energia i els stocks inicials per cada pais.
      \post El pais conte inicialment l'energia i stocks llegits.
  */
  void llegir_cond_inicials();
  
  
  /** @brief Llegeix la comanda dels paisos consumidors.
      \pre Llegeix un total d'enters igual als paisos consumidors.
      \post S'ha llegit la comanda.
  */
  void llegir_comanda();
  
  
  /** @brief Operacio d'escriptura de l'energia dels paisos.
      \pre Cert.
      \post Retorna l'energia de tots els paisos.
  */
  void escriure_energia_paisos();
  
  /** @brief Operacio d'escriptura del stock d'un pais.
      \pre 0 < pais <= total de paisos.
      \post Retorna els stocks de tota l'industria d'un pais.
  */
  void escriure_stock_pais(int pais);
};
#endif
    
    
    
    
    
    
    
    