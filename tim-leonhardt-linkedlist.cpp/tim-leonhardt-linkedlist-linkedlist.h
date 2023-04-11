#pragma once
#include "tim-leonhardt-linkedlist-node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;

public: 
	LinkedList() //Constructor
	{
		head = tail = nullptr;
		size = 0;
	}

	~LinkedList() //Destructor
	{
		Node* temp = new Node();
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		size = 0;
		tail = head = nullptr;
	}

	bool insert(Car& newCar) 
	{	
		//List == empty
		if (head == nullptr)
		{
			Node* temp = new Node();
			temp->data = newCar;
			head = temp; 
			tail = temp;
			size++;
			return true;
		}
		else
		{
			Node* temp = head;

			while (temp != nullptr && newCar < (temp->data))	//Iterate as long as newCar is smaller than current node
				temp = temp->next;

			if (temp != nullptr && newCar == (temp->data))		//If newCar equal to node => already exists --> return false
				return false;

			//At beginning
			else if (temp == head) {
				
				Node* newNode = new Node();
				
				newNode->data = newCar;
				newNode->next = head;
				newNode->previous = nullptr;
				
				head->previous = newNode;
				head = newNode;

				size++;
				return true;
			}

			//At the end 
			else if (temp == nullptr) {

				Node* newNode = new Node();

				newNode->data = newCar;
				newNode->previous = tail;

				tail->next = newNode;
				tail = newNode;

				size++;
				return true;
			}

			//In the middle 
			else {
				Node* newNode = new Node();
				Node* previousNode = temp->previous;

				newNode->data = newCar;
				newNode->next = temp;
				newNode->previous = previousNode;

				temp->previous = newNode;

				previousNode->next = newNode;

				size++;
				return true;
			}
		}
	}

	bool remove(Car& oldCar) 
	{
		//if list == empty 
		if (head == nullptr) {
			return false;
		}
		else{
			
			Node* temp = head;
			
			while (temp != nullptr && (temp->data > oldCar))	//Iterate as long as oldCar is smaller than current node
				temp = temp->next;

			
			if (temp != nullptr && oldCar == temp->data) {
				//Remove from beginning
				if (temp == head) {
					
					head = head->next;
					head->previous = nullptr;
					
					delete temp;

					size--;
					return true;
				}

				//Remove from end
				else if (temp == tail) {
					tail = tail->previous;
					tail->next = nullptr;

					delete temp;

					size--;
					return true;
				}

				//Remove from middle
				else {
					Node* next = new Node();
					Node* prev = new Node();

					next = temp->next;
					prev = temp->previous;

					next->previous = prev;
					prev->next = next;

					delete temp;

					size--;
					return true;
				}
			} 
		}
	}

	bool findCar(Car& findCar, Car*& carLocation) 
	{
		Node* temp = head;
		if (head == nullptr)										//If list = empty, car cannot be found at all 
			return false; 

		while ((temp != nullptr) && (temp->data != findCar)) {		 
			temp = temp->next;
		}

		if (temp == nullptr) {										//If nothing matches, the car must not exist
			return false;											//return false 
		}
		else {
			carLocation = (&(temp->data));							//If current node is equal to findCar and is not a null pointer, assign the variable
			return true;											//carLocation with the memory location of the node
		}
	}

	void outputList() 
	{
		Node* temp = head;

		while (temp != nullptr)										//Iterate through the Linked List and 
		{															
			cout << "\tModel:\t" << temp->data.getModel() << endl;	//output all of each node's attributes 
			cout << "\tBrand:\t" << temp->data.getBrand() << endl;
			cout << "\tColor:\t" << temp->data.getColor() << endl;
			cout << "\tDoors:\t" << temp->data.getDoors() << endl;
			cout << "\tSeats:\t" << temp->data.getSeats() << endl;
			cout << "\tHP:\t" << temp->data.getHorsepower() << endl;
			cout << endl;

			temp = temp->next;
		}
	}

	void getSizeOfLinkedList()
	{
		cout << "Size of this list is: " << size << endl;
	}
};