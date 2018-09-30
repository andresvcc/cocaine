import XCTest

import arrayTests

var tests = [XCTestCaseEntry]()
tests += arrayTests.allTests()
XCTMain(tests)