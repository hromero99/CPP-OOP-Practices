#include "ruleta.h"

Ruleta::Ruleta(const Crupier & crupier){
    banca_ = 1000000;
    bola_ = -1;
    crupier_ = crupier;
}

bool Ruleta::setBola(int newBola){
    if ( (newBola >= 0) && (newBola <= 36)){
        bola_ = newBola;
        return true;
    }
    return false;
}
bool Ruleta::setBanca(int newBanca){
    if (newBanca > 0){
        banca_ =newBanca;
        return true;
    }
    return false;
}
bool Ruleta::addJugador(const Jugador & newJugador){
    std::list<Jugador>::iterator findJugador = std::find(jugadores_.begin(), jugadores_.end(),newJugador);
    if (findJugador == jugadores_.end()){
        return false;
    }

    std::ifstream playerFile(newJugador.getDNI() + ".txt");
    if ( ((bool) playerFile) == false ){
        std::ofstream playerFile(newJugador.getDNI() + ".txt");
        playerFile.close();
    }
    playerFile.close();

}
int Ruleta::deleteJugador(std::string dni){
    if (jugadores_.empty()){
        return -1;
    }
    std::list<Jugador>::iterator it;
    for (it = jugadores_.begin(); it != jugadores_.end(); it++){
        if (it -> getDNI() == dni){
            jugadores_.erase(it);
            return 1;
        }
    }
    return -2;
}
int Ruleta::deleteJugador(const Jugador & toDeleteJugador){
    if (jugadores_.empty()){
        return -1;
    }
    std::list<Jugador>::iterator findJugador = std::find(jugadores_.begin(), jugadores_.end(),toDeleteJugador);
    if (findJugador == jugadores_.end()){
        return -2;
    }

    jugadores_.erase(findJugador);
    return 1;
}
