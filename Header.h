#pragma once
#include <iostream>

using namespace std;

class TString {
public:
	TString();

	TString(char b, int leng);

	TString(const char* tstr);

	TString(TString& a);

	~TString();

	char* get_s()
	{
		return init;
	}
	int get_l()
	{
		return length;
	}
	void set_s(const char*s);

	friend TString operator +(TString &a, TString &b);

	TString& operator =(const TString&a);

	void complete(TString& a, TString& b);

	friend bool operator == (TString &a, TString &b);

	friend bool operator <(TString &a, TString&b);

	friend bool operator >(TString &a, TString&b);

	char& operator [](const int index);

	friend ostream& operator <<(ostream& out, TString &a);

	friend istream& operator >> (istream& in, TString&b);

	char* find(const char*e);

	char* find_c(const char *c);

	TString* Tstrtok(const char *c);

private:
	char* init;
	int length;
	int size;
};