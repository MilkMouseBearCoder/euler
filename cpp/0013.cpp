#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> LoadNumberList();
const int NUMBER_LENGTH = 50;
const int CHUNK_SIZE = 10;
const unsigned long long upperbound = 1e+10;

int main()
{
    vector<string> numbers = LoadNumberList();
    string number;
    unsigned long long partTotal = 0;
    unsigned long long currNum = 0;

    // we are going to split each number into 5 10 digit numbers
    for(int n = 1; n <= NUMBER_LENGTH / CHUNK_SIZE; n++)
    {
        if (partTotal >= upperbound)
        {
            cout << partTotal << endl;
            partTotal/=upperbound;
            cout << partTotal << endl;
        }
        else
        {
            partTotal = 0;
        }
        for(int x = 0; x < numbers.size(); x++)
        {
            stringstream(numbers[x].substr(NUMBER_LENGTH - (n * CHUNK_SIZE), CHUNK_SIZE)) >> currNum;

            partTotal+=currNum;
        }
    }
    cout << partTotal;
}

vector<string> LoadNumberList()
{
    vector<string> result;
    string STRING;
    ifstream infile("0013_numbers.txt");
    while(infile >> STRING) // To get you all the lines.
    {
        result.push_back(STRING); // Prints our STRING.
    }
    infile.close();
    return result;
}
