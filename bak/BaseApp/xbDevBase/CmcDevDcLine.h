#pragma once

#include "CHvdcDeviceBase.h"
/**
 * ����· ֱ������
 */
class CmcDevDcLine : public CDevBranch
{

public:
	struct_LineMode *structLineMode;
	struct_Branch *structBranch;
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

protected:
	/**
	 * �������ֵ
	 */
	double ZrMax;
	/**
	 * �ӵ����ͣ��������/��������/˫����
	 */
	double ZrMin;

};

