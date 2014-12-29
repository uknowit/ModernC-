/*
 * Convertible.hpp
 *
 *  Created on: Dec 29, 2014
 *      Author: Shashi
 */

#ifndef INCLUDE_CONVERTIBLE_HPP_
#define INCLUDE_CONVERTIBLE_HPP_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

template <class T, class U>
class Conversion {
	typedef char Small;
	class Big {char dummy[2];};
	static  Small Test(U);
	static Big Test(...);
	static T MakeT();
public:
	enum {exists=sizeof(Test(MakeT()))==sizeof(Small)};
	enum {sameType=0};
};

template <class T> class Conversion <T,T>
{
public:
	enum {exists=1,sameType=1};
};



#endif /* INCLUDE_CONVERTIBLE_HPP_ */
