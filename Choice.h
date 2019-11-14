#ifndef CHOICE_H_
#define CHOICE_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <string>

// Choice represented by int.
typedef int Choice;

// Which object a player chooses each round.
enum { NONE, ROCK, PAPER, SCISSORS };

/**
 * Convert a chosen object to a wxString.
 * @param choice the object to convert.
 * @return the wxString.
 */
wxString choice_to_wxString(Choice choice);

std::string choice_to_String(Choice choice);

wxString string_to_wxString(std::string str);

wxString int_to_wxString(int score);

// wxString string_to_wxString(string str);

#endif /* CHOICE_H_ */
