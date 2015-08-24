/* 
 * File:   MusicMatrix.h
 * Author: Thomas P. Wilson
 *
 * Created on August 22, 2015, 6:47 PM
 */

#include <MarkovBuilder.h>

#ifndef MUSICMATRIX_H
#define	MUSICMATRIX_H

class MusicMatrix {
public:
    MusicMatrix();
    MusicMatrix(const MusicMatrix& orig);
    virtual ~MusicMatrix();

    void add(string to_note);
    string next_note(string from_note);
private:
	string last_note;
	MarkovBuilder<string>* markov;
	MarkovBuilder<int>* timings;
};

#endif	/* MUSICMATRIX_H */