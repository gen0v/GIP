#include "CharListenKnoten.h"

namespace MyString2 {

	CharListenKnoten::~CharListenKnoten()
	{
		/*if (this->next == nullptr) {
			delete this;
		}
		else this->next->~CharListenKnoten();*/
	}


	void CharListenKnoten::set_data(char _data)
	{
		CharListenKnoten::data = _data;
	}

	void CharListenKnoten::set_next(CharListenKnoten *_next)
	{
		//next = _next;
		//this->next = this;
		CharListenKnoten::next = _next;
	}

	char CharListenKnoten::get_data() const
	{
		return data;
	}

	CharListenKnoten *CharListenKnoten::get_next() const
	{
		//return *this->next;
		return next;
	}

	CharListenKnoten::CharListenKnoten(const CharListenKnoten &kopie) {
		data = kopie.data;
		if (kopie.next != nullptr) {
			next = new CharListenKnoten;
			*next = *kopie.next;
		}
		else {
			next = nullptr;
		}
	}






	CharListenKnoten &CharListenKnoten::operator=(const CharListenKnoten &o) {
		if (o.next == nullptr) {
			data = o.data;
			next = nullptr;
			return *this;
		}
		else {
			data = o.data;
			next = new CharListenKnoten;
			*next = *o.next;
			return *this;
		}
	}
}