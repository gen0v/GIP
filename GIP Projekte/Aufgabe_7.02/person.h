#pragma once

#include <iostream>
#include <string>

struct Person
{
	std::string vorname;
	std::string name;
	std::string geburtsdatum;
};

Person extrahiere_person(std::string eingabezeile);