
#include <iostream>
#include <fstream>
#include <string>
#include "tim-leonhardt-linkedlist-node.h"
#include "tim-leonhardt-linkedlist-linkedlist.h"
#include "tim-leonhardt-linkedlist-car-class.h"

void loadList(LinkedList& carList);

using namespace std;

int main() {
	LinkedList carList;
	loadList(carList);

	Car car1;
	Car* memoryLocation = nullptr;
	string brand;
	string model;
	string horsepower;
	string color;
	string seats;
	string doors;
	int num;

	int command = 0;
	do {
		cout << "\nEnter a number to select the command you want to run: \n";
		cout << "\t1. Add a car\n";
		cout << "\t2. Edit a car\n";
		cout << "\t3. Remove a car\n";
		cout << "\t4. List a car\n";
		cout << "\t5. Output entire list\n";
		cout << "\t6. Exit program\n";
		cout << "\n--: ";
		cin >> command;
		cout << endl;

		switch (command) 
		{
			case 1: // Add new car
			{
				cout << "\n\tWhat is the name of the model: ";
				cin.ignore();
				getline(cin, model);
				car1.setModel(model);
				if (carList.findCar(car1, memoryLocation))
				{
					cout << "\n\tThis model already exists in the list. Try another model\n";
				}
				else {
					cout << "\tWhat is the brand: ";
					getline(cin, brand);
					cout << "\tWhat is the horsepower: ";
					getline(cin, horsepower);
					cout << "\tWhat is the color: ";
					getline(cin, color);
					cout << "\tHow many seats: ";
					getline(cin, seats);
					cout << "\tHow many doors: ";
					getline(cin, doors);
					car1.setBrand(brand);
					car1.setModel(model);
					car1.setHorsepower(horsepower);
					car1.setColor(color);
					car1.setSeats(seats);
					car1.setDoors(doors);
					carList.insert(car1);
					cout << "\n\tThis model has been added to the list\n\n";
				}
				break;
			}
			case 2: // Edit car
			{
				cin.ignore();
				cout << "\n\tEnter the model of the car you would like to edit: ";
				getline(cin, model);
				car1.setModel(model);
				if (carList.findCar(car1, memoryLocation)) {

					cout << "\tWhat would you like to change: \n";
					cout << "\n\t\t1. Brand";
					cout << "\n\t\t2. Model";
					cout << "\n\t\t3. Horsepower";
					cout << "\n\t\t4. Color";
					cout << "\n\t\t5. Seats";
					cout << "\n\t\t6. Doors";
					cout << "\n\n--: ";
					cin >> num;

					switch (num)
					{
						case 1:
						{
							cin.ignore();
							cout << "\t\tEnter the new brand: ";
							getline(cin, brand);
							memoryLocation->setBrand(brand);
							cout << "\t\tChanges have been made" << endl << endl;
							break;
						}
						case 2:
						{
							cin.ignore();
							cout << "\t\tEnter the new model: ";
							getline(cin, model);
							memoryLocation->setModel(model);
							cout << "\t\tChanges have been made" << endl << endl;
							break;
						}
						case 3:
						{
							cin.ignore();
							cout << "\t\tEnter the new horsepower: ";
							getline(cin, horsepower);
							memoryLocation->setHorsepower(horsepower);
							cout << "\t\tChanges have been made" << endl << endl;
							break;
						}
						case 4:
						{
							cin.ignore();
							cout << "\t\tEnter the new color: ";
							getline(cin, color);
							memoryLocation->setColor(color);
							cout << endl << "\t\tChanges have been made" << endl << endl;
							break;
						}
						case 5:
						{
							cin.ignore();
							cout << "\t\tEnter the new number of seats: ";
							getline(cin, seats);
							memoryLocation->setSeats(seats);
							cout << "\t\tChanges have been made" << endl << endl;
							break;
						}
						case 6:
						{
							cin.ignore();
							cout << "\t\tEnter the new number of doors: ";
							getline(cin, doors);
							memoryLocation->setDoors(doors);
							cout << "\t\tChanges have been made" << endl << endl;
							break;
						}
						default:
						{
							cout << "\n\tThe entered number was not an option. The Process has been caneled.\n\n";
							break;
						}
					}
				}
				else
				{
					cout << "\n\tThis model does not exist\n";
				}
				break;
			}
			case 3: //Remove car
			{
				cout << "\n\tEnter the model you would like to remove: ";
				cin.ignore();
				getline(cin, model);
				car1.setModel(model);
				if (carList.findCar(car1, memoryLocation)) {
					carList.remove(*memoryLocation);
					cout << "\t" << model << " has been successfully removed\n\n";
				}
				else
				{
					cout << "\n\tThis model does not exist\n\n";
				}
				break;
			}
			case 4: //List car 
			{
				cout << "\n\tEnter the model you would like to find: ";
				cin.ignore();
				getline(cin, model);
				car1.setModel(model);
				if (carList.findCar(car1, memoryLocation))
				{
					cout << endl << "\t\t" << "Brand: " << memoryLocation->getBrand() << endl;
					cout << "\t\t" << "Model: " << memoryLocation->getModel() << endl;
					cout << "\t\t" << "Horsepower: " << memoryLocation->getHorsepower() << endl;
					cout << "\t\t" << "Color: " << memoryLocation->getColor() << endl;
					cout << "\t\t" << "Seats: " << memoryLocation->getSeats() << endl;
					cout << "\t\t" << "Doors: " << memoryLocation->getDoors() << endl;
				}
				else
					cout << "\n\tThis model does not exist\n\n";
				break;
			}
			case 5: //Output entire list 
			{
				carList.outputList();
				carList.getSizeOfLinkedList();
				break;
			}
			case 6: //Exit Program
			{
				return 0;
				break;
			}
			default: //Number != in range 
			{
				cout << "\n\tThe entered number is not available. Please try again or enter '6' to exit the program\n\n";
				break;
			}
		}
	} while (command != 6);
}

void loadList(LinkedList& carList) {
	ifstream file;
	file.open("CarList.txt");
	
	string line;

	getline(file, line);

	while (getline(file, line)) {
		Car carObject;

		string brand, model, item;

		size_t indexComma;

		//Brand 
		indexComma = line.find(',');
		brand = line.substr(0, indexComma);
		line.erase(0, indexComma + 1);
		carObject.setBrand(brand);

		//Model 
		indexComma = line.find(',');
		model = line.substr(1, indexComma-1);
		line.erase(0, indexComma + 1);
		carObject.setModel(model);

		//Horsepower 
		indexComma = line.find(',');
		item = line.substr(1, indexComma-1);
		line.erase(0, indexComma + 1);
		carObject.setHorsepower(item);

		//Color 
		indexComma = line.find(',');
		item = line.substr(1, indexComma-1);
		line.erase(0, indexComma + 1);
		carObject.setColor(item);

		//Seats  
		indexComma = line.find(',');
		item = line.substr(1, indexComma-1);
		line.erase(0, indexComma + 1);
		carObject.setSeats(item);

		//Doors 
		indexComma = line.find(',');
		item = line.substr(1, indexComma-1);
		line.erase(0, indexComma + 1);
		carObject.setDoors(item);

		carList.insert(carObject);
	}

	file.close();
}