#pragma once
#include "CharListenKnoten.h"
#include <string>

namespace MyStrings2 {



	class MyString2 {

	public:
		MyString2() :anker(nullptr) {}
		MyString2(std::string text);

		unsigned int length();
		char at(unsigned int pos);

		MyString2 operator +(char c) const;
		std::string to_string() const; 



	protected:
		CharListenKnoten * anker;
		/*	append_iternal
		Erzeugt neuen CLK mit p_data als Nutzlast und haengt
		diesen ans ende an.
		*/
		void append_iternal(char p_data);
		void delete_iternal(); // loescht alle CLK des MyString2 *this
		/* deep_copy_iternal
		Erzeugt eine tiefe Kopie aller CLK des MyString* this und gibt
		den Pointer auf den erten kopierten CLK zurueck
		*/
		CharListenKnoten* deep_copy_iternal() const;



	};

}

