#pragma once

#include <string>
#include <map>


using namespace std;

/////////////////////////////////////////
struct struct_mcStaDevIndex
{
	string StatioName;

	int AcSys_Index;
	int AcF_Index;
	int Xf_Index;
	int Convertor_Index;
};

typedef map<string, struct_mcStaDevIndex> mcStaDevIndexMap;

struct struct_mcResult
{
public:
	string CaseID;
	string StatioName;

	double PdPercent;

	int nValvor12;

	double UT;
	double dr, dx;

	//ʵ������
	double Uac;
	double Uv;
	double Tap;

	double Udio;
	double Pd;
	double Ud;
	double Id;

	double Ang;
	double AngMax;
	double AngMin;

};


struct struct_mcStation
{
public:
	string StatioName;

	int nValvor12;

	double UT;
	double dr, dx;

	//ʵ������
	double Uac;
	double Uv;
	double Tap;

	double Udio;
	double Pd;
	double Ud;
	double Id;

	double Ang;
	double AngMax;
	double AngMin;

};

struct struct_BGXB
{

public:
	int hOrder;
	double Urms;
	double Phase;

};


struct struct_Branch
{

public:
	/**
	* ����
	*/
	double Zr;
	/**
	* �п�
	*/
	double Zx_L;
	/**
	* �ݿ�
	*/
	double Zx_C;
	/**
	* ���
	*/
	double Z_L;
	/**
	* ����
	*/
	double Z_C;

};

struct struct_LineMode
{

public:
	/**
	* ֱ�����߸߶�
	*/
	double CSXGD;
	/**
	* ֱ�����߼��
	*/
	double CSXSPJL;
	/**
	* �������봫���߼�߶�
	*/
	double BLXYCSXGDC;
	/**
	* ��·����
	*/
	double XLCD;
	/**
	* ������ˮƽ����
	*/
	double BLXSPJL;
	/**
	* �����߰뾶
	*/
	double CSXBJ;
	/**
	* �����߰뾶
	*/
	double BLXBJ;
	/**
	* �����ߵ絼��
	*/
	double CSXDDL;
	/**
	* �����ߵ�������
	*/
	double CSXDZLX;
	/**
	* �����ߵ�����
	*/
	double CSXDZL;
	/**
	* ������ֱ������
	*/
	double CSXZZDZ;
	/**
	* �����߻���
	*/
	double CSXHC;
	/**
	* �����߷�����
	*/
	double CSXFLS;
	/**
	* �����߷��Ѽ��
	*/
	double CSXFLJJ;
	/**
	* �����ߵ�������
	*/
	double BLXDZLX;
	/**
	* �����ߵ絼��
	*/
	double BLXDDL;
	/**
	* �����ߵ�����
	*/
	double BLXDZL;
	/**
	* ������ֱ������
	*/
	double BLXZZDZ;
	/**
	* �����߻���
	*/
	double BLXHC;
	/**
	* �����߷�����
	*/
	double BLXFLS;
	/**
	* �����߷��Ѽ��
	*/
	double BLXFLJJ;
	/**
	* ����������
	*/
	double TRDZL;

};

enum Enum_HvdcConvertorType
{
	Hvdc_Rectify = 0,
	Hvdc_Invertor = 1,

};

enum Enum_mcGroundType
{
	mc_Ground10 = 10,
	mc_Ground11 = 11,
	mc_Ground20 = 20,
	mc_Ground21 = 21

};

enum Enum_mcDeviceType
{
	mc_AcSys = 11,
	mc_AcF,
	mc_Xf2,
	mc_Convertor,
	mc_DcLine,
	mc_GroundLine,
	mc_MetalLine,
	mc_Ground

};

enum Enum_mcCaseFlag
{
	mcCaseBit_Pulse = 0,
	mcCaseBit_Power,
	mcCaseBit_GND,
	mcCaseBit_Ud,
	mcCaseBit_Rd,
	mcCaseBit_Uac
};

enum Enum_xbGroundType
{
	xb_Ground10 = 10,
	xb_Ground11 = 11,
	xb_Ground20 = 20,
	xb_Ground21 = 21


};

enum Enum_xbDeviceType
{
	xb_3pVSrc = 1,
	xb_xf2,
	xb_PbDKQ,
	xb_DcF,
	xb_DcLine,
	xb_GroundLine,
	xb_Ground,
	xb_MetalLine,
	xb_XfC,
	xb_CoupleC,
	xb_PulseC,
	xb_Shunt,
	xb_Branch,

	//
	xb_Branch3,
	xb_Trap,
	xb_Jkzz

};

enum Enum_DCFType
{
	DCF_None,
	DCF_Single,
	DCF_Double,
	DCF_DoubleHighPass,
	DCF_Triple,
	DCF_TripleHighPass
};


//ֱ���˲���ƫ������
enum Enum_DCFOrder
{
	DCF_NoneDev = 0, //��ƫ��
	DCF_ConsDev = 1, //�㶨ƫ��
	DCF_RandDev = 2, //����ƫ��
	DCF_ConPDev = 3, //��ƫ��
	DCF_ConNDev = 4  //��ƫ��
};
