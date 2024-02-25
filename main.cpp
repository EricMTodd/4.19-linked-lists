
//============================================================================
// Name        :
// Author      : Bonnie Bell
// Version     :
// Copyright   : Your copyright notice
// Description : Linked List Fun
//============================================================================

#include <fstream>
#include <iostream>
#include <time.h>

#include "Node.h"

using namespace std;

typedef unsigned int uint;

void printList(Node* list) {
	while (list != nullptr) {
		cout << list->data << "  ";
		list = list->next;
	}
	cout<<endl;
}

int addLists(Node* listA, Node* listB) {
    int sum = 0;
    int carry = 0;
    int multiplier = 1; // To keep track of the digit position

    while (listA != nullptr || listB != nullptr || carry != 0) {
        int digitA = (listA != nullptr) ? listA->data : 0;
        int digitB = (listB != nullptr) ? listB->data : 0;

        int total = digitA + digitB + carry;
        int digitSum = total % 10; // Extract the last digit of the total
        carry = total / 10;        // Update carry for the next iteration

        sum += digitSum * multiplier; // Add the digit to the sum

        // Move to the next nodes in the linked lists
        if (listA != nullptr) listA = listA->next;
        if (listB != nullptr) listB = listB->next;

        // Increment the multiplier to move to the next digit position
        multiplier *= 10;
    }

    return sum;
}

Node* genList(int number) {
	Node* headOfList = new Node(number%10);
	Node* listIterator = headOfList;
	number = number / 10;
	while (number > 0) {
		listIterator->next = new Node(number%10);
		listIterator = listIterator->next;
		number = number/10;
	}
	return headOfList;
}

int main() {
	srand(time(NULL));
	int numA = rand()%10000000;
	int numB = rand()%10000000;
	Node* listA = genList(numA);
	Node* listB = genList(numB);
	int sum = addLists(listA, listB);
	if ( sum == (numA + numB)) {
		cout<<"PASSED basic test (9 pts)"<<endl;
	}
	else {
		cout<<"FAILED expected: "<<numA + numB<<" actual: "<<sum<<endl;
	}

	int numC = rand()%100<<12;
	int numD = rand()%100;
	Node* listC = genList(numC);
	Node* listD = genList(numD);
	sum = addLists(listC, listD);
	if ( sum == (numC + numD)) {
//		cout<<"PASSED A: "<<numA<<" much greater than B:"<<numD<<endl;
		cout<<"PASSED A much greater than B (8 pts)"<<endl;
	}
	else {
		cout<<"FAILED expected: "<<numC + numD<<" actual: "<<sum<<endl;
	}

	int numF = rand()%100<<12;
	int numE = rand()%100;
	Node* listE = genList(numE);
	Node* listF = genList(numF);
	sum = addLists(listE, listF);
	if ( sum == (numE + numF)) {
//		cout<<"PASSED B: "<<numF<<" much greater than A:"<<numE<<endl;
		cout<<"PASSED B much greater than A (8 pts)"<<endl;
	}
	else {
		cout<<"FAILED expected: "<<numE + numF<<" actual: "<<sum<<endl;
	}

	return 0;
}

