///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.h
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4��-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
#define EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_

#include "CxbDevTwoDot.h"
#include "gbHead_Def.h"


/**
* ��������ѹԴ
*/
class CxbDev3pVSrc : public CxbDevTwoDot
{

protected:
	//����
	/**
	* 3P�ĵ�Ч�絼
	*/
	//doubleVector Yg;
	/**
	* 3P�ĵ�Ч����
	*/
	//doubleVector Yb;
	doubleVector UhVect;
	/**
	* ������Դ���
	*/
	doubleVector PhhVect;
	/**
	* ���������
	*/
	double L;
public:

	//����
	/**
	* 3P�ĵ�Ч�絼
	*/
	//double GetYg();
	/**
	* 3P�ĵ�Ч�絼
	*/
	//void SetYg(double newVal);
	/**
	* 3P�ĵ�Ч����
	*/
	//double GetYb();//����
	/**
	* 3P�ĵ�Ч����
	*/
	//void SetYb(double newVal);

	//����
	void SetL(double newVal);
	virtual double GetUre(int vhOrder);
	virtual double GetUim(int vhOrder);
	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmeg);
};

#endif // !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
