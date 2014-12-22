/*
 * PartialTemplateSpecialization.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: Shashi
 */

#ifndef INCLUDE_PARTIALTEMPLATESPECIALIZATION_CPP_
#define INCLUDE_PARTIALTEMPLATESPECIALIZATION_CPP_
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class Window {
public:
	virtual ~Window(){}
	virtual void printFunc(){cout<<"As of now printing window..."<<endl;}
};

class ModalDialog:public Window {
public:
	virtual void printFunc(){cout<<"As of now printing Modal Dialog"<<endl;}
};

class Controller {
public:
	virtual ~Controller(){}
	virtual void printFunc() {cout<<"As of now printing Controller "<<endl;}
};

class MyController:public Controller {
public:
	virtual void printFunc(){cout<<"As of now printing MyController "<<endl;}
};

template<class Window,class Controller> class Widget
{
public:
	Widget(const Window& win,const Controller& contrl)
	{
		winObj=win;
		contrlObj=contrl;
	}
	void WidgetFunc()
	{
		cout<<"Template deduction::"<<endl;
		winObj.printFunc();
		contrlObj.printFunc();
	}
private:
	Window winObj;
	Controller contrlObj;
};


template<> class Widget<ModalDialog,MyController>
{
public:
	Widget(const ModalDialog& modWin,const MyController& myContrl)
	{
		modWinObj=modWin;
		myContrlObj=myContrl;
	}
	void WidgetFunc()
	{
		cout<<"Full Template specialization deduction::"<<endl;
		modWinObj.printFunc();
		myContrlObj.printFunc();
	}
private:
	ModalDialog modWinObj;
	MyController myContrlObj;
};

#endif /* INCLUDE_PARTIALTEMPLATESPECIALIZATION_CPP_ */
