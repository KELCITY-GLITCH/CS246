#include "Deque.h"

int main()
{
    std::string content, error;
    dsn::Deque<char> stack;

    std::cout << "Enter a string enclosure: ";
    std::getline(std::cin,content);

    for(char i : content)
    {
        if(i == '(' || i == '[' || i == '{' || i == '<')
        {
            stack.insertFirst(i);
        }
        else if(i == ')')
        {
            if(stack.empty())
            {
                error = "Exceeded closing symbol";
                break;
            }
            else if(stack.first() != '(') 
            {
                error = "Mismatch closing symbol";
                break;
            }
            stack.removeFirst();
        }
        else if(i == ']')
        {
            if(stack.empty())
            {
                error = "Exceeded closing symbol";
                break;
            }
            else if(stack.first() != '[') 
            {
                error = "Mismatch closing symbol";
                break;
            }
            stack.removeFirst();
        }
        else if(i == '}')
        {
            if(stack.empty())
            {
                error = "Exceeded closing symbol";
                break;
            }
            else if(stack.first() != '{') 
            {
                error = "Mismatch closing symbol";
                break;
            }
            stack.removeFirst();
        }
        else if(i == '>')
        {
            if(stack.empty())
            {
                error = "Exceeded closing symbol";
                break;
            }
            else if(stack.first() != '<') 
            {
                error = "Mismatch closing symbol";
                break;
            }
            stack.removeFirst();
        }
    }

    if(!stack.empty()) {error = "Unclosed opening symbol";}

    std::cout << "The string " << content << " is ";

    if(stack.empty()) 
    {
        std::cout << "balanced\n";
    }
    else 
    {
        std::cout << " unbalanced. The error " << error << " occurred\n";
    }
    return 0;

}