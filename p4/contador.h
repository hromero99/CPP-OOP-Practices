#ifndef _CONTADOR_H_
#define _CONTADOR_H_
#include <list>

class Contador{
    private:
    int valor_;
    int min_;
    int max_;
    std::list <int> values_;
    public: 
    Contador(int valor=0, int min=0, int max = 1000);
    inline void setMin(int newMin){min_ = newMin;}
    inline void setMax(int newMax){max_ = newMax;}
    void setValor(int newValor);
    inline int getMin()const { return min_;}
    inline int getMax()const {return max_;}
    inline int getValor()const { return valor_;}
    inline int get()const {return valor_;}
    Contador operator=(int val);
	int operator=(const Contador &obj);   
    Contador operator++(void);
    Contador operator++(int);
    Contador operator--(void);
    Contador operator--(int);
    friend Contador operator+( Contador & contador, int number);
    friend Contador operator+(int number, Contador & contador);
    friend Contador operator-( Contador & contador, int number);
    friend Contador operator-(int number, Contador & contador);
    bool undo(int numberOperations=1);
};
#endif