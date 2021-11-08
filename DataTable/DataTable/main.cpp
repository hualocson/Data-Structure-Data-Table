#include "table.h"

//Remove space first, end string str
void  formatString(string &str) {
    string temp = "";
    int size = str.length();
    for (int i = 0; i < size; i++) {
        if (str[i] != ' ')
            temp += str[i];
        else {
            if (temp != "" && temp.back() != ' ')
                temp += str[i];
        }
    }
    str = temp;
}

void createTable(string str, Table *&table) {
    string nameField;
    int size = str.length();
    int pos;
    Row* row = new Row();
    string temp;
    do {
        pos = str.find_first_of(',');
        if (pos != -1) {
            temp = str.substr(0, pos);
            str.replace(0, pos + 2, "");
        }
        else {
            pos = size - 1;
            temp = str.substr(0, pos);
            str.replace(0, pos, "");
        }
        formatString(temp);
        int primaryKey = temp.find("PRIMARY");
        pos = temp.find_first_of(' ');
        nameField = temp.substr(0, pos);
        Column* newField;
        if (primaryKey != -1)
            newField = new Column(nameField, true);
        else 
            newField = new Column(nameField);
        row->InsertField(*newField);
    } while (str.empty() == false);
    table = new Table(row);
}

int main()
{
    string command,tableName,str, line;
    cin >> command;
    cout << command << endl;
    getline(cin, line);
    int pos1 = line.find_first_of('(');
    int pos2 = line.find_first_of(')');

    str = line.substr(pos1 + 1, pos2 - pos1 -1);
    cout << str << endl;
    Table* table;
    createTable(str, table);


    //insert row
    table->Insert();
    table->Insert();
    //select All
    table->Show();
    return 0;
}