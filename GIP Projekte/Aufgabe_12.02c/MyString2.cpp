#include "MyString2.h"


namespace MyString2 {



	MyString2::MyString2(std::string text)
	{
		if (!text.empty()) {
			anker = new CharListenKnoten(text.at(0));
			CharListenKnoten *tmpA = anker;
			CharListenKnoten *tmpB;
			for (int i = 1; i < text.size(); i++) {
				tmpB = new CharListenKnoten(text[i]);
				tmpA->set_next(tmpB);
				tmpA = tmpB;
			}
		}
		
}

	unsigned int MyString2::length()
	{
		unsigned int counter = 0;
		CharListenKnoten *tmp = this->anker;
		while (tmp != nullptr) {
			counter++;
			tmp = tmp->get_next();
		}
		return counter;
	}

	char MyString2::at(unsigned int pos)
	{
		if (pos >= length()) {
			return '\0';
		}
		unsigned int i = 0;
		CharListenKnoten *tmp = anker;
		while (i < pos) {
			i++;
			tmp = tmp->get_next();
		}
		return tmp->get_data();
	}

	MyString2 MyString2::operator+(char c) const
	{
		/*
		MyStrings2::MyString2* copy = new MyString2();
		copy->anker = this->deep_copy_iternal();
		copy->append_internal(c);
		return *copy;
		*/
		MyString2 test(*this);
		test.append_internal(c);
		return test;


	}

	std::string MyString2::to_string() const
	{
		std::string temp = "";
		CharListenKnoten* tmp = anker;
		while (tmp != nullptr) {
			temp += tmp->get_data();
			tmp = tmp->get_next();
		}
		return temp;
	}

	
	/*
	void MyString2::append_iternal(char p_data)
	{
		CharListenKnoten* temp = new CharListenKnoten(p_data);
		//Falls anker nullptr ist dann erzeugen und ankern

		if (this->anker == nullptr) {
			anker = temp;
		}
		else {
			//sonst rekursiv durchgehen bis zum ende und dranhaengen
			/*anker->findLast().set_data(p_data);
			//anker->findLast().set_next(temp);
			anker->findLast().set_next(anker);
			temp->~CharListenKnoten();*/
		/*
		
			CharListenKnoten* temp2 = this->anker;
			while(temp2->get_next() != nullptr) {
				temp2 = temp2->get_next();
			}
			//naechster nullptr also;;
			temp2->set_next(temp);

			
		}
	}
	*/

	void MyString2::append_internal(char p_data) {

		CharListenKnoten* n = new CharListenKnoten(p_data);
		if (anker == nullptr) {
			
			//anker = new CharListenKnoten(p_data);
			anker = n;
			return;
		}
		CharListenKnoten* tmp = anker;
		while (tmp->get_next() != nullptr) {
			tmp = tmp->get_next();
		}
		//tmp->set_next(new CharListenKnoten(p_data));
		tmp->set_next(n);
	}

	void MyString2::delete_iternal()
	{
		this->anker->~CharListenKnoten();
	}

	CharListenKnoten * MyString2::deep_copy_internal() const
	{
		/*
		MyString2* copy = new MyString2();
		copy->anker = anker;
		//while not nullpty copy and ..
		CharListenKnoten *temp = anker;
		do {
			copy->append_internal(temp->get_data());
			temp = temp->get_next();
			if (temp->get_next() == anker) {
				break;
			}
		} while (temp != nullptr);*/
		
		//new Anker
		CharListenKnoten * new_anker = new CharListenKnoten();
		MyString2* copy = new MyString2();
		new_anker->set_data(anker->get_data());

		copy->anker = new_anker;
		//copy->append_internal(anker->get_next()->get_data());
		

		//jetzt kopieren
		CharListenKnoten *temp = anker;
		
		while (temp->get_next() != nullptr) {
			//new_anker->set_next(new CharListenKnoten(temp->get_data()));
			
			copy->append_internal(temp->get_next()->get_data());
			temp = temp->get_next();
			
		}
		return new_anker;
	}


	MyString2::MyString2(const MyString2 &kopie) {
		if (kopie.anker != nullptr) {
			anker = kopie.deep_copy_internal();
		}
	}

	MyString2::~MyString2()
	{
		//
		delete this->anker;
	}
}