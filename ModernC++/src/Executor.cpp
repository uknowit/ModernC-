/*
 * Executor.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: Shashi
 */
#include "../include/LocalClasses.hpp"
#include <string>
int main()
{
	cout<<"Starting Execution......."<<endl;
	cout<<"======================="<<endl;
	std::string name="Executor.cpp";
	int dayCounter=1;
	Interface* adapter = makeAdaptor(name,dayCounter);
	adapter->fun();
	return 0;
}
