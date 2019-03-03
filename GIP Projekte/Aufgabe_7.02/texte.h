#pragma once
#include <string>


void spalte_ab_erstem(char zeichen,
	std::string eingabe,
	std::string& erster_teil,
	std::string& zweiter_teil);

void loesche_leerzeichen(std::string &temp);

void ersetze(std::string& text, char zeichen, std::string text_einfuegen);
