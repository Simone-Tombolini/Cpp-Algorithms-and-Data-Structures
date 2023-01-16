//Programmazione C++
//Tombolini Simone 869564
//Esame appello gennaio 2023

#ifndef OUT_OF_BOUND_EXCEPTION_H
#define OUT_OF_BOUND_EXCEPTION_H

#include <stdexcept>
#include <string>
/**
 * @brief Classe rappresentante un eccezzione logica per un indice fuori
 * Questa classe è solo a scopo didattico.
 * Rappresenta un eccezzione custom nel caso, è derivata dalla logic error e ha la possibilità di
 * fornire un messaggio di errore e a che indici della matrice è stata lanciata l'eccezzione.
 * Questa classe non è strettamente necessaria, ma e' utile solo a scopo didattico.
 */
class out_of_bound_exception : public std::logic_error {
	int _z;
	int _y;
	int _x;
public:
	/**
	 * @brief Costruttore dell'eccezzione
	 * Costruiosce una nuova ecccezzione
	 * @param message Messeggio dell'eccezione
	 * @param z punto z
	 * @param y punto y
	 * @param x punto x
	 */
	out_of_bound_exception(const std::string &message, int z, int y, int x);
	/**
 	* @brief Ritorna la posizione x dov'e' avvenuto l'errore
 	* Ritorna la posizione x dov'e' avvenuto l'errore
 	* @return int 
 	*/
	int get_z(void) const;
	/**
 	* @brief Ritorna la posizione y dov'e' avvenuto l'errore
 	* Ritorna la posizione y dov'e' avvenuto l'errore
 	* @return int 
 	*/
	int get_y(void) const;
	/**
 	* @brief Ritorna la posizione z dov'e' avvenuto l'errore
 	* Ritorna la posizione z dov'e' avvenuto l'errore
 	* @return int 
 	*/
	int get_x(void) const;
	
};


#endif