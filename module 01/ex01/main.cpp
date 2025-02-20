#include "Zombie.hpp"

int main(){
    int N = 10;
    std::string name = "Bar";
    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++){
        horde[i].announce();
    }
    delete[] horde;
}

