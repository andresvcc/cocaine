import XCTest

import variablesTests

var tests = [XCTestCaseEntry]()
tests += variablesTests.allTests()
XCTMain(tests)