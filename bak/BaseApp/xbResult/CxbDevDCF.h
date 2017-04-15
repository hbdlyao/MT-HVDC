///////////////////////////////////////////////////////////
//  CxbDevDCF.h
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4��-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
#define EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_

#include "CxbDevTwoDot.h"

//����
#include "CComplex.h"
#include "gbHead_Def.h"
#include "CRand.h"

/**
* ֱ���˲���
*/
class CxbDevDCF : public CxbDevTwoDot
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
	//����
	//����
	double C1;
	double C2;
	double C3;
	double L1;
	double L2;
	double L3;
	double R1;
	double R2;
	//����ƫ��
	double PdC1;
	double PdC2;
	double PdC3;
	double PdL1;
	double PdL2;
	double PdL3;
	double PdR1;
	double PdR2;
	double Pdf;
	double NdC1;
	double NdC2;
	double NdC3;
	double NdL1;
	double NdL2;
	double NdL3;
	double NdR1;
	double NdR2;
	double Ndf;
	//ʵ��ƫ��
	double ddC1;
	double ddC2;
	double ddC3;
	double ddL1;
	double ddL2;
	double ddL3;
	double ddR1;
	double ddR2;
	double ddf;
	//����
	int Type;
	//Ƶ��
	double Frequency;
	//
	double get_C1();
	double get_C2();
	double get_C3();
	double get_L1();
	double get_L2();
	double get_L3();
	double get_R1();
	double get_R2();
	double get_f();
public:
	void SetType(double newVal);
	void SetFrequency(double newVal);
	void InitY(int vhOrder);
	//����ʵ��ƫ��
	void set_dev(int type);
	/**
	* 3P�ĵ�Ч�絼
	*/
	double GetYg();
	/**
	* 3P�ĵ�Ч����
	*/
	double GetYb();
	/**
	* 3P�ĵ�Ч�絼
	*/
	void SetYg(double newVal);
	/**
	* 3P�ĵ�Ч����
	*/
	void SetYb(double newVal);
};
#endif // !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
