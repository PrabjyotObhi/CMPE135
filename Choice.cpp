#include "Choice.h"
#include <string>

wxString choice_to_wxString(Choice choice)
{
    switch (choice)
    {
        case ROCK:     return "Rock";
        case PAPER:    return "Paper";
        case SCISSORS: return "Scissors";
        default:       return "none";
    }
}

std::string choice_to_String(Choice choice)
{
    switch (choice)
    {
        case ROCK:     return "Rock";
        case PAPER:    return "Paper";
        case SCISSORS: return "Scissors";
        default:       return "none";
    }
}

wxString string_to_wxString(std::string str)
{
    std::cout << "str = " << str << std::endl;
    if(str == "Human") return "Human";
    else if (str == "Computer") return "Computer";
    else if (str == "Tie") return "Tie";
    else return "none";
}

wxString int_to_wxString(int score)
{
    return std::to_string(score);
}
