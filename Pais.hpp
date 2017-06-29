/** @file Pais.hpp
    @brief Especificació de la classe Pais
*/

#ifndef PAIS_HPP
#define PAIS_HPP

//#include <vector>
//#include "utils.PRO2"

/** @class Pais
    @brief Representa un pais, el qual conte energia i l'industria amb cada sector
    i l'stock de cadascun d'ells.

    
*/
class Pais
{
private:
  int energia; //energia del Pais.
  vector<int> stock; //industria del Pais
  
public:
  /*Constructores*/
  
  /** @brief Constructora per defecte
      S'executa automaticament al crear un Pais
      \pre Cert.
      \post Crea un Pais sense energia i amb un nombre determinat de sectors, que es llegeix
      automaticament quan es crida a la creadora, cadascun d'ells sense cap stock inicial.
  */
  Pais();
  
  
  /** @brief Destructora per defecte.
      \pre Cert.
      \post Destrueix l'objecte local.
  */
  ~Pais();
  
  
  /*Modificadores*/
  
  /** @brief Modifica l'energia del Pais.
      \pre energia + energia del pais >= 0.
      \post El pais augmenta o disminueix la seva energia en funcio del signe del parametre
      energia.
  */
  void modificar_energia(int energia);
  
  
  /** @brief Modifica les unitats d'un sector.
      \pre 0 < sector <= total de sectors. stock + stock del sector >= 0.
      \post L'stock del sector augmenta o disminueix en funcio del signe del parametre stock.
  */
  void modificar_unitats_prod(int sector, int stock);

  
  /*Consultores*/
  
  /** @brief Consulta l'energia del Pais.
      \pre Cert.
      \post El parametre implicit conte l'energia del pais.
  */
  int consultar_energia() const;
  
  
  /** @brief Consulta quanta industria hi ha.
      \pre Cert.
      \post El parametre implicit passa a tenir el valor del total de sectors.
  */
  int consultar_industria() const;
  
  
  /** @brief Consulta l'stock.
      \pre 0 < sector <= total de sectors.
      \post El parametre implicit passa a valdre el valor del stock del sector del pais.
  */
  int consultar_stock(int sector) const;
  
  
  /*Lectura i Escriptura*/
  
  /** @brief Lectura de l'energia i els stocks inicials de cada Pais.
      \pre Cert.
      \post Es llegeix l'energia inicial i per cada sector el seu stock inicial.
  */
  void lectura_conds_ini();
  

  /** @brief Operacio d'escriptura de tots els stocks de les m industries del pais.
      \pre Cert.
      \post Escriu tots els stocks de tots els sectors.
  */
  void escriure_stock();
};
#endif
