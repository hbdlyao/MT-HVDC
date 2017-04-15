///////////////////////////////////////////////////////////
//  CmcCalAcSys.cpp
//  Implementation of the Class CmcCalAcSys
//  Created on:      02-4��-2017 14:41:33
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalAcSys.h"
#include "CmcDevAcSys.h"

void CmcCalAcSys::Prepare()
{
	int vK=0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//�޿���
	//ʵ��ֵ
	pmcProfile->pmcStaData[vK].Uac = vDev->GetUac();

}


void CmcCalAcSys::PrepareNormal() 
{
	int vK = 0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//�޿���
	//�ֵ
	pmcProfile->pmcStaDataN[vK].Uac = vDev->GetUacN();
}

void CmcCalAcSys::NodeSort(NodeMap& vNodeMap)
{
	//������ڵ���
}


void CmcCalAcSys::NodeID(NodeMap& vNodeID)
{
	//������ڵ���
}

