#pragma once

struct BaumKnoten
{
	bool elternknoten = false;
	int wert = NULL;
	BaumKnoten *links = nullptr;
	BaumKnoten *rechts = nullptr;
};


namespace suchbaum {


	void einfuegen(BaumKnoten * root, int wert);
	void ausgeben(BaumKnoten * knoten, int tiefe);
}