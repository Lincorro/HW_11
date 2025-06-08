#include <iostream>
#include <string>

bool corectSymbol(char symbol) {
    if (symbol >= '0' && symbol <= '9' || symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z' || symbol >= '!' && symbol <= '/')
    {
        return true;
    }
    else return false;
}

bool rihtSideCheck(int position, std::string email) {
    bool havePoint = false;
    if (position - email.length() <0 || position - email.length() >= 63)
    {
        return false;
    }
    if (position - email.length() > 1) {
        for (size_t i = position + 1; i < email.length(); i++)
        {
            if (!corectSymbol(email[i]) || email[i] >= 33 && email[i] < 45 || email[i] == 47)
            {
                return false;
            }
            else
            {
                if (email[i] == '.' && havePoint == true)
                {
                    return false;
                }
                else if (email[i] == '.')
                {
                    havePoint = true;
                }
                else
                {
                    havePoint = false;

                    if (!corectSymbol(email[i]) || email[i] >= 33 && email[i] < 45 || email[i] == 47)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }


    
}
bool leftSideCheck(int position, std::string email) {
    bool havePoint = false;
    if (position < 65 && position > 0) {
        for (size_t i = 0; i < position; i++)
        {
            if (!corectSymbol(email[i]))
            {
                return false;
            }
            else
            {
                if (email[i] == '.' && havePoint == true)
                {
                    return false;
                }
                else if (email[i] == '.')
                {
                    havePoint = true;
                }
                else
                {
                    havePoint = false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }

}

void emailCheck( ) {
    std::string email;
    std::cout << "Input your email \n";
    std::getline(std::cin, email);
    bool flag = false;

    for (size_t i = 0; i < email.length(); i++)
    {
        if (email[i] == '@') 
        {
            flag = true;
            if (rihtSideCheck(i, email)  && leftSideCheck(i, email) )
            {
                std::cout << "YES \n";
                exit(0);
            }
            else
            {
                std::cout << "NO \n";
                exit(0);
            }

        }
    }
    if (!flag)
    {
        std::cout << "NO \n";
    }
    
}