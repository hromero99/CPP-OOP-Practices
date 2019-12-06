#ifndef _DADOS_H_
#define _DADOS_H_

#include <ctime>
#include <cstdlib>

class Dados{
    private:
        int dado1_;
        int values1[5];
        int lanzamientos1_;
        int additions1_;
        int dado2_;
        int values2[5];
        int lanzamientos2_;
        int additions2_;
    public:
    Dados();
    inline int getDado1(){return dado1_;}
    inline int getDado2(){return dado2_;}
    void lanzamiento();
    bool setDado1(int dadoValue);
    bool setDado2(int dadoValue);
    inline int getSuma(){return dado1_ + dado2_;}
    inline int getLanzamientos1(){return lanzamientos1_;}
    inline int getLanzamientos2(){return lanzamientos2_;}
    int getDiferencia();
    float getMedia1();
    float getMedia2();
    void getUltimos1 (int (&vector)[5]);
    void getUltimos2 (int (&vector)[5]);
    };
#endif