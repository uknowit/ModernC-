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
public:
	NiftyCounter(){mObj=new T;}

	~NiftyCounter(){delete mObj;}

	void doSomeThing()
	{
		if(isPolyMorphic)
		{
			mObj.printFunc();
			cout<<"Object is polymorphic"<<endl;
		}
		else
		{
			cout<<"Object is non-polymorphic"<<endl;
		}
	}
private:
	T* mObj;
};

#endif /* INCLUDE_INT2TYPE_HPP_ */
