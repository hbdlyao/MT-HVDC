///////////////////////////////////////////////////////////
//  CmcCalConvertor.cpp
//  Implementation of the Class CmcCalConvertor
//  Created on:      02-4��-2017 14:42:20
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalConvertor.h"

void CmcCalConvertor::CalConvertor()
{


}

void CmcCalConvertor::CalConvertorNormal()
{
	int vK = 0;
	int vType;
	double vX;

	CmcDevConvertor * vDev;

	//�޿���
	vK = StationIndex;
	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
		
	//
	vX = pmcProfile->pmcStaData[vK].Ud;
	vDev->SetUdN(vX);

	vX = pmcProfile->pmcStaData[vK].Id;
	vDev->SetIdN(vX);

	//
	vType = vDev->GetStationType();
	switch (vType)
	{
	case Hvdc_Rectify:
		pmcProfile->UpdateR_UN(vK);

		vX=pmcProfile->pmcStaDataN[vK].Udio ;
		vDev->SetUdioN(vX);

		vX=pmcProfile->pmcStaDataN[vK].Uv;
		vDev->SetUvN(vX);
	
		break;
		
	case Hvdc_Invertor:

		pmcProfile->UpdateI_UN(vK);

		vX = pmcProfile->pmcStaDataN[vK].Udio;
		vDev->SetUdioN(vX);

		vX = pmcProfile->pmcStaDataN[vK].Uv;
		vDev->SetUvN(vX);

		break;

	default:
		break;
		}//switch
	 
}

void CmcCalConvertor::Prepare()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//�޿���
	//Yao

	//ʵ��ֵ
	//pmcProfile->pmcStaData[vK].nValvor12 = vDev->GetValvor12Count();//Ӧ������ָ��ֵ

	pmcProfile->pmcStaData[vK].Udio = vDev->GetUdio();
	pmcProfile->pmcStaData[vK].Uv = vDev->GetUv();
	pmcProfile->pmcStaData[vK].Pd = vDev->GetPd();
	pmcProfile->pmcStaData[vK].Ud = vDev->GetUd();
	pmcProfile->pmcStaData[vK].Id = vDev->GetId();

	pmcProfile->pmcStaData[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaData[vK].dr = vDev->GetdrN();
	pmcProfile->pmcStaData[vK].dx = vDev->GetdxN();

	pmcProfile->pmcStaData[vK].alphaOrgamma = vDev->GetAlhpa_gama();
	pmcProfile->pmcStaData[vK].AngCtrl_Max = vDev->GetAngleMax();
	pmcProfile->pmcStaData[vK].AngCtrl_Min = vDev->GetAngleMin();

		
}


void CmcCalConvertor::PrepareNormal() 
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//�޿���
	//Yao

	//�ֵ
	pmcProfile->pmcStaDataN[vK].nValNum = vDev->GetValvor12Count();
	pmcProfile->pmcStaDataN[vK].Uv = vDev->GetUvN();

	pmcProfile->pmcStaDataN[vK].Udio = vDev->GetUdioN();
	pmcProfile->pmcStaDataN[vK].Pd = vDev->GetPdN();
	pmcProfile->pmcStaDataN[vK].Ud = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].Id = vDev->GetIdN();

	pmcProfile->pmcStaDataN[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaDataN[vK].dr = vDev->GetdrN();
	pmcProfile->pmcStaDataN[vK].dx = vDev->GetdxN();

	pmcProfile->pmcStaDataN[vK].alphaOrgamma = vDev->GetAlpha_gamaN();
	pmcProfile->pmcStaDataN[vK].AngCtrl_Max = vDev->GetAngleMax();
	pmcProfile->pmcStaDataN[vK].AngCtrl_Min = vDev->GetAngleMin();

}

void CmcCalConvertor::UpdateJ()
{
	int vK = 0;
	CmcDevConvertor * vDev;
	
	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);	
	switch (vDev->GetStationCtrlType())
	{
	case 1:
		//doUpdateJ_IdCtrl(vK,vDev);
		break;
	
	case 2:
		doUpdateJ_PdCtrl(vK,vDev);			
		break;
	
	case 3:
		doUpdateJ_UdCtrl(vK,vDev);
		break;
	
	case 4:
		doUpdateJ_AngCtrl(vK,vDev);	
		break;
	
	default:
		break;
	}// switch
	
}


void CmcCalConvertor::doUpdateJ_PdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode==-1) //���ӵ�
		pmcProfile->UpdateJ_PdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateJ_PdCtrl(vK, iNode, jNode);

}


void CmcCalConvertor::doUpdateJ_UdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //�ӵ�
		pmcProfile->UpdateJ_UdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateJ_UdCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::doUpdateJ_AngCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //�ӵ�
		pmcProfile->UpdateJ_AngCtrl0(vK, iNode);
	else
		pmcProfile->UpdateJ_AngCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::UpdateF_J()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	switch (vDev->GetStationCtrlType())
	{
	case 1:
		//doUpdateF_IdCtrl(vK,vDev);
		break;

	case 2:
		doUpdateF_PdCtrl(vK, vDev);					
		break;

	case 3:
		doUpdateF_UdCtrl(vK, vDev);					
		break;

	case 4:
		doUpdateF_AngCtrl(vK, vDev);					
		break;

	default:
		break;
	}// switch

}


void CmcCalConvertor::doUpdateF_PdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	

	if (jNode == -1) //�ӵ�
		pmcProfile->UpdateF_PdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateF_PdCtrl(vK, iNode, jNode);

}


void CmcCalConvertor::doUpdateF_UdCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //�ӵ�
		pmcProfile->UpdateF_UdCtrl0(vK, iNode);
	else
		pmcProfile->UpdateF_UdCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::doUpdateF_AngCtrl(int vK, CmcDevConvertor* vDev)
{

	int iNode, jNode;
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	if (jNode == -1) //�ӵ�
		pmcProfile->UpdateF_AngCtrl0(vK, iNode);
	else
		pmcProfile->UpdateF_AngCtrl(vK, iNode, jNode);
}


void CmcCalConvertor::NodeGround(NodeMap & vNodeMap)
{
	bool vGround;
	string vName;
	CmcDevConvertor  * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	//˫��
	vGround = pmcProfile->IsBiPole();
	if (vGround)
	{
		vName = vDev->GetNodeName(1);
		vNodeMap[vName] = -1; //-1��ʾ�ӵ�
	}

	//��������
	vGround = pmcProfile->IsMetalLine();
	vGround = vGround && (vDev->GetIsGround() == 1);
	if (vGround)
	{
		vName = vDev->GetNodeName(1);
		vNodeMap[vName] = -1; //-1��ʾ�ӵ�
	}

}

