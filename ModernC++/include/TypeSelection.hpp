/*
 * TypeSelection.hpp
 *
 *  Created on: Dec 26, 2014
 *      Author: Shashi
 */

#ifndef INCLUDE_TYPESELECTION_HPP_
#define INCLUDE_TYPESELECTION_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
template <typename T, bool isPolymporphic>
class NiftyCounterSelectionTraits
{
	typedef T* valueType;
};

template <typename T>
class NiftyCounterSelectionTraits<T, false>
{
	typedef T valueType;
};

template <bool flag,typename T,typename U>
class Select
{
	typedef T Result;
};

template <typename T,typename U>
class Select <false,T,U>
{
	typedef U Result;
};

template <class T,bool isPolyMorphic> class NiftyCounterSelection
{

private:
	typedef NiftyCounterSelectionTraits<T,isPolyMorphic> Traits;
	typedef typename Traits::valueType ValueType;
	typedef  typename Select<isPolyMorphic,T,T*>::Result ValueTypeSelect;
public:
	NiftyCounterSelection(){}

	~NiftyCounterSelection(){}

};




#endif /* INCLUDE_TYPESELECTION_HPP_ */
