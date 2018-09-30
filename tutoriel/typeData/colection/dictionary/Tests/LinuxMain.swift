import XCTest

import dictionaryTests

var tests = [XCTestCaseEntry]()
tests += dictionaryTests.allTests()
XCTMain(tests)