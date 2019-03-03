#include<iostream>
#include<string>
#include "texte.h"


using namespace std;

bool gefunden = false;

void spalte_ab_erstem(char zeichen,string eingabe,string& erster_teil,string& zweiter_teil) {

	gefunden = false;
	for (int i = 0; i < eingabe.length(); i++)
	{
		if (eingabe.at(i) == zeichen && gefunden == false) {
			gefunden = true;
			//erster Teil
			for (int a = 0; a < i; a++)
			{
				//erster_teil.at(a) = eingabe.at(a);
				erster_teil+= eingabe.at(a);
			}
			//zweiter Teil
			for (int b = 0; b < eingabe.length(); b++)
			{
				if (b > i) {
					//zweiter_teil.at(b) = eingabe.at(b);
					zweiter_teil += eingabe.at(b);
				}
			}
		}
	}

	if (gefunden == false) {
		for (int i = 0; i < eingabe.length(); i++)
		{
				//erster_teil.at(i) = eingabe.at(i);
				erster_teil += eingabe.at(i);
			
		}
	}


}

void loesche_leerzeichen(string &temp) {
	string verbessert;
	int counter = 0;
	for (int i = 0; i < temp.length(); i++)
	{
		if ((temp.at(i) == ' ' || temp.at(i) == '\t' || temp.at(i) == '\r' || temp.at(i) == '\n')) {
			if (counter < 1) {
				verbessert += ' ';
			}
			counter++;
		}else verbessert += temp.at(i);
			
	}

	temp = verbessert;
}

void ersetze(string & text, char zeichen, string text_einfuegen)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (text.at(i) == zeichen) {
			text.at(i) = ' ';
			text = text + text_einfuegen;
		}
	}
}
