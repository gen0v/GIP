#include <iostream>
#include "binaerer_suchbaum.h"




void suchbaum::einfuegen(BaumKnoten* root, int wert) {
	//Einfuegen
	if (root->elternknoten == true) {
		root->wert = wert;
		root->elternknoten = false;
	}
		if(root->wert == wert) {
			//Doppel - tue nichts
		}
		else if (root->wert > wert) {
			//Elternwert groesser als Kindwert
			//Neuer Root rekursiv
			if (root->links == nullptr) {
				//falls links nicht existiert
				//erzeuge neuen Linksknoten
				BaumKnoten *neu = new BaumKnoten;
				neu->wert = wert;
				neu->links = nullptr;
				neu->rechts = nullptr;
				//root drauf verlinken
				root->links = neu;
			}
			//falls links doch existiert dann rekursiv weiter
			einfuegen(root->links, wert);

		}
		else if (root->wert < wert) {
			//Elternwert kleiner als Kindwert
			//Neuer Root rekursiv
			if (root->rechts == nullptr) {
				//falls links nicht existiert
				//erzeuge neuen Rechtsknoten
				BaumKnoten *neu = new BaumKnoten;
				neu->wert = wert;
				neu->links = nullptr;
				neu->rechts = nullptr;
				//root drauf verlinken
				root->rechts = neu;
			}
			//falls links doch existiert dann rekursiv weiter
			einfuegen(root->rechts, wert);
		}

	}

	void suchbaum::ausgeben(BaumKnoten* knoten, int tiefe) {
		int temp = tiefe;
		

		if (knoten->rechts != nullptr) {
			//weiter nach rechts
			//std::cout << "++";
			suchbaum::ausgeben(knoten->rechts, tiefe+1);
		}
		//nicht weiter nach rechts
		//Pluse fehlen
		for (int i = 0; i < temp; i++)
		{
			std::cout << "++";
		}
	
		if (knoten->wert == NULL) {
			std::cout << "Leerer Baum.\n";
		}
		else std::cout << knoten->wert<< std::endl;
		
		if (knoten->links != nullptr)
		{

			//std::cout << "++";
			suchbaum::ausgeben(knoten->links, tiefe+1);
		}
		
		
		
		
		
		
		
		/*	//Zuerst rechter Teilbaum
		if (knoten->rechts == nullptr) {
			//mache nichts erstmal
		}
		//Dann Knoten Selbst
		else {
			for (int i = 0; i < tiefe; i++)
			{
				std::cout << "++";
			}
			suchbaum::ausgeben(knoten->rechts, tiefe++);
			tiefe--;
		}
		//Dann Linker Teilbaum
		if (knoten->links == nullptr) {
			//mache erstmal nichts
		}
		else {
			for (int i = 0; i < tiefe; i++)
			{
				std::cout << "++";
			}
			suchbaum::ausgeben(knoten->links, tiefe++);
			tiefe--;
		}
		std::cout << knoten->wert<<std::endl;*/
	}
