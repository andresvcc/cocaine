import XCTest

import setTests

var tests = [XCTestCaseEntry]()
tests += setTests.allTests()
XCTMain(tests)