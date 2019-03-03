#pragma once

//using namespace MyString2;
namespace MyString2 {


	class CharListenKnoten {

	public:
		//Contructor
		CharListenKnoten(char d) :data(d){}
		CharListenKnoten() = default;
		//explicit CharListenKnoten(char data, CharListenKnoten *next = nullptr);
		CharListenKnoten(const CharListenKnoten &kopie);
		//CharListenKnoten(){}
		//Destructor
		~CharListenKnoten();
		//Getter & Setter
		void set_data(char _data);
		void set_next(CharListenKnoten *_next);
		char get_data() const;
		CharListenKnoten *get_next() const;
		//Andere Methoden
		CharListenKnoten &operator=(const CharListenKnoten &o);




	private:
		char data = ' ';
		CharListenKnoten* next = nullptr;
	};


}
