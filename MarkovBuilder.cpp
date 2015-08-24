/*
 * File:   MarkovBuilder.cpp
 * Author: Thomas P. Wilson
 *
 * Created on August 22, 2015, 7:10 PM
 */

#include "MarkovBuilder.h"

template<class T>
MarkovBuilder<T>::MarkovBuilder() {}

template<class T>
MarkovBuilder<T>::MarkovBuilder(const MarkovBuilder& orig) {}

template<class T>
MarkovBuilder<T>::MarkovBuilder(const std::vector<T> values) {
	this->values = values;
	for (unsigned int i = 0; i < values.size(); i++) {
		this->value_lookup[values[i]] = i;
	}

	// Initialize adjacency matrix with the initial probabilities for note transitions
	for (unsigned int i = 0; i < values.size(); i++) {
		for (unsigned int j = 0; j < values.size(); j++) {
			this->matrix[i][j] = 0;
		}
	}
}

template<class T>
MarkovBuilder<T>::~MarkovBuilder() {}

template<class T>
void MarkovBuilder<T>::add(T from_value, T to_value) {
	this->matrix[value_lookup[from_value]][value_lookup[to_value]] += 1;
	this->values_added++;
}

template<class T>
T MarkovBuilder<T>::next_value(T from_value) {
	int value = value_lookup[from_value];
	std::vector<int> value_counts = matrix[value];
	int value_index = randomly_choose(value_counts);
	if (value_index < 0) {
		throw "Non-existent value selected.";
	}
	return values[value_index];
}

template<class T>
int MarkovBuilder<T>::randomly_choose(std::vector<int> choices) {
	int counted_sum = 0;
	int count_sum = 0;
	for (unsigned int i = 0; i < choices.size(); i++) {
		count_sum += choices[i];
	}
	int selected_count = (rand() % (count_sum + 1)) + 1;
	for (unsigned int i = 0; i < choices.size(); i++) {
		counted_sum += choices[i];
		if (counted_sum >= selected_count) {
			return i;
		}
	}
	throw "Impossible value selection made";
}