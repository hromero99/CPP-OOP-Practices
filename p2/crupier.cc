#include "crupier.h"

Crupier::Crupier(const std::string & dni, const std::string & codigo, const std::string & nombre, const std::string & apellidos , const std::string & direccion, \
    const std::string &localidad, const std::string & provincia,const std::string & pais, int edad) : Persona (dni, nombre, apellidos, provincia, \
    localidad, pais, edad){
        setCodigo(codigo);
    }