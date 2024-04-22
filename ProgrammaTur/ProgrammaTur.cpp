#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<fstream>
#include <WINDOWS.h>
#include <filesystem>
#include <time.h>
using namespace std;
struct turism {
	char name[100]{};
	char country[100]{};
	char city[100]{};
	char time_start[20]{};
	char time_finish[20]{};
};
/*Написать программу которая будет вычитывать
 из файла информацию о туристических мероприятиях.
1. Вывести название, страна проведения, место, дата начала, дата окончания.
2. Сортивка по названию.
3. Добавить возможность поиска по дате( выводить если дата между началом и окончание)*/

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	tm t;
	"I:\\РПО и ГД для тех у кого нет диска колледж\\БВ312\\Здадание\\";
	ifstream file("example.csv");
	if (!filesystem::exists("C:/Users/student/Desktop/ProgrammaTur/ProgrammaTur/example.csv.lnk")) {
		cout << "not find\n";
		return 0;
	}
	if (!file.is_open())
	{
		return 0;
	}
	char buffer[2048] = {};
	file.getline(buffer, 2048);
	while (!file.eof()) {
		turism Read;
		char buffer1[2028];
		file.getline(buffer1, 2048);//Читаем строку
		if (strlen(buffer1) < 10) {
			continue;
		}
		char tmp[128]{};
		char* end;
		strtok_s(buffer1, ",", &end);

		strcpy_s(Read.name, 150, strtok_s(end, ",", &end));

		strtok_s(end, ",", &end);

		strtok_s(end, ",", &end);

		strcpy_s(Read.country, 100, strtok_s(end, ",", &end));
		strcpy_s(Read.city, 100, strtok_s(end, ",",  &end));
	
		
		if (strrchr(end, ',')) {
			strcpy_s(Read.time_finish, 20, strrchr(end, ',') + 1);
			*strrchr(end, ',') = '\0';
		}
		if (strrchr(end, ',')) {
			strcpy_s(Read.time_start, 20, strrchr(end, ',') + 1);
			*strrchr(end, ',') = '\0';
		}
		cout << Read.name << " " << Read.city << " start:" << Read.time_start <<" finish:"<<Read.time_finish<<endl;
	

		//file.getline(buffer1, 1024, ',');//убираем не нужное поле с айди
		//file.getline(Read.name, sizeof(Read.name), ',');
		//file.getline(buffer1, 1024, ',');//убираем не нужное поле с английским названием
		//file.getline(buffer1, 1024, ',');//убираем не нужное поле с типом
		//file.getline(Read.name, sizeof(Read.country), ',');
		//file.getline(Read.name, sizeof(Read.city), ',');
	}
  }