#pragma once
#pragma once
#include<fstream>
using namespace std;
#include"StudentRecord.h"

class FileIO
{
public:
	static void ReadData()
	{
		fstream fs;
		StudentRecord p1;
		fs.open("StudentRecord.dat", ios::in | ios::binary);
		while (fs.read((char*)&p1, sizeof(StudentRecord)))
		{
			p1.Display();
		}
		fs.close();
	}
	static void WriteData() {
		fstream fs;
		StudentRecord p1;
		fs.open("StudentRecord.dat", ios::out | ios::binary);
		char wish;

		do
		{
			p1.Accept();
			fs.write((char*)&p1, sizeof(StudentRecord));
			cout << "\n do u wnat to add more records:";
			cin >> wish;
		} while (wish == 'y' || wish == 'Y');
		cout << "\n all records written into file successfully";
		fs.close();

	}
	static void FindStudent(int RollNo) {
		fstream fs;
		StudentRecord p1;
		fs.open("StudentRecord.dat", ios::in | ios::binary);
		while (fs.read((char*)&p1, sizeof(StudentRecord)))
		{
			p1.SearchStudent(RollNo);
		}
		fs.close();
	}
};