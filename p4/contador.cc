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
		values_.push_back(this->valor_);
		setValor(val);
		return *this;
}

int Contador::operator=(const Contador &obj){
    values_.push_back(this->valor_);
	*this=obj.valor_;
	return obj.valor_;
}

Contador Contador::operator++(void){
    values_.push_back(this->valor_);
    setValor( valor_ + 1 );
    return *this;
}
Contador Contador::operator++(int){
    values_.push_back(this->valor_);
    Contador contadorAux = *this;
    setValor( ( getValor() ) + 1 );
    return contadorAux;
}

Contador Contador::operator--(void){
    values_.push_back(this->valor_);
    setValor(valor_ - 1);
    return *this;
}
Contador Contador::operator--(int){
    values_.push_back(this->valor_);
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
    if((contador.get() -number) < contador.min_) contador.valor_ = contador.min_;
	else contador.valor_ -= number;
	contador.values_.emplace_back(contador.get());
	return contador;
}


Contador operator-(int number, Contador &contador) {
	if((number - contador.get()) < contador.min_) contador.valor_ = contador.min_;
	else contador.valor_ -= number;
	contador.values_.emplace_back(contador.get());
	return contador;
}
bool Contador::undo(int numberOperations) {

	if (numberOperations>(int)values_.size() || numberOperations<0){
        return false;
    }
		for (int i = 0; i < numberOperations; ++i){
			values_.pop_back();
		}
		this->valor_=values_.back();
		return true;
}
