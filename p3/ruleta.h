#ifndef _RULETA_H_
#define _RULETA_H_
#include "crupier.h"
#include "jugador.h"
#include <algorithm>
#include <fstream>

class Ruleta{
    private:
    int bola_;
    int banca_;
    std::list<Jugador> jugadores_;
    Crupier crupier_;
    public: 
    Ruleta(const Crupier & crupier);
    inline int getBola()const { return bola_;}
    inline int getBanca()const {return banca_;}
    bool setBola(int newBola);
    bool setBanca(int newBanca);
    inline void setCrupier(Crupier newCrupier){ crupier_ = newCrupier};
    inline Crupier getCrupier(){return crupier_;}
    inline std::list<Jugador> getJugadores(){return jugadores_;}
    bool addJugador(const Jugador & newJugador);
    int deleteJugador(std::string dni);
    int deleteJugador(const Jugador & newJugador);

};
#endif