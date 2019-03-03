#include "person.h"
#include <string>
#include "texte.h"

using namespace std;

Person extrahiere_person(string eingabezeile)
{
	Person p;
	string rest(eingabezeile.length()+1, ' ');
	
	spalte_ab_erstem(',', eingabezeile, p.name, rest);
	spalte_ab_erstem(',', rest, p.vorname, p.geburtsdatum);
	loesche_leerzeichen(p.name);
	loesche_leerzeichen(p.vorname);
	loesche_leerzeichen(p.geburtsdatum);

	return p;
}
