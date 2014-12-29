/*
 * Executor.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: Shashi
 */
#include "../include/LocalClasses.hpp"
#include "../include/PartialTemplateSpecialization.hpp"
#include "../include/Int2Type.hpp"
#include "../include/Type2Type.hpp"
#include "../include/TypeSelection.hpp"
#include "../include/Convertible.hpp"
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

	//Type2Type
	std::string nameArg="Shashi";
	std::string lastArg="Kumar";
	Test tt(lastArg); //Overhead of creating additional object to overload functionTemplate
	Test* T = create(nameArg,tt);
	delete T;
	std::cout<<"=============="<<std::endl;
	Test* T1 = Create(nameArg,Type2Type<Test>());
	delete T1;

	//Convertibility
	std::cout<<Conversion<double,int>::exists <<" "<<
			Conversion<char,char*>::exists <<" "<<
			Conversion<size_t,std::vector<int> >::exists<<endl;
	std::cout<<SUPERSUBCLASS(Controller,MyController)<<std::endl;
	return 0;
}
