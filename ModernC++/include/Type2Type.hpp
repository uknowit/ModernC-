#ifndef _TYPE_2_TYPE_HPP
#define _TYPE_2_TYPE_HPP

#include <stdio.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
class Test {
public:
	Test(const std::string& name){cout<<"Calling Test constructor"<<endl;}
};

template<class T, class U>
T* create(const U& arg)
{
	return new T(arg);
}

template <class T,class U>
T* create(const U& arg, T) {
	cout<<"Creating new T..."<<endl;
	return new T(arg);
}

template <class U>
Test* create(const U& arg,Test) {
	cout<<"Creating new Test ..."<<endl;
	return new Test(arg);
}

template <typename T>
struct Type2Type {
	typedef T OriginalType;
};

template <class T,class U>
T* Create(const U& arg,Type2Type<T>)
{
	return new T(arg);
}

template <class U>
Test* Create(const U& arg,Type2Type<Test>)
{
	return new Test(arg);
}
/*
 * Partial specialization of function
 * template is not allowed.
template<class U>
Test* create<Test,U> (const U& arg)
{
	return new Test(arg);
}*/

#endif
