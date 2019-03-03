#include "MyString2.h"


namespace MyStrings2 {



	MyString2::MyString2(std::string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			this->append_iternal(text.at(i));
		}
	}

	unsigned int MyString2::length()
	{
		int counter = 0;

		MyStrings2::CharListenKnoten* temp = this->anker;

		while (temp->get_next() != nullptr) {
			counter++;
			temp = temp->get_next();
		}
		return counter;
	}

	char MyString2::at(unsigned int pos)
	{
		int counter = pos;
		MyStrings2::CharListenKnoten* temp = this->anker;
		char erg = temp->get_data();
		for (int i = 0; i < pos; i++)
		{
			temp = temp->get_next();
			erg = temp->get_data();
		}
		if (temp->get_data() == ' ') {
			return '\0';
		}
		else return erg;
	}

	MyString2 MyString2::operator+(char c) const
	{
		MyStrings2::MyString2* copy = new MyString2();
		copy->anker = this->deep_copy_iternal();
		copy->append_iternal(c);
		return *copy;


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
			
			CharListenKnoten* temp2 = this->anker;
			while(temp2->get_next() == nullptr) {
				temp2 = temp2->get_next();
			}
			//naechster nullptr also;;
			temp2->set_next(temp);

			
		}
	}

	void MyString2::delete_iternal()
	{
		this->anker->~CharListenKnoten();
	}

	CharListenKnoten * MyString2::deep_copy_iternal() const
	{
		MyStrings2::MyString2* copy = new MyStrings2::MyString2();
		copy->anker = this->anker;
		//while not nullpty copy and ..
		CharListenKnoten* temp = anker;
		while (temp != nullptr) {
			copy->append_iternal(temp->get_next()->get_data());
			temp = temp->get_next();
		}



		return nullptr;
	}

}