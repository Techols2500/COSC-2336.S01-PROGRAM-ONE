//************************************************************************** 
//
// Programming Excerise 1   
// CLASS: COSC 2336.S01
// AUTHOR: TYLER ECHOLS 
// DATE: Sep 2017  
//
//************************************************************************** 


#ifndef	REF_COUNT_H
#define	REF_COUNT_H

class RefCount
{
	//______________________ Methods _______________________________________
public:
	RefCount();
	virtual	~RefCount();
	void	UpCount();
	void	DownCount();

private: 
	//______________________ Properties _______________________________________
	int		References;
};

//______________________ Method Definitions _______________________________________
inline void RefCount::UpCount()
{
	++References;
}

inline void RefCount::DownCount()
{
	if (--References == 0)
		delete this;
	else;
}

#endif
