///////////////////////////////////////////////////////////
//  CxbDevShunt.h
//  Implementation of the Class CxbDevShunt
//  Created on:      12-4��-2017 12:00:41
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_472CF7D9_FB58_4953_A33F_BC63919B2769__INCLUDED_)
#define EA_472CF7D9_FB58_4953_A33F_BC63919B2769__INCLUDED_

#include "CHvdcDefs.h"
#include "CxbDevOneDot.h"

/**
 * RLC����֧·
 */
class CxbDevShunt : public CxbDevOneDot
{

public:
	double GetZr();
	double GetZ_C();
	double GetZ_L();
	double GetZx_C();
	double GetZx_L();
	void SetZr(double vValue);
	void SetZ_C(double vValue);
	void SetZ_L(double vValue);
	void SetZx_C(double vValue);
	void SetZx_L(double vValue);
	virtual void Init();
	virtual double GetY();
	virtual double GetYg();
	virtual double GetYb();
	/**
	 * ����
	 */
	virtual double GetYg(double vOmega);
	/**
	 * ����
	 */
	virtual double GetYb(double vOmega);

protected:
	/**
	 * ֧·����
	 */
	struct_Branch structBranch;

};
#endif // !defined(EA_472CF7D9_FB58_4953_A33F_BC63919B2769__INCLUDED_)
