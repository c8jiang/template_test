#pragma once

#include <string>
#include <iostream>

class Person
{
private:
	std::string name;

public:
	//explicit Person(std::string const& n) : name(n) {
	//	std::cout << "copying string-CONSTR for '" << name << "'\n";
	//}

	//explicit Person(std::string&& n) : name(std::move(n)) {
	//	std::cout << "moving string-CONSTR for '" << name << "'\n";
	//}

	template<typename STR>
	explicit Person(STR&& s) : name(std::forward<STR>(s)) {
		std::cout << "TMPL-CONSTR for '" << name << "'\n";
		std::cout << typeid(STR).name() << "\n";
	}

	Person(Person const& p) : name(p.name) {
		std::cout << "COPY-CONSTR Person '" << name << "'\n";
	}
	Person(Person&& p) : name(std::move(p.name)) {
		std::cout << "MOVE-CONSTR Person '" << name << "'\n";
	}
};
