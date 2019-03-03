//
// Created by Knut Zuidema on 1/20/2018.
//

#include "MyString.h"

namespace MyString {
	void MyString::append_internal(char p_data) {
		if (head == nullptr) {
			head = new CharListenKnoten(p_data);
			return;
		}
		CharListenKnoten* tmp = head;
		while (tmp->getNext() != nullptr) {
			tmp = tmp->getNext();
		}
		tmp->setNext(new CharListenKnoten(p_data));
	}

	void MyString::delete_internal() {
		delete head;
	}

	CharListenKnoten *MyString::deep_copy_internal() const {
		if (head != nullptr) {
			return new CharListenKnoten(*head);
		}
		else {
			return new CharListenKnoten;
		}
	}

	MyString::MyString(std::string str) {
		if (!str.empty()) {
			head = new CharListenKnoten(str[0]);
			CharListenKnoten *tmp1 = head;
			CharListenKnoten *tmp2;
			for (int i = 1; i < str.size(); i++) {
				tmp2 = new CharListenKnoten(str[i]);
				tmp1->setNext(tmp2);
				tmp1 = tmp2;
			}
		}
	}

	MyString::~MyString() {
		delete_internal();
	}

	MyString::MyString(const MyString &copy) {
		if (copy.head != nullptr) {
			head = copy.deep_copy_internal();
		}
	}

	MyString &MyString::operator=(const MyString &o) {
		head = new CharListenKnoten(*o.head);
		return *this;
	}

	unsigned int MyString::size() const {
		unsigned int res = 0;
		CharListenKnoten *tmp = head;
		while (tmp != nullptr) {
			res++;
			tmp = tmp->getNext();
		}
		return res;
	}

	char MyString::at(unsigned int pos) {
		if (pos >= size()) {
			return '\0';
		}
		unsigned int i = 0;
		CharListenKnoten *tmp = head;
		while (i < pos) {
			i++;
			tmp = tmp->getNext();
		}
		return tmp->getData();
	}

	MyString MyString::operator+(char c) const {
		MyString res(*this);
		res.append_internal(c);
		return res;
	}

	std::string MyString::to_string() {
		std::string res;
		CharListenKnoten* tmp = head;
		while (tmp != nullptr) {
			res += tmp->getData();
			tmp = tmp->getNext();
		}
		return res;
	}
}