#include "Zombie.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "enter command id and name: 1 - default, 2 - name zombie, 3 - new zombie, 4 - randomChump\n";
        return (0);
    }
    if (argv[1][0] == '1')
    {
        std::cout << "default zombie naming\n";
        Zombie z1;
        z1.announce();
    }
    else if (argv[1][0] == '2')
    {
        std::cout << "normal zombie naming\n";
        Zombie z1(argv[2]);
        z1.announce();
    }
    else if (argv[1][0] == '3')
    {
        std::cout << "heap zombie naming\n";
        Zombie *z1;
        z1 = newZombie(argv[2]);
        z1->announce();
        delete(z1);
    }
    else if (argv[1][0] == '4')
    {
        std::cout << "random chump zombie naming\n";
        randomChump(argv[2]);
    }
    return (0);
}