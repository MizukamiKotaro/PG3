#include <stdio.h>
#include <iostream>
#include <list>
#include <Windows.h>
#include <string>

template <typename T>
void Comment(T comment) {
	std::cout << comment << std::endl;
}

int main() {
	SetConsoleOutputCP(65001);

	std::list<const char*> stationNames {
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho"
	};


	Comment("1970");
	for (std::list<const char*>::iterator it_station = stationNames.begin(); it_station != stationNames.end(); it_station++) {
		Comment(*it_station);
	}

	for (std::list<const char*>::iterator it_station = stationNames.begin(); it_station != stationNames.end(); it_station++) {
		if (*it_station == "Tabata") {
			it_station = stationNames.insert(it_station, "Nishi-Nippori");
			break;
		}
	}

	Comment("");
	Comment("2019");
	for (std::list<const char*>::iterator it_station = stationNames.begin(); it_station != stationNames.end(); it_station++) {
		Comment(*it_station);
	}

	for (std::list<const char*>::iterator it_station = stationNames.begin(); it_station != stationNames.end(); it_station++) {
		if (*it_station == "Tamachi") {
			it_station = stationNames.insert(it_station, "Takanawa Gateway");
			break;
		}
	}
	Comment("");
	Comment("2022");
	for (std::list<const char*>::iterator it_station = stationNames.begin(); it_station != stationNames.end(); it_station++) {
		Comment(*it_station);
	}

	return 0;
}
