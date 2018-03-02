/* File: VectorDriver.cpp
 * Athr: Lucas Manker
 * Date: 3/2/2018
 *
 * Desc: provides the basic framework and examples for an introduction to
 *       the STL::vector, iterators, and the algorithms facilities.
 */
typedef unsigned long ulong;

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

//Fills a vector with index numbers corresponding to each entry
void fill_vector(vector<short> &data) {
	for (ulong i = 0; i<data.size(); i++) {
		data.at(i) = i;
	}
}

//Prints vector
void print(const vector<short> &data) {
	if (data.empty()) {
		cout << "<empty>";
	}
	else {
		cout << "<" << data.at(0);
		for (ulong i = 1; i<data.size(); i++) {
			cout << ", " << data.at(i);
		}
		cout << ">";
	}
}

//Only prints the even index entries of the vector
void print_even(const vector<short> &data) {
	if (data.empty()) {
		cout << "<empty>";
	}
	else {
		cout << "<" << data.at(2);
		for (ulong i = 4; i<data.size(); i += 2) {
			cout << ", " << data.at(i);
		}
		cout << ">";
	}
}

//Computes a sum of the entries in the vector
short compute_sum(const vector<short> &data) {
	std::vector<short>::const_iterator iter = data.begin();

	short sum = 0;
	while (iter != data.end()) {
		sum += *iter;
		iter++;
	}

	return sum;
}

//Adds 10 random numbers to an empty vector
void add_numbers(vector<short> &data) {
	for (ulong i = 0; i < 10; i++) {
		data.push_back(rand());
	}
}

//Checks to see if value variable is present within the vector, returns a boolean value
bool is_present(const vector<short> &data, short value) {
	std::vector<short>::const_iterator iter = data.begin();
	bool present = false;
	while (iter != data.end()) {
		if (*iter == value) {
			present = true;
			return present;
		}
		iter++;
	}

	return present;
}

int main() {
  cout << "  ..:: B E G I N  S A M P L E  C O D E  ::.." << endl << endl;
  vector<short> sample_vector(5), rand_vector;

  cout << "new vector: ";
  print(sample_vector);
  cout << endl;

  fill_vector(sample_vector);

  cout << "filled vector: ";
  print(sample_vector);
  cout << endl;

  cout << "sum of vector's elements: " << compute_sum(sample_vector) << endl;
  cout << endl << "   ..::  E N D   S A M P L E  C O D E  ::.." << endl;

  //L4.P1
  cout << "vector with random numbers: ";
  add_numbers(rand_vector);
  print(rand_vector);
  cout << endl; 

  //L4.P2
  cout << "only the even entries: " << endl;
  print_even(rand_vector);
  cout << endl;

  //L4.P3
  bool presentT1 = is_present(sample_vector, 1);
  bool presentT2 = is_present(sample_vector, 100);
  cout << "is 1 present in the sample vector? :" << endl;
  char response;
  response = presentT1 == true ? 'T' : 'F';
  cout << response << endl;
  cout << "is 100 present in the sample vector? :" << endl;
  response = presentT2 == true ? 'T' : 'F';
  cout << response << endl;

  //L4.P4
  cout << "new vector:" << endl;
  vector <short> sortVect{ 7,3,8,4,5 };
  print(sortVect);
  cout << endl;
  cout << "new vector sorted: " << endl;
  std::sort(sortVect.begin(), sortVect.end());
  print(sortVect);


  return 0;
}
