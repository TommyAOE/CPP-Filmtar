#include"Ido.h"
#include "memtrace.h"

std::ostream& operator<<(std::ostream& os, Ido& ido) {
	if (ido.GetOra() < 10)	os << "0" << ido.GetOra() << ":";
	else    os << ido.GetOra() << ":";
	if (ido.GetPerc() < 10)	os << "0" << ido.GetPerc();
	else    os << ido.GetPerc();
	return os;
}
bool Ido::operator==(Ido rhs) {
	if (perc == rhs.perc && ora == rhs.ora)	return true;
	else return false;
}
bool Ido::operator!=(Ido rhs) {
	return (*this == rhs);
}