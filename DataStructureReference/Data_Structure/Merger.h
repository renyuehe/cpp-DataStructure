#ifndef __MERGER_H__
#define __MERGER_H__

template < class T>
class Merger{
public:
	virtual T merger(T a, T b) = 0;
};

#endif