#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct Container {
	int value;
	bool hasMore(const Container&);
};

// template <typename T> // function template // old version
template <class T> // new version
T largest(T a, T b) { // find the largest among two values
	return a > b ? a : b;
}

// character pointers
// overload always have priority towards templates
// specialized template, gets trigerred when this type is called
// it becomes a template for the largest who's typename is
// only cons char pointer and nothing else
template <>
const char* largest<const char*>(const char* a, const char* b) {
	return strcmp(a, b) > 0 ? a : b;
}

template <>
Container largest<Container>(Container C1, Container C2) {
	return C1.hasMore(C2) ? C1 : C2;
}

int main() {
	char s1[] = "abc";
	char s2[] = "cdefg";

	cout << largest(s1, s2) << endl;


	return 0;
}