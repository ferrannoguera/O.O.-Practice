/** @file Sector.hpp
    @brief Especificació de la classe Sector
*/
#ifndef SECTOR_HPP
#define SECTOR_HPP

//#include "utils.PRO2"
//#include <vector>

/** @class Sector
    @brief Representa un sector el qual conte les propietats uniques
    per cadascun d'ells en l'industria.
    
*/
class Sector
{
private:
    int eup; 
    int tantxcent_energia; 
    int max_cant_prod; 
    vector<pair<int,int> > dep; 
    
public:
  /*Constructores*/
  
  /** @brief Constructora per defecte
      \pre Cert.
      \post Sector buit.
  */
  Sector();
  
  
  /** @brief Destructora per defecte.
      \pre Cert.
      \post Destrueix l'objecte local.
  */
  ~Sector();
  
  
  /*Modificadores*/
  
  
  /*Consultores*/
  
  
  /** @brief Consulta EUP
      \pre Cert.
      \post El parametre implicit conte l'energia necesaria per unitat.
  */
  int consultar_EUP() const;
  
  
  /** @brief Consulta la produccio maxima.
      \pre Cert.
      \post El parametre implicit conte la produccio maxima per cicle del sector
  */
  int consultar_max_cant_prod() const;
  
  
  /** @brief Consulta el % energia que li correspon
      \pre Cert.
      \post El parametre implicit conte el % d'energia que li correspon al sector.
  */
  int consultar_tantxcent_energia() const;
  
  
  /** @brief Consulta les dependencies del sector.
      \pre Cert.
      \post El parametre implicit passa a valdre les dependencies del sector, donantles en un
      vector de parells on el primer nombre representa el sector del que depen i el segon
      la dependencia que tenen.
  */
  vector<pair <int,int> > consultar_dependencies() const;
  
  
  /*Lectura i Escriptura*/
  
  /** @brief Operacio de lectura de les propietats uniques per cada sector de cada pais.
      \pre Hi ha preparats al canal per llegir com a minim 4 enters no negatius, 
      \post Llegeix les condicions inicials del sector.
  */
  void llegir_cond_inicials_sector();

};
#endif


  
  
  