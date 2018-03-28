#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

vector<string> batchFileSQLInput(string batchFileName) {

    ifstream script(batchFileName);

    string line = "";
    vector <string> quiries;

    if (script.is_open()) {

        while (getline(script, line)) {

            // New Lines Eliminated
            if (line.find("\r") != string::npos) {
                line = line.substr(0, line.find('\r'));
            }
            if (line.find("\n") != string::npos) {
                line = line.substr(0, line.find('\n'));
            }

            string sqlQuery = "";

            for (string::size_type i = 0; i < line.length(); ++i) {
                sqlQuery += toupper(line[i]);
            }
            cout << sqlQuery << endl;

                size_t eachQueryBreak = sqlQuery.find(';');

                if (eachQueryBreak != string::npos) {

                    string query = sqlQuery.substr(0, eachQueryBreak);
                }
                else {
                    cout << "ERROR: " << sqlQuery << " is not executed. No semicolon could be found." << endl;
                    break;  // GOTO Next Line in the file
                }
            quiries.push_back(sqlQuery);
        }
    }
    else
    {
        cout << "ERROR: cannot open " << batchFileName << endl;
    }
}

//string SQLConsoleInput(string sql);

void SQLConsoleInput(string sql) {

    while (sql.length() > 0) {

        string sqlQueryInput = "";

        for (string::size_type i = 0; i < sql.length(); ++i) {
            sqlQueryInput += toupper(sql[i]);
        }
        //cout << sqlQueryInput << endl;

        size_t eachQueryBreak = sqlQueryInput.find(';');

        if (eachQueryBreak != string::npos) {

            string query = sqlQueryInput.substr(0, eachQueryBreak);

        }
        else {
            cout << "ERROR: " << sqlQueryInput << " is not executed.semicolon is missing at the end of the line" << endl;
        }
            sql = "";
            cout << "SQL > ";
            getline(cin, sql);
            if (sql == "QUIT;" || sql=="quit;")
                break;

    }
}

int main(int argc, char** argv)
{
   // std::cout << "Have " << argc << " arguments:" << std::endl;
    //for (int i = 0; i < argc; ++i)
    //{
      //  std::cout << argv[i] << std::endl;
    //}
    if (argc != 2)
    {
			cout << "Invalid Input Specification" << endl;
			cout << "Enter : dbms script=<filename> OR dbms \"<SQL query>\"" << endl;
    }
      string inputArgument = argv[1];

		if (inputArgument.find("script") != string::npos)
        {
			char* batchFileName = strtok((char*)inputArgument.c_str(), "=");
			batchFileName = strtok(NULL, "=");
			if (batchFileName == NULL)
            {
				cout << "No Batch FileName Given" << endl;
				return 0;
			}
			cout << batchFileName << endl;
            vector<string> result = batchFileSQLInput(batchFileName);

            for (std::size_t i = 0; i < result.size(); ++i)
            {
                cout << result.size()<< endl;
                cout << result[i];
            }

        }
		else
        {
            SQLConsoleInput(inputArgument);

        }

		return 0;
}
