#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(NULL));
    int number, randomNumber;;
    randomNumber = rand()%10;
    std::cout << "Introduce un número: ";
    std::cin>>number;
  
    if (number < randomNumber){
        std::cout<<"El numero es menor";
    }
    else if(number > randomNumber){
            std::cout<<"El numero es mayor";
    }
    else{
        std::cout<<"El numero es el correcto";
    }

    return 0;
}