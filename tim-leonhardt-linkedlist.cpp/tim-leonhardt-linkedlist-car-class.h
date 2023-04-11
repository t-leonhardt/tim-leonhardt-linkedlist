#pragma once
#include <iostream>

using namespace std;

class Car {
private:
	string brand;
	string model;
	string horsepower;
	string color;
	string seats;
	string doors;

public:
	Car() {
		brand = "";
		model = "";
		horsepower = "";
		color = "";
		seats = "";
		doors = "";
	}

	//Setters 
	void setBrand(string brand) {
		this->brand = brand;
	}
	void setModel(string model) {
		this->model = model;
	}
	void setHorsepower(string hp) {
		horsepower = hp;
	}
	void setColor(string color) {
		this->color = color;
	}
	void setSeats(string seats) {
		this->seats = seats;
	}
	void setDoors(string doors) {
		this->doors = doors;
	}

	//Getters
	string getBrand() {
		return brand;
	}
	string getModel() {
		return model;
	}
	string getHorsepower() {
		return horsepower;
	}
	string getColor() {
		return color;
	}
	string getSeats() {
		return seats;
	}
	string getDoors() {
		return doors;
	}

	//Operator overloading 
	bool operator==(const Car& rightSide) const {
		if (rightSide.model == this->model)
			return true;
		else
			return false;
	}

	bool operator>(const Car& rightSide) const {
		if (rightSide.model > this->model)
			return true;
		else
			return false;
	}

	bool operator<(const Car& rightSide) const {
		if (rightSide.model < this->model)
			return true;
		else
			return false;
	}

	bool operator!=(const Car& rightSide) const {
		if (rightSide.model != this->model)
			return true;
		else
			return false;
	}
};