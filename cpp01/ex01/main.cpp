#include "Zombie.hpp"

int main() {
    int N = 6; // Number of zombies in the horde
    Zombie* horde = zombieHorde(N, "HordeZombie");
    if (!horde) return 1; // Check for memory allocation failure
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}