/* 
 * File:   MusicMatrix.cpp
 * Author: thomas
 * 
 * Created on August 22, 2015, 6:47 PM
 */

#include <MusicMatrix>

MusicMatrix::MusicMatrix() {
	this->markov = new MarkovBuilder<string>({"a","a#","b","c","c#","d","d#","e","f","f#","g","g#"});
	this->timings = new MarkovBuilder<int>({1,2,4,8,16});
}

MusicMatrix::MusicMatrix(const MusicMatrix& orig) {
}

MusicMatrix::~MusicMatrix() {
}