#pragma once
#ifndef TABLE_H
#define TABLE_H
#include "row.h"
class Table {
private:
	vector<Row>* tableData;
	Row* formatRow;
public:
	Table() {
		tableData = new vector<Row>;
		formatRow = nullptr;
	}
	Table(Row* formatRow) {
		this->formatRow = formatRow;
		tableData = new vector<Row>;
	}
	~Table() {
		delete tableData;
		delete formatRow;
	}
	void Insert() {
		Row* newRow = formatRow;
		tableData->push_back(*newRow);
		tableData->back().Insert();
	}


	//Select All
	void Show() {
		formatRow->PrintAllField();
		vector<Row>::iterator itRow = tableData->begin();
		for (; itRow != tableData->end(); itRow++) {
			cout << itRow->toString() << endl;
		}
	}
};

#endif // !TABLE_H
