#pragma once


#include "CDeviceBase.h"
#include "CHvdcDefs.h"
#include "CComplex.h"

class CHvdcDeviceBase : public CDeviceBase
{
};

/**
 * һ�˵��豸
 */
class CDevOneDot : public CHvdcDeviceBase
{
protected:
	virtual void Init()  ;

};

/**
 * ˫�˵��豸
 */
class CDevTwoDot : public CHvdcDeviceBase
{

protected:
	virtual void Init() ;

};

/**
 * RLC����֧·
 */
class CDevShunt : public CDevOneDot
{
protected:
	/**
	 * ֧·����
	 */
	struct_Branch structBranch;

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

	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmega);

};

/**
 * ����֧·
 */
class CDevBranch : public CDevTwoDot
{
protected:
	/**
	 * �ܶ˻���վ����
	 */
	string StationName1;
	/**
	 * �ܶ˻���վ����
	 */
	string StationName2;


public:
	/**
	 * ֧·����
	 */
	struct_Branch structBranch;

	virtual void Init();

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

	/**
	 * �ܶ˻���վ����
	 */
	string GetStationName1();
	/**
	 * �ܶ˻���վ����
	 */
	string GetStationName2();
	/**
	 * �ܶ˻���վ����
	 */
	void SetStationName1(string newVal);
	/**
	 * �ܶ˻���վ����
	 */
	void SetStationName2(string newVal);
	virtual double GetY();
	virtual double GetYg();
	virtual double GetYb();

	virtual double GetYg(double vOmega);
	virtual double GetYb(double vOmega);


};
