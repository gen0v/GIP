#include "wortspiegel.h"
#include <iostream>

using namespace std;

int anfang, ende;
int position_ = 0;
string gespiegelt = "";
string kopie;
int j = 0;

std::string wortspiegel(std::string &text, int pos)
{
	kopie = text;
	position_ = pos;
	if (kopie.at(position_) == '.' || kopie.at(position_) == ' ') {
		//tue nichts
		return kopie;
	}
	do
	{
		if (position_ > 0) {
			position_ = position_ - 1;
			anfang = position_;
		}
		else {
			anfang = position_;
			break;
		}
		//cout << endl << text.at(position_);
		if (text.at(position_ ) == ' ' || text.at(position_) == '.') {
			break;
		}
	} while (true);
	//nochmal fuer ende
	//cout << endl << "nochmal ende" << text.length();
	position_ = pos;
	do
	{
		if (position_ < text.length()) {
			ende = position_;
			position_ = position_ + 1;
			//ende = position_;
		}
		else {
			ende = position_;
			break;
		}
		//cout << endl << text.at(position_-1);
		if (text.at(position_-1) == ' ' || text.at(position_-1) == '.') {
			break;
		}
	} while (true);// (text.at(position_-1) != ' ' || text.at(position_-1) != '.');

	ende--;

	//cout << "ANFANG " << anfang << " ENDE " << ende;
	//string zum spiegeln erstellen

	//jetzt das Worte vertauschen;
	//j = 0;
	if (anfang > 0) {
		j = anfang+1;
	}else j = anfang;
	gespiegelt = "";
	
	for (int h = ende; h > anfang-1; h--)//-1
	{
		//cout << "A" << h;
		//gespiegelt += text.at(h);
		if (j > ende) {
			
		}else kopie.at(j) = text.at(h);
		//cout << endl << j << " xxx " << text.at(j) << " - " << text.at(h);
		j++;
	}
		//return "Test";
	cout << endl;
	return kopie;
	
}