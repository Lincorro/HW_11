#include <iostream>
#include <string>

bool corect(int ip) {
    return (ip >= 0 && ip <= 255);
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
                ipCorect = corect(std::stoi(ipNumber));
                ipNumber.clear();
            }
            else
            {
                ipNumber += ip[i];
           
            }
        }
    }
    if (pointCount < 0 || ipCorect == false)
    {
        std::cout << "NO \n";
    }else std::cout << "YES \n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}