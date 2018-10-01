import XCTest

import structurTests

var tests = [XCTestCaseEntry]()
tests += structurTests.allTests()
XCTMain(tests)