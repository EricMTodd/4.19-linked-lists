# 4.19-linked-lists

Your assignment this week is to work with linked lists. In order to pass all the tests it is important to understand how and when to check for the end condition of a linked list. You will write a function int addLists(Node* listA, Node* listB). The two linked lists represent numbers, where each element in the list is a digit with the least significant number in the first link position ie: the number 1234 will be represented as list->4 ->3 -> 2->1. Your job is to add the two numbers and return the sum. There is 25 points available in the tests, the tests will check if you correctly return the sum when the two numbers are relatively close in size, when A is much bigger than B and vice versus. Not tested but available for 5pts extra credit is if you write a recursive algorithm to traverse the lists that sums the numbers recursively (that means no global variables, the accumulate must be based on and returned in the recursive call).