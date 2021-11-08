#pragma once
#ifndef ROW_H
#define ROW_H
#include "column.h"
class Row {
private:
	vector<Column>* fieldArray;
	int indexOfPrimaryKey;
public:
	Row() {
		fieldArray = new vector<Column>;
		indexOfPrimaryKey = -1;
	}
	Row(const Row& row) {
		fieldArray = new vector<Column>;
		int size = row.fieldArray->size();
		for (int i = 0; i < size; i++) {
			InsertField(row.fieldArray->at(i));
		}
		indexOfPrimaryKey = row.indexOfPrimaryKey;
	}
	~Row() {
		delete fieldArray;
	}
	//overloading
	Row& operator=(const Row& obj) {
		if (this == &obj)
			return *this;
		fieldArray = new vector<Column>;
		int size = obj.fieldArray->size();
		for (int i = 0; i < size; i++) {
			InsertField(obj.fieldArray->at(i));
		}
		this->indexOfPrimaryKey = obj.indexOfPrimaryKey;
		return *this;
	}
	void InsertField(Column newField) {
		fieldArray->push_back(newField);
		if (newField.IsPrimaryKey()) {
			indexOfPrimaryKey = fieldArray->size() - 1;
			fieldArray->back() = fieldArray->front();
			fieldArray->front() = newField;
		}
	}
	//Insert value to all field
	void Insert() {
		int size = fieldArray->size();
		if (size != 0) {
			for (int i = 0; i < size; i++) {
				string str;
				cout << fieldArray->at(i).FieldName() << ": ";
				cin >> str;
				fieldArray->at(i).setValue(str);
			}
		}
	}
	string toString() {
		stringstream ss;
		int size = fieldArray->size();
		for (int i = 0; i < size; i++) {
			ss << setw(20) << left << fieldArray->at(i).toString();
		}
		return ss.str();
	}

	void PrintAllField() {
		vector<Column>::iterator it = fieldArray->begin();
		for (; it != fieldArray->end(); it++) {
			cout << setw(20) << left << it->FieldName();
		}
		cout << endl;
		int width = 20 * fieldArray->size();
		cout << setfill('-');
		cout << setw(width) << "-" << endl;
		cout << setfill(' ');
	}

	vector<Column>* FieldArray() {
		return fieldArray;
	}
};
#endif // !ROW_H

