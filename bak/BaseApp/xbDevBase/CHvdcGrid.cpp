///////////////////////////////////////////////////////////
//  CHvdcGrid.cpp
//  Implementation of the Class CmcHVDC
//  Created on:      24-3��-2017 15:52:58
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyFunc.h"

#include "CHvdcGrid.h"

#include "CHvdcDefs.h"
#include "CHvdcFunc.h"
#include "gbHead_mcDevice.h"



string CHvdcGrid::TypeToName(int vType)
{

	string vName;
	vName = CHvdcFunc::mcTypeToName(vType);
	
	return vName;
}

int CHvdcGrid::StaCount()
{
	CDeviceTBL * vTBL;

	int vN=0;

	vTBL = DeviceTBL(mc_Convertor);

	if (vTBL!=nullptr)
		vN = vTBL->GetItemCount();
	
	return vN;


}

void CHvdcGrid::Init()
{
	int i;
	CDeviceTBL * vTBL;

	for (i = mc_AcSys; i <= mc_MetalLine; i++)
	{
		vTBL = NewDeviceTBL(i);
		vTBL->SetTblType(i);

	}

}


string CHvdcDeviceTBL::TypeToName(int vDevType){

	string vName;
	vName = CHvdcFunc::mcTypeToName(vDevType);
	
	return vName;
}



CDeviceBase * CHvdcDeviceTBL::doNewDevice(int vDevType) 
{
	CDeviceBase * vDev=nullptr; 
	
	switch (vDevType)
	{
	case mc_AcSys:
		//����ϵͳ  
		vDev = new  CmcDevAcSys();
		break;

	case mc_AcF:
		//�����˲���
		vDev = new  CmcDevAcFilter();
		break;

	case mc_Xf2:
		//˫�����ѹ��  
		vDev = new  CmcDevXf2();
		break;


	case mc_Convertor:
		//������  
		vDev = new  CmcDevConvertor();
		break;

	case mc_DcLine:
		//ֱ������  
		vDev = new  CmcDevDcLine();
		break;


	case mc_GroundLine:
		//�ӵؼ���  
		vDev = new  CmcDevGroundLine();
		break;

	case mc_MetalLine:
		//��������  
		vDev = new  CmcDevMetalLine();
		break;

	case mc_Ground:
		//�ӵؼ�  
		vDev = new  CmcDevGround();
		break;

	default:
		break;

	}//switch

	vDev->Init();

	return vDev;
}


CDeviceTBL * CHvdcGrid::NewDeviceTBL(int vType)
{

	string vName;
	CHvdcDeviceTBL * vTBL;
	
	vName = TypeToName(vType);
	
	//
	vTBL = new CHvdcDeviceTBL();
	vTBL->SetTblType(vType);
	vTBL->SetTblName(vName);
	
	//
	pItems[vType] = vTBL;
	
	return pItems[vType];
}
