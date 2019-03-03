#pragma once
#include "CharListenKnoten.h"
#include <string>

namespace MyString {
	class MyString {
	public:
		CharListenKnoten * head = nullptr;

		void append_internal(char p_data);

		void delete_internal();

		CharListenKnoten *deep_copy_internal() const;

	public:
		MyString() = default;

		MyString(std::string str);

		~MyString();

		MyString(const MyString &copy);

		MyString &operator=(const MyString &o);

		unsigned int size() const;

		MyString operator+(char c) const;

		std::string to_string();

		char at(unsigned int pos);
	};
}