/* File: VectorDriver.h
 * Athr: Lucas Manker
 * Date: 3/2/18
 *
 * Desc: provides the basic framework and examples for an introduction to
 *       the STL::vector, iterators, and the algorithms facilities.
 *
 * Edited by: Rafer Cooley
 * Date: Oct. 1, 2017
 */
//
typedef unsigned long ulong;

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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