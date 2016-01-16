//#include <cppunit/CompilerOutputter.h>
//#include <cppunit/extensions/TestFactoryRegistry.h>
//#include <cppunit/ui/text/TestRunner.h>
//
//#include "Test_CppUnit.h"
//
//CPPUNIT_TEST_SUITE_REGISTRATION(Test_CppUnit);
//
//int main(int argc, char* argv[])
//{
//	// get the top-level suite of tests (registry is not the Win32 registry)
//	CppUnit::Test * suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
//	// add the test to the list of tests to run
//	CppUnit::TextUi::TestRunner runner;
//	runner.addTest(suite);
//	// change the default outputter to a compiler error format outputter
//	runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));
//	// run the tests
//	bool wasSuccessful = runner.run();
//	// return error code 1 if one or more tests failed
//	return wasSuccessful ? 0 : 1;
//
//}