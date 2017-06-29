/** @file Cjt_sectors.hpp
    @brief Especificació de la classe Cjt_sectors
*/

#ifndef CJT_SECTORS_HPP
#define CJT_SECTORS_HPP

//#include "utils.PRO2"
#include "Sector.hpp"
#include "Cjt_paisos.hpp"
//#include <queue>
//#include <vector>

/** @class Cjt_sectors
    @brief Representa l'industria amb el conjunt de sectors i les propietats que tenen
    en commu cadascun d'ells. 
*/

class Cjt_sectors
{
private:
  
  vector<Sector> ind;
  queue<int> prioritat;
  
public:
  /*Constructores*/
  
  /** @brief Creadora de Cjt_sectors.
      \pre Cert.
      \post Es crea una conjunt de Sectors on el total d'aquests ve donat per cp.
  */
  Cjt_sectors(const Cjt_paisos &cp);
  
  
  /** @brief Destructora de Cjt_sectors.
      \pre Cert.
      \post Destrueix l'objecte local.
  */
  ~Cjt_sectors();
  
  
  /*Modificadores*/
  
  
  /** @brief Realitza un cicle de produccio.
      \pre Cert.
      \post Es realitza un cicle de produccio.
  */
  void cicle_de_produccio(Cjt_paisos &cp);
  
  
  /*Consultores*/
  
  
  /*Lectura i Escriptura*/
  
  /** @brief Llectura de tots els sectors per ordre de prioritat.
      \pre Llegeix per ordre de prioritat tots els sectors que hi ha.
      \post S'ha llegit la prioritat entre els sectors.
  */
  void llegir_prioritat();
  
  
  /** @brief Llectura de les condicions de cada sector.
      \pre Llegeix les condicions propies per a cada sector de l'industria.
      \post S'han llegir les condicions caracteristiques de cada sector.
  */
  void llegir_cond_sectors();

};
#endif