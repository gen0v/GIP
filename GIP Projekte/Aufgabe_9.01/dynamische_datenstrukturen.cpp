#include <iostream>
using namespace std;
struct TListenKnoten
{
	int data;
	TListenKnoten *next;
	//Prev
	TListenKnoten *prev;
};
void hinten_anfuegen(TListenKnoten *&anker, const int wert)
{
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr)
		{
		
		//prev
		ptr->next->prev = ptr;
		//
		ptr = ptr->next;
		}
		ptr->next = neuer_eintrag;
		//Selber eingefugt
		neuer_eintrag->prev = ptr;

	}
}
void liste_ausgeben(TListenKnoten * anker)
{
	if (anker == nullptr)
		cout << "Leere Liste." << endl;
	else
	{
		cout << "[ ";
		TListenKnoten *ptr = anker;
		do
		{
			cout << ptr->data;
			if (ptr->next != nullptr) cout << " , ";
			else cout << " ";
			ptr = ptr->next;
		} while (ptr != nullptr);
		cout << "]" << endl;
	}
}

void liste_ausgeben_rueckwaerts(TListenKnoten * anker)
{
	if (anker == nullptr)
		cout << "Leere Liste." << endl;
	else
	{
		cout << "[ ";
		TListenKnoten *ptr = anker;
		TListenKnoten *last;
		do
		{
			//cout << ptr->data;
			//if (ptr->next != nullptr) cout << " , ";
			//else cout << " ";
			last = ptr;
			ptr = ptr->next;
		} while (ptr != nullptr);
		ptr = last;
		do
		{
			cout << ptr->data;
			if (ptr->prev != nullptr) cout << " , ";
			else cout << " ";
			ptr = ptr->prev;
		} while (ptr != nullptr);
		
		cout << "]" << endl;
	}
}


void einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert) {
	//TListenKnoten *temp0 = nullptr, *temp1 = nullptr, *temp2 = nullptr;
	TListenKnoten *temp;

	TListenKnoten *temp0 = new TListenKnoten;
	temp0->next = nullptr;
	temp0->prev = nullptr;

	TListenKnoten *temp1 = new TListenKnoten;
	temp1->next = nullptr;
	temp1->prev = nullptr;

	TListenKnoten *temp2 = new TListenKnoten;
	temp2->next = nullptr;
	temp2->prev = nullptr;


	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert_neu;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;

	if (anker == nullptr)
		//Leere Liste

		anker = neuer_eintrag;
	else
	{

		TListenKnoten *ptr = anker;
		do {
			temp = ptr;
			
			if (ptr != nullptr) {
				if (ptr->data == vor_wert) {
					temp = ptr;
					break;
				}
			}
			ptr = ptr->next;
		}while(ptr != nullptr);
		ptr = temp;

		if (ptr->data == vor_wert && ptr->next != nullptr) {
			//Neuen Wert vorher einfuegen

			temp1->data = wert_neu;
			if (ptr->prev == nullptr) {
				//Neuer Anker
				temp = anker;
				anker = temp1;
				temp1->next = temp;
				temp->prev = temp1;
			}
			else {
			temp0 = ptr->prev;
			temp2 = ptr;

			//liste ab altem Wert hinten einfugen
			temp1->next = temp0->next;
			temp0->next = temp1;
			temp1->prev = temp2->prev;

			temp2->prev = temp1;
			temp1->next = temp2;
			}
		}
		else if (ptr->data == vor_wert && ptr->next == nullptr) {
			temp1->data = wert_neu;
			//letztes Element
			temp0 = ptr->prev;
			temp2 = ptr;

			//liste ab altem Wert hinten einfugen
			temp1->next = temp0->next;
			temp0->next = temp1;
			temp1->prev = temp2->prev;

			temp2->prev = temp1;
			temp1->next = temp2;
		}
		else {
			temp1->data = wert_neu;
			ptr->next = temp1;
			temp1->prev = ptr;
		}

	}
}

int main()
{
	const int laenge = 10;
	TListenKnoten *anker = nullptr;
	for (int i = 0; i < laenge; i++)
		einfuegen(anker, i*i, 9999);
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);
	int wert_neu, vor_wert;
	cout << "Einzufuegender Wert: "; cin >> wert_neu;
	cout << "Vor welchem Wert? "; cin >> vor_wert;
	einfuegen(anker, wert_neu, vor_wert);
	liste_ausgeben(anker);
	liste_ausgeben_rueckwaerts(anker);
	system("PAUSE");
	return 0;
}