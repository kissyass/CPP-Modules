#include <iostream>
#include <fstream>

std::string replace_string(std::string str, std::string s1, std::string s2)
{
    std::string new_str;
    size_t pos;

    pos = str.find(s1);
    if (pos != std::string::npos)
    {
        new_str = str.substr(0, pos);
        new_str += s2;
        if (pos != str.length())
            new_str += replace_string(str.substr(pos + s1.length()), s1, s2);
    }
    else 
        new_str = str;
    return (new_str);
}

int main(int argc, char **argv)
{
    std::ifstream file;
    std::ofstream file_rep;
    std::string s1;
    std::string s2;
    std::string file_rep_name;
    std::string file_name;
    std::string new_str;

    if (argc != 4)
    {
        std::cout << "Wrong number of arguments\n";
        return (0);
    }

    file_name = argv[1];
    file.open(file_name.c_str());
    if (file.good() == false)
    {
        std::cout << "File doesn't exist\n";
        return (0);
    }
    
    file_rep_name = file_name + ".replace";
    file_rep.open(file_rep_name.c_str());
    if (file_rep.good() == false)
    {
        file.close();
        std::cout << "Impossible to create file\n";
        return(0);
    }

    s1 = argv[2];
    s2 = argv[3];

    while (getline(file, new_str))
        file_rep << replace_string(new_str, s1, s2) << std::endl;
    return (0);
}