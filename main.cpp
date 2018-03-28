#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


using namespace std;

int main(int argc, string *argv) {

    string inputArgument;
    string line;
    inputArgument = argv[1];
    vector<string> quiries;

    if (inputArgument.find("script") != string::npos) {
        char *batchFileName = strtok((char *) inputArgument.c_str(), "=");
        batchFileName = strtok(NULL, "=");
        if (batchFileName == NULL) {
            cout << "No Batch FileName Given" << endl;
            return 0;
        } else {
            ifstream iput(batchFileName);
            while (getline(iput, line))
            {
                if (line.find("\r") != string::npos) {
                    line = line.substr(0, line.find('\r'));
                }
                if (line.find("\n") != string::npos) {
                    line = line.substr(0, line.find('\n'));
                }

                //cout << line << endl;
                string sqlQuery = "";

                for (string::size_type i = 0; i < line.length(); ++i)
                {
                    sqlQuery += toupper(line[i]);
                }
                cout << sqlQuery << endl;
                size_t eachQueryBreak = sqlQuery.find(';');
                if (eachQueryBreak != string::npos) {

                    string query = sqlQuery.substr(0, eachQueryBreak);
                } else {
                    cout << "semicolun not found at the end of the statement";
                     break;
                }

                    quiries.push_back(sqlQuery);
            }
        }
    }

    for (std::size_t i = 0; i < quiries.size(); ++i)
    {
        cout << quiries.size()<< endl;
        cout << quiries[i] << endl;
    }
}