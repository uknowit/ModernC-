/*
 * Executor.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: Shashi
 */
#include "../include/LocalClasses.hpp"
#include "../include/PartialTemplateSpecialization.hpp"
#include "../include/Int2Type.hpp"
#include <string>

int main()
{
	cout<<"Starting Execution......."<<endl;
	cout<<"======================="<<endl;
	std::string name="Executor.cpp";
	int dayCounter=1;
	//Local classes
	Interface* adapter = makeAdaptor(name,dayCounter);
	adapter->fun();

	//Partial template specialization
	Window win;
	Controller contrl;
	ModalDialog modWin;
	MyController myContrl;
	Widget<Window,Controller> wid(win,contrl);
	Widget<ModalDialog,MyController> widFull(modWin,myContrl);
	wid.WidgetFunc();
	widFull.WidgetFunc();

	//Int2Type
	NiftyCounter<Window,true> niftyCounter;
	niftyCounter.DoSomeThing(new Window);
	return 0;
}
