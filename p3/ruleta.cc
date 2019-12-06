#include "ruleta.h"

Ruleta::Ruleta(const Crupier & crupier) : crupier_(crupier){
    banca_ = 1000000;
    bola_ = -1;

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
    //std::list<Jugador>::iterator findJugador = std::find(jugadores_.begin(), jugadores_.end(),newJugador);
    std::list<Jugador>::iterator it;
    for( it = jugadores_.begin(); it != jugadores_.end(); it++){
        if (newJugador.getDNI() == it ->getDNI()){
            return false;
        }
    }
    std::ifstream playerFile(newJugador.getDNI() + ".txt");
    if ( ((bool) playerFile) == false ){
        std::ofstream playerFile(newJugador.getDNI() + ".txt");
        playerFile.close();            
    }
    playerFile.close();
    jugadores_.push_back(newJugador); 
    return true;
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
    //std::list<Jugador>::iterator findJugador = std::find(jugadores_.begin(), jugadores_.end(),toDeleteJugador);
        std::list<Jugador>::iterator it;

    for( it = jugadores_.begin(); it != jugadores_.end(); it++){
        if (toDeleteJugador.getDNI() == it ->getDNI()){
            jugadores_.erase(it);
            return 1;
        }
    }
    
    return -2;
   
}

void Ruleta::escribeJugadores(){
    std::ofstream file("jugadores.txt");
    std::list<Jugador>::iterator it;
    for (it=jugadores_.begin(); it != jugadores_.end(); it++){
        file << it->getDNI() << ","<<it ->getCodigo() << ","<< \
        it-> getNombre() <<"," << \
        it -> getApellidos() <<","<< it -> getDireccion() << "," << \
        it -> getLocalidad() <<","<<it -> getProvincia() <<","<< \
        it -> getPais() <<","<< it -> getDinero()<<std::endl;
    }
    file.close();
}

void Ruleta::leeJugadores(){
    jugadores_.clear();
    std::ifstream file("jugadores.txt");
    Jugador temJugador("DNI", "COD");
    std::list<Jugador>::iterator it;
    std::string value;
    while(getline(file, value, ',')) {
        temJugador.setDNI(value);
        getline(file, value, ',');
        temJugador.setCodigo(value);
        getline(file, value, ',');
        temJugador.setNombre(value);
        getline(file, value, ',');
        temJugador.setApellidos(value);
        getline(file, value, ',');
        temJugador.setDireccion(value);
        getline(file, value, ',');
        temJugador.setLocalidad(value);
        getline(file, value, ',');
        temJugador.setProvincia(value);
        getline(file, value, ',');
        temJugador.setPais(value);
        getline(file, value, '\n');
        temJugador.setDinero(std::stoi(value));      
        jugadores_.push_back(temJugador);
    }
    file.close();
}

void Ruleta::giraRuleta(){
    srand(time(NULL));
    setBola(rand()%37);
}
std::string Ruleta::getColor() {
    if(getBola() == 0) return "0";
    else {
        int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
        for(int i = 0; i < 18; i++) {
            if(getBola() == red[i]) return "rojo";
        }
        return "negro";
    }
}

std::string Ruleta::getParImpar() {
    if(getBola() == 0) return "0";
    else {
        if((getBola() % 2) == 0) return "par";
        else return "impar";
    }
}
std::string Ruleta::getAltoBajo() {
    if(getBola() == 0) return "0";
    else {
        if(getBola() < 18) return "bajo";
        else return "alto";
    }
}

void Ruleta::getPremios(){
    std::list<Jugador>::iterator it;
    //Auxiliar variables used in each player iteration
    std::list<Apuesta>apuestas;
    std::list<Apuesta>::iterator itApuesta;
    
    for(it = jugadores_.begin(); it != jugadores_.end(); it++) {
        it->setApuestas();
        apuestas = it->getApuestas();
        for(itApuesta = apuestas.begin(); itApuesta != apuestas.end(); itApuesta++) {

            switch (itApuesta->tipo) {

                case 1: //Apuesta sencilla
                    if(std::stoi(itApuesta->valor) == getBola()) {
                        int profit = 35 * (itApuesta->cantidad);
                        it->setDinero(it->getDinero() + profit);
                        setBanca(getBanca() - profit);
                    }
                    else {
                        it->setDinero(it->getDinero() - itApuesta->cantidad);
                        setBanca(getBanca() + itApuesta->cantidad);
                    }
                    break;

                case 2: //Apuesta rojo/negro
                    if(itApuesta->valor == getColor()) {
                        it->setDinero(it->getDinero() + itApuesta->cantidad);
                        setBanca(getBanca() - itApuesta->cantidad);
                    }
                    else {
                        it->setDinero(it->getDinero() - itApuesta->cantidad);
                        setBanca(getBanca() + itApuesta->cantidad);
                    }
                    break;

                case 3: //Apuesta par/impar
                    if(itApuesta->valor == getParImpar()) {
                        it->setDinero(it->getDinero() + itApuesta->cantidad);
                        setBanca(getBanca() - itApuesta->cantidad);
                    }
                    else {
                        it->setDinero(it->getDinero() - itApuesta->cantidad);
                        setBanca(getBanca() + itApuesta->cantidad);
                    }
                    break;

                case 4: //Apuesta alto/bajo
                    if(itApuesta->valor == getAltoBajo()) {
                        it->setDinero(it->getDinero() + itApuesta->cantidad);
                        setBanca(getBanca() - itApuesta->cantidad);
                    }
                    else {
                        it->setDinero(it->getDinero() - itApuesta->cantidad);
                        setBanca(getBanca() + itApuesta->cantidad);
                    }
                    break;
            }
        }
    }
}