#pragma once

#include "TMonom.h"

class TPolinom :public TList<TMonomData>
{
public:
	TPolinom();
	TPolinom(TPolinom& _v);
	~TPolinom();

	TPolinom& operator =(const TPolinom& _v);
	TPolinom& operator +=(TMonom& _v);

	TPolinom operator *(const TPolinom& _v);
	TPolinom operator +(const TPolinom& _v);
	TPolinom operator -(const TPolinom& _v);

	string GetPolinom();

	friend ostream& operator <<(ostream& ostr, const TPolinom& P);
	friend istream& operator >>(istream& istr, TPolinom& P);


	void LoadToFile(string name);
	friend ofstream& operator <<(ofstream& ofstr, const TPolinom& P);
};

