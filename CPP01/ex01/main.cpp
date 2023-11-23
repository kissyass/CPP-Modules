#include "Zombie.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "enter command id and name: 1 - default, 2 - name zombie, 3 - horde: number of zombies and names\n";
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
        Zombie *horde;
        int num = atoi(argv[2]);
        std::string name = "default zombie";
        if (argv[3])
            name = argv[3];
        horde = zombieHorde(num, name);
        for (int i = 0; i < num; i ++)
            horde[i].announce();
        delete [] horde;
        std::cout << "The horde is deleted\n";
    }
    return (0);
}