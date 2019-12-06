#include "dados.h"


Dados::Dados(){
    srand(time(NULL));
    dado1_ = 1;
    dado2_ = 1;
    lanzamientos1_ = 0;
    additions1_ =  0;
    additions2_ = 0;
    lanzamientos2_ = 0;
}
void Dados::lanzamiento(){
    dado1_ = ((rand() % 6) + 1);
    dado2_ = ((rand() % 6) + 1);
    lanzamientos2_++;
    lanzamientos1_++;
}
bool Dados::setDado1(int dadoValue){
    if ( (dadoValue < 1) || (dadoValue > 6) ){
        return false;
    }
    for (int i = 4; i > 0; i--) {
      values1[i] = values1[i - 1];
    }
    values1[0] = dadoValue;
    dado1_ = dadoValue;
    additions1_ = additions1_ + dadoValue;
    lanzamientos1_++;
    return true;
}
bool Dados::setDado2(int dadoValue){
    if ( (dadoValue < 1) || (dadoValue > 6) ){
        return false;
    }
    for (int i = 4; i > 0; i--) {
      values2[i] = values2[i - 1];
    }
    values2[0] = dadoValue;
    lanzamientos2_++;
    additions2_ = additions2_ +dadoValue;
    dado2_ = dadoValue;
    return true;
}

float Dados::getMedia1(){
    if (lanzamientos1_ == 0){
        return 0.0;
    }
    additions1_ = additions1_/ lanzamientos1_;
    return additions1_;
}

float Dados::getMedia2(){
    if (lanzamientos2_ == 0){
        return 0.0;
    }
    additions2_ = additions2_/ lanzamientos2_;
    return additions2_;
    
}

int Dados::getDiferencia () {
  int diferencia;
  diferencia = dado1_ - dado2_;
  if (diferencia < 0) {
    diferencia = -1 * diferencia;
  }
  return diferencia;
}

void Dados::getUltimos1 (int (&vector)[5]) {
  for (int i = 0; i < 5; i++) {
    vector[i] = values1[i];
  }
}
void Dados::getUltimos2 (int (&vector)[5]) {
  for (int i = 0; i < 5; i++) {
    vector[i] = values2[i];
  }
}