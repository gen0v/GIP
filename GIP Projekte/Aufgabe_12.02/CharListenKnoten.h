#pragma once

//using namespace MyString2;
namespace MyStrings2 {


	class CharListenKnoten {

	public:
		//Contructor
		CharListenKnoten(char d, CharListenKnoten* n) :data(d), next(n) {}
		CharListenKnoten(char d) :data(d), next(nullptr) {}
		//CharListenKnoten(): data(' '),next(nullptr){}
		//Destructor
		~CharListenKnoten();
		//Getter & Setter
		void set_data(char _data);
		void set_next(CharListenKnoten *_next);
		char get_data();
		CharListenKnoten* get_next();
		//Andere Methoden





	protected:
		char data;
		CharListenKnoten* next;
	};


}
