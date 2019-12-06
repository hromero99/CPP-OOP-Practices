#ifndef _PERSONA_H_
#define _PERSONA_H_
#include <iostream>
class Persona{
    private:
    std::string dni_;
    std::string nombre_;
    std::string apellidos_;
    std::string direccion_;
    std::string localidad_;
    std::string provincia_;
    std::string pais_;
    int edad_;
    public:
    Persona(const std::string & dni, const std::string & nombre="", const std::string & apellidos ="", int edad=0, const std::string & direccion="", \
    const std::string &localidad="",const std::string & provincia="",const std::string & pais="");
    inline std::string getDNI()const {return dni_;}
    inline std::string getNombre()const {return nombre_;}
    inline std::string getApellidos()const {return apellidos_;}
    inline std::string getDireccion()const {return direccion_;}
    inline std::string getLocalidad()const {return localidad_;}
    inline std::string getProvincia()const {return provincia_;}
    inline std::string getPais()const {return pais_;}
    inline int getEdad()const {return edad_;}
    inline void setDNI(const std::string & dni){dni_ = dni;}
    inline void setNombre(const std::string & nombre){nombre_ = nombre;}
    inline void setApellidos(const std::string &apellidos){apellidos_ = apellidos;}
    inline void setDireccion(const std::string & direccion){direccion_ = direccion;}
    inline void setLocalidad(const std::string & localidad){localidad_ = localidad;}
    inline void setProvincia(const std::string & provincia){provincia_ = provincia;}
    inline void setPais(const std::string & pais){ pais_ = pais;}
    inline bool setEdad(int edad){if (edad >= 0) {edad_ = edad; return true;} return false;}
    inline std::string getApellidosyNombre()const{return getApellidos() +", "+ getNombre();}
    inline bool mayor(){if (edad_ < 18){return false;} return true;}
    };

#endif
