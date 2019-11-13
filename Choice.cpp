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
