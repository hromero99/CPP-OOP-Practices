#include "jugador.h"

Jugador::Jugador(const std::string & dni, const std::string & codigo, const std::string & nombre, const std::string & apellidos , int edad, const std::string & direccion, \
    const std::string &localidad, const std::string & provincia,const std::string & pais) : Persona (dni, nombre, apellidos, edad,direccion, \
    localidad,provincia, pais){
    setDNI(dni);
    setCodigo(codigo);
    setDinero(1000);
}
void Jugador::setApuestas(){
    apuestas_.empty();
    std::string value;
    std::ifstream file(getDNI() + ".txt");

    while (getline(file, value, ',')){
        Apuesta ap;
        ap.tipo = std::stoi(value);
        getline(file,value,',');
        ap.valor = value;
        getline(file,value,'\n');
        ap.cantidad = std::stoi(value);
        apuestas_.push_back(ap);
    }
    file.close();
}