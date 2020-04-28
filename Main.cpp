#include <iostream>
#include "Header.h"
#include <array>



using namespace std;


int main() {
	TString a;
	TString b("const");
	TString c(b);
	cout << b.get_s() << " access to the field" << endl;
	cout << c.get_s() << " access to the field" << endl;
	c.set_s("access to the field");
	cout << c << endl;
	TString d;
	d = b + c;
	cout << d << " operator +" << endl;
	TString e("sdsdsds");
	TString f("sdsdsds");
	cout << (f == e) << " operator ==" << endl;
	cout << (b == c) << " operator ==" << endl;
	e.set_s("sdsd");
	f.set_s("s");
	cout << (e < f) << " operator <" << endl;
	cout << (f > e) << " operator >" << endl;
	cout << f[0]<< " operator []" << endl;
	
	TString x;
	cin >> x;
	
	cout << x.find("_c") << endl;
	cout << x.find_c("z") << endl;

	TString* arr;
	arr = x.Tstrtok("_");

	for (int i = 0; i < sizeof(arr) - 1; i++)
		cout << arr[i] << " ";
	return 0;
}