///////////////////////////////////////////////////////////
//  CxbOrder.h
//  Implementation of the Class CxbOrder
//  Created on:      05-4��-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
#define EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_
#include <string>
using namespace std;

class CxbOrder
{

public:
	/**
	* ˫��/��������/�������/˫������
	*/
	string Flag_Ground;

	/**
	* �ӵ���ʽ���������/��������/˫��
	*/
	int GroundType;
	//����
	string GroundStaiton;
	//����
	//�˲���ƫ������
	int DCFDevType;
	int DCFRandTimes;

	~CxbOrder();
	void Init();
	void Clear();
	void Release();

};
#endif // !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
