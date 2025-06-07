#include <iostream>;
#include <string>

char newPosition(char symbol, int newPosition) 
{
    if (symbol >= 'a' && symbol <= 'z') 
    {
        return (((symbol - 'a') + newPosition)%26)+'a';
    }
    else if (symbol >= 'A' && symbol <= 'Z')
    {
        return (((symbol - 'A') + newPosition) % 26) + 'A';
    }
}

void caesar( ) {
    std::string text;
    std::string newText;
    int posirion = 0;
    std::cout << "Input your text(only English) and transfer number \n";
    std::getline(std::cin, text);
    std::cin >> posirion;

    for (int i = 0; i < text.length(); i++) 
    {
        if (text[i] == ' ')
        {
            newText += ' ';
        }
        else
        {
            newText += newPosition( text[i], posirion);
        }
       
       
    }
    std::cout << newText;
}