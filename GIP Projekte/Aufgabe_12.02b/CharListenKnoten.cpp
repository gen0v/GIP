#include "CharListenKnoten.h"

namespace MyString {
	CharListenKnoten::CharListenKnoten(char data, CharListenKnoten *next) : data(data), next(next) {}

	char CharListenKnoten::getData() const {
		return data;
	}

	void CharListenKnoten::setData(char data) {
		CharListenKnoten::data = data;
	}

	CharListenKnoten *CharListenKnoten::getNext() const {
		return next;
	}

	void CharListenKnoten::setNext(CharListenKnoten *next) {
		CharListenKnoten::next = next;
	}

	CharListenKnoten::CharListenKnoten(const CharListenKnoten &copy) {
		data = copy.data;
		if (copy.next != nullptr) {
			next = new CharListenKnoten;
			*next = *copy.next;
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