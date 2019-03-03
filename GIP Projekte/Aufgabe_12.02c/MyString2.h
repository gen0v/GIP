#pragma once
#include "CharListenKnoten.h"
#include <string>

namespace MyString2 {



	class MyString2 {

	public:
		MyString2() = default;
		//MyString2() :anker(nullptr) {}
		MyString2(std::string text);
		MyString2(const MyString2 &kopie);
		~MyString2();

		unsigned int length();
		char at(unsigned int pos);

		MyString2 operator +(char c) const;
		std::string to_string() const; 

		CharListenKnoten* anker = nullptr;
		CharListenKnoten* deep_copy_internal() const;
		void delete_iternal();
		void append_internal(char p_data);


		//1CharListenKnoten * anker;
		/*	append_iternal
		Erzeugt neuen CLK mit p_data als Nutzlast und haengt
		diesen ans ende an.
		*/
		
		//1void append_internal(char p_data);
		//1void delete_iternal(); // loescht alle CLK des MyString2 *this
		/* deep_copy_iternal
		Erzeugt eine tiefe Kopie aller CLK des MyString* this und gibt
		den Pointer auf den erten kopierten CLK zurueck
		*/
		//1CharListenKnoten* deep_copy_iternal() const;



	};

}

