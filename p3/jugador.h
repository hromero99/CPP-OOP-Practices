#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#include "persona.h"
#include <list>
#include <fstream>

typedef struct apuesta{
    int tipo;
    std::string valor;
    int cantidad;
} Apuesta;

class Jugador : public Persona{
    private:
    int dinero_;
    std::string codigo_;
    std::list<Apuesta> apuestas_;
    public: 
    Jugador(const std::string & dni,const std::string & codigo, const std::string & nombre="", const std::string & apellidos ="", int edad=0, \
    const std::string & direccion="", const std::string &localidad="",const std::string & provincia="",const std::string & pais="");
    inline void setDinero(int newDinero){dinero_ = newDinero;}
    inline int getDinero()const { return dinero_;}
    inline void setCodigo(std::string newCodigo){codigo_ = newCodigo;}
    inline std::string getCodigo() {return codigo_;}
    inline std::list<Apuesta> getApuestas(){return apuestas_;}
    void setApuestas();
};
#endif