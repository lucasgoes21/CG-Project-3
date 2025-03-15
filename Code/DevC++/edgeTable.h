#ifndef EDGE_TABLE_H
#define EDGE_TABLE_H

#include <list>
#include "edgeInfo.h"
#include "point2D.h"

class EdgeTable {
	private: 
		list<EdgeInfo *> *table;
		int yMax;
		int yMin;
		void add(EdgeInfo *);

	public:	
		EdgeTable(const list<Point2D *> &);
		const list<EdgeInfo *> & getList(int n) const;
		int getYMin() const { return yMin; };
		int getYMax() const { return yMax; };
		void clearList(int);
		void print() const;
		~EdgeTable();
};

#endif