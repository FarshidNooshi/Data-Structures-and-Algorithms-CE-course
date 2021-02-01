#pragma once

#include <bits/stdc++.h>

#include "Query.h"
#include "Answer.h"

using namespace std;

class Writer {
	map<Query, Answer> analysedMap;

public:
	Writer() = default;

	Writer(map<Query, Answer> analysedMap) {
		this->analysedMap = analysedMap;
	}

	void WriteAnswers();
};