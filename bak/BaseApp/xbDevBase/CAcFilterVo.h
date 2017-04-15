///////////////////////////////////////////////////////////
//  CAcFilterVo.h
//  Implementation of the Class CAcFilterVo
//  Created on:      04-4��-2017 7:02:53
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8A30BACD_725C_4c50_89C0_C234185D6455__INCLUDED_)
#define EA_8A30BACD_725C_4c50_89C0_C234185D6455__INCLUDED_

#include "CHvdcDeviceVo.h"

/**
 * ����· �����˲���
 */
class CAcFilterVo : public COneDotVo
{

public:
	/**
	 * �����˲������ͣ�����г/˫��г��
	 */
	int GetAcfType();
	/**
	 * ������ѹ
	 */
	double GetQac();
	/**
	 * �˲����޹�
	 */
	double GetQacf();
	/**
	 * �˲�����޹�
	 */
	double GetQacfN();
	/**
	 * �������ѹ
	 */
	double GetQacN();
	/**
	 * ����
	 */
	double GetZc();
	/**
	 * ����
	 */
	double GetZr();
	/**
	 * �翹
	 */
	double GetZx();
	/**
	 * �����˲������ͣ�����г/˫��г��
	 */
	void SetAcfType(int newVal);
	/**
	 * ������ѹ
	 */
	void SetQac(double newVal);
	/**
	 * �˲����޹�
	 */
	void SetQacf(double newVal);
	/**
	 * �˲�����޹�
	 */
	void SetQacfN(double newVal);
	/**
	 * �������ѹ
	 */
	void SetQacN(double newVal);
	/**
	 * ����
	 */
	void SetZc(double newVal);
	/**
	 * ����
	 */
	void SetZr(double newVal);
	/**
	 * �翹
	 */
	void SetZx(double newVal);
	double GetUac();
	void SetUac(double newVal);
	double GetUacN();
	void SetUacN(double newVal);

protected:
	/**
	 * �����˲������ͣ�����г/˫��г��
	 */
	int AcfType;
	/**
	 * ������ѹ
	 */
	double Qac;
	/**
	 * �˲����޹�
	 */
	double Qacf;
	/**
	 * �˲�����޹�
	 */
	double QacfN;
	/**
	 * �������ѹ
	 */
	double QacN;
	/**
	 * ����
	 */
	double Zc;
	/**
	 * ����
	 */
	double Zr;
	/**
	 * �翹
	 */
	double Zx;
	/**
	 * ���ཻ����ѹ
	 */
	double Uac;
	/**
	 * ����������ѹ
	 */
	double UacN;

};
#endif // !defined(EA_8A30BACD_725C_4c50_89C0_C234185D6455__INCLUDED_)
