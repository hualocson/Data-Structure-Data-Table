#pragma once
#ifndef COLUMN_H
#define COLUMN_H
#include "main.h"
class Column {
private:
	string fieldName;
	string value;
	bool isPrimaryKey;
public:
	Column(string fieldName) {
		this->fieldName = fieldName;
		isPrimaryKey = false;
		value = "";
	}
	Column(string fieldName, bool isPrimaryKey) {
		this->fieldName = fieldName;
		this->isPrimaryKey = isPrimaryKey;
		value = "";
	}
	~Column() {
	}

	//overload
	Column& operator=(const Column& obj) {
		if (this == &obj)
			return *this;
		fieldName = obj.fieldName;
		value = obj.value;
		isPrimaryKey = obj.isPrimaryKey;
		return *this;
	}

	string FieldName() {
		return fieldName;
	}
	void setValue(string value) {
		this->value = value;
	}
	string Value() {
		return value;
	}
	bool IsPrimaryKey() {
		return isPrimaryKey;
	}
	string toString() {
		stringstream ss;
		if (value != "")
			ss << value;
		else
			ss << " - ";
		return ss.str();
	}
};
#endif // !COLUMN_H

