import XCTest

import enumerationsTests

var tests = [XCTestCaseEntry]()
tests += enumerationsTests.allTests()
XCTMain(tests)