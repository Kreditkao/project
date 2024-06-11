#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Admin
{

	char name[100] = "";
	char post[100] = "Main Admin";


	void fillAdmin() {
		cout << "Please login by entering your name\n";
		cout << "Input name: ";
		cin.getline(name, 100);

	}

	void showAdmin() {

		cout << "Name: " << name << endl;
		cout << "Post: " << post << endl;
		cout << "---------------------------------------\n\n";
	}

	void saveToTextFile(FILE* fp) {
		fprintf(fp, "\n%s\n%s", name, post);
	}

	void loadFromTextFile(FILE* fp) {
		fscanf_s(fp, "\n");
		fscanf_s(fp, "\n");
		fgets(name, 100, fp);
		name[strlen(name) - 1] = '\0';
		fgets(post, 100, fp);
		post[strlen(post) - 1] = '\0';
	}
};
