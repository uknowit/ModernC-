/*
 * LocalClasses.hpp
 *
 *  Created on: Dec 21, 2014
 *      Author: Shashi
 */

#ifndef INCLUDE_LOCALCLASSES_HPP_
#define INCLUDE_LOCALCLASSES_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class Interface
{
public:
	virtual void fun()=0;
	virtual ~Interface(){};
};

template <class T,class P> Interface* makeAdaptor(const T& obj,const P& arg)
{
	class Local: public Interface
	{
	public:
		Local(const T& obj,const P& arg):obj_(obj),arg_(arg){}
		virtual void fun() {cout<<"Printing...Obj"<<obj_<<" arg.."<<arg_<<endl;}
	private:
			T obj_;
			P arg_;

	};
	return new Local(obj,arg);
}

#endif /* INCLUDE_LOCALCLASSES_HPP_ */
