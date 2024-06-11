#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Client
{
	char name[100] = "";
	char marka[100] = "";
	double cash = 0;

	void fillClient() {
		cout << "Input name: ";
		cin.getline(name, 100);
		cout << "Input car: ";
		cin.getline(marka, 100);
		
	}

	void showClient() {
		cout << "Name: " << name << endl;
		cout << "Car: " << marka << endl;
		cout << "Cash: " << cash << " USD.\n\n";
	}

	void saveToTextFile(FILE* fp) {
		fprintf(fp, "\n%s\n%s\n%0.2lf", name, marka, cash);
	}

	void loadFromTextFile(FILE* fp) {
		fscanf_s(fp, "\n");
		fgets(name, 100, fp);
		name[strlen(name) - 1] = '\0';
		fgets(marka, 100, fp);
		marka[strlen(marka) - 1] = '\0';
		fscanf_s(fp, "%lf", &cash);
	}
};
