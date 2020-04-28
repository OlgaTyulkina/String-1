#include "Header.h"
#pragma warning(disable:4996)

TString::TString() :init(0), size(0), length(0)
{

}

TString::TString(char b, int leng) {
	size = leng + 1;
	init = new char[size];
	length = leng;
	for (int i = 0; i < length; i++) init[i] = b;
	init[length] = 0;
}

TString::TString(const char* tstr) {
	if (strlen(tstr) > 0) {

		size = strlen(tstr) + 1;
		length = strlen(tstr);
		init = new char[strlen(tstr) + 1];
		for (size_t i = 0; i < strlen(tstr); i++)init[i] = tstr[i];
		init[strlen(tstr)] = 0;
	}

}

TString::TString(TString &a) {
	size = a.get_l() + 1;
	length = a.get_l();
	init = new char[size];
	for (int i = 0; i < length; i++)init[i] = a.get_s()[i];
	init[length] = 0;
}

TString::~TString() {
	if (init != NULL)
		delete[] init;
}

void TString::set_s(const char*s) {
	if (strlen(s) > 0) {
		size = strlen(s) + 1;
		length = strlen(s);
		init = new char[strlen(s) + 1];
		for (size_t i = 0; i < strlen(s); i++)init[i] = s[i];
		init[strlen(s)] = 0;
	}
}

TString operator +(TString& a, TString &b) {
	TString c(a);
	c.complete(a, b);
	return c;
}

TString &TString::operator =(const TString& a) {
	if (&a == this)
		return *this;
	length = a.length;
	size = length + 1;
	init = new char[size];
	for (int i = 0; i < length; i++)init[i] = a.init[i];
	init[length] = 0;
	return *this;
}

bool operator == (TString &a, TString &b) {
	return(0 == strcmp(a.get_s(), b.get_s()));
}

bool operator <(TString &a, TString&b) {
	return(strcmp(a.get_s(), b.get_s()) < 0);
}

bool operator >(TString &a, TString&b) {
	return(strcmp(a.get_s(), b.get_s()) > 0);
}

char& TString::operator [](const int index) {
	if (index < 0 || index >= length)
		throw "yikes";
	else
		return init[index];
}

ostream& operator <<(ostream& out, TString &a) {
	for (int i = 0; i < a.get_l(); i++) {
		out << a.get_s()[i];
	}

	return out;
}

istream& operator >> (istream& in, TString& b) {
	char t[256];
	in.getline(t, 256);
	TString e(t);
	b = e;
	return in;
}

char* TString::find(const char *e) {
	char* t = strstr(init, e);
	if (t != NULL)
		return t;
	else
		return (char*)"Not found";
}

char* TString::find_c(const char *c) {
	char* t = strstr(init, c);
	if (t != NULL)
		return t;
	else
		return (char*)"Not found";
}

TString* TString::Tstrtok(const char* c) {
	int count = 0;

	TString tmp = init;

	char* istr = strtok(tmp.init, c);
	while (istr != NULL)
	{
		count += 1;
		istr = strtok(NULL, c);
	}

	tmp = init;

	TString* result = new TString[count];

	count = 0;

	istr = strtok(tmp.init, c);
	while (istr != NULL)
	{
		result[count] = istr;
		count += 1;
		istr = strtok(NULL, c);
	}

	return result;
}

void TString::complete(TString& a, TString& b)
{

	init = new char[a.get_l() + 1 + b.get_l()];
	length = a.get_l() + b.get_l();
	size = a.get_l() + 1 + b.get_l();
	for (int i = 0; i < a.get_l(); i++) init[i] = a.get_s()[i];
	for (int i = 0; i < b.get_l(); i++) init[i + a.get_l()] = b.get_s()[i];
	init[a.get_l() + b.get_l()] = 0;
}