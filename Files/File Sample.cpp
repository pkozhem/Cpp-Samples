/*Code sample for files*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream fout;
	ifstream fin;

	fin.open("<file_location>");
	fout.open("<file_location>", ofstream::app);

	if (!fout) cout << "file wasn't opened\n" << endl;
	else cout << "file was opened\n" << endl;

	fout << "sample text" << endl;
	fin.seekg(0, ios_base::beg);

	string str;
	while (!fin.eof())
	{
		str = "";
		getline(fin, str);
		cout << str << endl;
	}

	fin.close();
	fout.close();
}