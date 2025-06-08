#include <iostream>
#include <string>

bool corect(std::string ip) {
    if (ip >= "0" && ip <= "255")
    {
        int adress = std::stoi(ip);
        return (adress >= 0 && adress <= 255);

    }
    else
    {
        return false;
    }
}

void ipCheck() {
    int pointCount = 3;
    std::string ipNumber;
    std::string ip;
    bool ipCorect = true;
    std::cout << "Input your ip \n";
    std::getline(std::cin, ip);

    for (size_t i = 0; i < ip.length(); i++)
    {
        if (ipCorect)
        {
            if (ip[i]=='.')
            {
                --pointCount;
                ipCorect = corect(ipNumber);
                ipNumber.clear();
            }
            else
            {
                ipNumber += ip[i];
           
            }
        }
    }
    if (pointCount != 0 || ipCorect == false)
    {
        std::cout << "Invalid \n";
    }else std::cout << "Valid \n";
}