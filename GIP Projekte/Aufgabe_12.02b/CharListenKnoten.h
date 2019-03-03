#pragma once

namespace MyString {
	class CharListenKnoten {
	private:
		char data = ' ';
		CharListenKnoten *next = nullptr;
	public:
		CharListenKnoten() = default;

		explicit CharListenKnoten(char data, CharListenKnoten *next = nullptr);

		CharListenKnoten(const CharListenKnoten &copy);

		char getData() const;

		void setData(char data);

		CharListenKnoten *getNext() const;

		void setNext(CharListenKnoten *next);

		CharListenKnoten &operator=(const CharListenKnoten &o);
	};
}