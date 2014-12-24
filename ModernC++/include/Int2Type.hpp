/*
 * Int2Type.hpp
 *
 *  Created on: Dec 23, 2014
 *      Author: Shashi
 */

#ifndef INCLUDE_INT2TYPE_HPP_
#define INCLUDE_INT2TYPE_HPP_
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

template<int v> struct Int2Type
{
	enum {value =v};
};

template <class T,bool isPolyMorphic> class NiftyCounter
{

private:
	void doSomeThing(T* pObj,Int2Type<true>)
	{
			pObj->printFunc();
			cout<<"Object is polymorphic"<<endl;
	}

	void doSomeThing(T* obj,Int2Type<false>)
	{
			cout<<"Object is non-polymorphic"<<endl;
	}


public:
	NiftyCounter(){}

	~NiftyCounter(){}

	void DoSomeThing(T* obj)
	{
		doSomeThing(obj,Int2Type<isPolyMorphic>());
	}

};

#endif /* INCLUDE_INT2TYPE_HPP_ */
