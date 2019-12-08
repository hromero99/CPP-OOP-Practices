#include "contador.h"
Contador::Contador(int valor, int min, int max){
    if(min<max){
		min_=min;
		max_=max;
		if(min_<=valor && valor<=max_) valor_=valor;
		else valor_=0;
	}
	else{
		valor_ = 0;
		min_ =0;
		max_=1000;
	}

}

void Contador::setValor(int newValor){
    if(newValor <= min_){
        valor_ = min_;
    }
    else if(newValor >= max_){
        valor_ = max_;
    }
    else{
        valor_ = newValor;
    }
}


Contador Contador::operator=(int val){
		//values.push_back(this->value);
		setValor(val);
		return *this;
	}

int Contador::operator=(const Contador &obj){
	//values.push_back(this->value);
	*this=obj.valor_;
	return obj.valor_;
}

Contador Contador::operator++(void){
    setValor( valor_ + 1 );
    return *this;
}
Contador Contador::operator++(int){
    Contador contadorAux = *this;
    setValor( ( getValor() ) + 1 );
    return contadorAux;
}

Contador Contador::operator--(void){
    setValor(valor_ - 1);
    return *this;
}
Contador Contador::operator--(int){
    Contador contadorAux = *this;
    setValor( ( getValor() ) - 1 );
    return contadorAux;
}

Contador operator+( Contador & contador, int number){
    contador.setValor(number + contador.getValor());
    return contador;
}
Contador operator+(int number, Contador & contador){
    contador.setValor(number + contador.getValor());
    return contador;
}

Contador operator-( Contador & contador, int number){
    contador.setValor(number - contador.getValor());
    return contador;
    }
Contador operator-(int number, Contador & contador){
    contador.setValor(number - contador.getValor());
    return contador;
}

bool Contador::undo(int numberOperations) {
    return true;
}
