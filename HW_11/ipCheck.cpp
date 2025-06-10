#include <iostream>
#include <string>

bool corect(std::string ip) {
    if (ip.length() > 0 && ip.length() <= 3 &&
        ip.find_first_not_of("0123456789") == std::string::npos)
    {
        if (ip.empty() || (ip.length() > 1 && ip[0] == '0')) {
            return false;
        }
        int adress = std::stoi(ip);
        return (adress >= 0 && adress <= 255);
    }
    else
    {
        return false;
    }
}

int ipCheck() {
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
                if (!ipCorect)
                {
                    std::cout << "Invalid \n";
                    return 1;
                }
                ipNumber.clear();
            }
            else
            {
                ipNumber += ip[i];
           
            }
        }
    }
    if (pointCount != 0 )
    {
        std::cout << "Invalid \n";
    }else std::cout << "Valid \n";
    return 0;
}