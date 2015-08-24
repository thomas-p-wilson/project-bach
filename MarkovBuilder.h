/**
 * File:   MarkovBuilder.h
 * Author: Thomas P. Wilson
 *
 * Created on August 22, 2015, 7:10 PM
 */

#include <list>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

#ifndef MARKOVBUILDER_H
#define MARKOVBUILDER_H

template <class T>
class MarkovBuilder {
public:
	MarkovBuilder();
	MarkovBuilder(const MarkovBuilder& orig);
	MarkovBuilder(const std::vector<T> value_list);
	virtual ~MarkovBuilder();
	void add(T from_value, T to_value);
	T next_value(T from_value);

private:
	int values_added = 0;
	std::vector<T> values;
	map<T, int> value_lookup;
	std::vector<std::vector<int>> matrix;
	int randomly_choose(std::vector<int> choices);
};

#endif /* MARKOVBUILDER_H */