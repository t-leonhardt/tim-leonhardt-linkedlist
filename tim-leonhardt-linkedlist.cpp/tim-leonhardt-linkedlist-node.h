#pragma once
#include "tim-leonhardt-linkedlist-car-class.h"

class Node {
public:
	Node* next;
	Node* previous;
	Car data;

	Node() {
		next = previous = nullptr;
	}
};