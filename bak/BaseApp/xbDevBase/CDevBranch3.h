///////////////////////////////////////////////////////////
//  CDevBranch3.h
//  Implementation of the Class CxbDevBranch3
//  Created on:      05-4��-2017 18:06:38
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_9DCA5352_91CF_42dc_9575_AAA4CBE06A1A__INCLUDED_)
#define EA_9DCA5352_91CF_42dc_9575_AAA4CBE06A1A__INCLUDED_

#include "CHvdcDeviceBase.h"

class CDevBranch3 : public CDevTwoDot
{
protected:
	/**
	 * 3P�ĵ�Ч�絼
	 */
	double Yg;
	/**
	 * 3P�ĵ�Ч����
	 */
	double Yb;



public:
	/**
	 * 3P�ĵ�Ч�絼
	 */
	double GetYg();
	/**
	 * 3P�ĵ�Ч�絼
	 */
	void SetYg(double newVal);
	/**
	 * 3P�ĵ�Ч����
	 */
	double GetYb();
	/**
	 * 3P�ĵ�Ч����
	 */
	void SetYb(double newVal);
};
#endif // !defined(EA_9DCA5352_91CF_42dc_9575_AAA4CBE06A1A__INCLUDED_)
