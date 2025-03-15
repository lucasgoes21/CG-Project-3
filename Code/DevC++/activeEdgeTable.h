#ifndef ACTIVE_TABLE_H
#define ACTIVE_TABLE_H

#include <iterator>
#include <list>
#include "edgeInfo.h"

class ActiveEdgeTable {
	private:
		list<EdgeInfo *> AET;
		list<EdgeInfo *>::iterator it;
	public:
		ActiveEdgeTable() {};
		void extend(const list<EdgeInfo *> &);
		void sort();
		int getSize() const { return AET.size(); };
		bool getOneBlockLimits(double *, double *);
		void updateXValues();
		void removeEdgesByYMax(int);
		void print() const;
};

#endif