#pragma once


#include <string>

#include <comutil.h>

//#include "stdafx.h"

using namespace std;


class CMyFunc
{

protected:
	CMyFunc();
	virtual ~CMyFunc();
	CMyFunc(const CMyFunc& theCMyFunc);

public:
	static string CreateObjID();

	static string VarToStr(_variant_t & vVar);

};

