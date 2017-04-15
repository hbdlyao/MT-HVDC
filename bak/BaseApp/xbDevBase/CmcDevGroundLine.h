#pragma once

#include "CHvdcDeviceBase.h"

/**
 * ����· �ӵؼ�
 */
class CmcDevGroundLine : public CDevShunt
{

protected:	/**
	 * �������ֵ
	 */
	double ZrMax;
	/**
	 * �ӵ����ͣ��������/��������/˫����
	 */
	double ZrMin;


public:
	/**
	 * �������ֵ
	 */
	double GetZrMax();
	/**
	 * �ӵ����ͣ��������/��������/˫����
	 */
	double GetZrMin();
	/**
	 * �������ֵ
	 */
	void SetZrMax(double newVal);
	/**
	 * �ӵ����ͣ��������/��������/˫����
	 */
	void SetZrMin(double newVal);
};

