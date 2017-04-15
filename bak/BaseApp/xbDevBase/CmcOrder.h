#pragma once

#include <string>

using namespace std;

class CmcOrder
{

public:
	//DFBFH22 : 

	string Flag_Pulse = "11";   //˫��/����
	string Flag_Ground= "1111";  //˫��/��������/�������/˫������
	string Flag_Ud    = "1111";  //ȫѹ/80%/70%/Ԥ��
	string Flag_Rd    = "11";    //����/����
	string Flag_Uac   = "1111";  //�/���/��С/��С

	/**
	 * �ӵ���ʽ���������/��������/˫��
	 */
	int GroundType;
	/**
	 * ֱ����ѹ��ȫѹ/80%/70%/Ԥ��
	 */
	int UdLevel;
	/**
	 * ֱ����·������/����
	 */
	int RdLevel;
	/**
	 * ����ϵͳ��ѹ���/���/��С/��С
	 */
	int UacLevel;
	/**
	 * ����ϵͳ��ѹ���Ƿ񽻲�
	 */
	int UacSwap;
	/**
	 * ��ƽ�⹤��
	 */
	int Unbalance;
	/**
	 * ÿ��12��������������1/2
	 */
	int Nof12pulse;

	~CmcOrder();

	void Init();
	void Clear();
	void Release();

};
