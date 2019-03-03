#include "CharListenKnoten.h"

namespace MyStrings2 {

	CharListenKnoten::~CharListenKnoten()
	{
		/*if (this->next == nullptr) {
			delete this;
		}
		else this->next->~CharListenKnoten();*/
	}


	void CharListenKnoten::set_data(char _data)
	{
		this->data = _data;
	}

	void CharListenKnoten::set_next(CharListenKnoten *_next)
	{
		//next = _next;
		//this->next = this;
		CharListenKnoten::next = next;
	}

	char CharListenKnoten::get_data()
	{
		return this->data;
	}

	CharListenKnoten *CharListenKnoten::get_next()
	{
		//return *this->next;
		return next;
	}



}