#pragma once
#ifndef SYSTEM_COMMAND_H
#define SYSTEM_COMMAND_H
#include "main.h"
enum class  MetaCommandResult {
	SUCCESS,
	UNRECOGNIZED_COMMAND
};
enum class PrepareResult { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT };
enum class StatementType { CREATE_TABLE, INSERT, SELECT, UPDATE };

struct Statement {
	StatementType type;
};

MetaCommandResult doMetaCommand(const string& inputBuffer) {
	if (inputBuffer.compare(".exit") == 0) {
		cout << "Exit SQL" << endl;
		exit(EXIT_SUCCESS);
	}
	else if (inputBuffer.compare(".table") == 0) {
		cout << "Can call data or read data from file hear" << endl;
		return MetaCommandResult::SUCCESS;
	}
	else {
		return MetaCommandResult::UNRECOGNIZED_COMMAND;
	}
}

PrepareResult prepareStatement(const string& inputBuffer, Statement* statement) {
	if (inputBuffer.compare(0, 6, "create") == 0) {
		statement->type = StatementType::CREATE_TABLE;
		return PrepareResult::PREPARE_SUCCESS;
	}

	if (inputBuffer.compare(0, 6, "insert") == 0) {
		statement->type = StatementType::INSERT;
		return PrepareResult::PREPARE_SUCCESS;
	}
	if (inputBuffer.compare(0, 6, "select") == 0) {
		statement->type = StatementType::SELECT;
		return PrepareResult::PREPARE_SUCCESS;
	}

	if (inputBuffer.compare(0, 6, "update") == 0) {
		statement->type = StatementType::UPDATE;
		return PrepareResult::PREPARE_SUCCESS;
	}

	return PrepareResult::PREPARE_UNRECOGNIZED_STATEMENT;
}

void executeStatement(Statement* statement) {
	switch (statement->type) {
	case (StatementType::INSERT):
		printf("This is where we would do an insert.\n");
		break;
	case (StatementType::SELECT):
		printf("This is where we would do a select.\n");
		break;
	case (StatementType::UPDATE):
		printf("This is where we would do a update.\n");
		break;
	case (StatementType::CREATE_TABLE):
		printf("This is where we would do a create table.\n");
		break;
	}
}

void printPromt(const string& mess = "MySQL") {
	cout << mess << "> ";
}

void startSQL() {
	string inputBuffer;
	while (true) {
		printPromt();
		getline(cin, inputBuffer);

		/// <summary>
		/// .exit => exit
		/// .table <table name> => show table name or call data
		/// </summary>
		if (inputBuffer[0] == '.') {
			switch (doMetaCommand(inputBuffer)) {
			case (MetaCommandResult::SUCCESS):
				continue;
			case (MetaCommandResult::UNRECOGNIZED_COMMAND):
				cout << "Unrecognized command: \"" << inputBuffer << "\"" << endl;
				continue;
			}
		}

		/// <summary>
		/// convert input => statement
		/// </summary>
		Statement statement;
		switch (prepareStatement(inputBuffer, &statement)) {
		case (PrepareResult::PREPARE_SUCCESS):
			break;
		case (PrepareResult::PREPARE_UNRECOGNIZED_STATEMENT):
			cout << "Unrecognized keyword at start of \"" << inputBuffer << "\"" << endl;
			continue;
		}

		executeStatement(&statement);
		printf("Executed.\n");
	}
}

#endif // !SYSTEM_COMMAND_H

