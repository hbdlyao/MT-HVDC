///////////////////////////////////////////////////////////
//  CmcCalAcSys.cpp
//  Implementation of the Class CmcCalAcSys
//  Created on:      02-4��-2017 14:41:33
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalAcSys.h"


void CmcCalAcSys::Prepare()
{
	int vK=0;
	CmcDevAcSys * vDev;

	vDev = dynamic_cast<CmcDevAcSys *>(pDevice);
	vK = StationIndex;

	//�޿���
	//Yao
	//�ֵ
	pmcProfile->pmcStaDataN[vK].Uac = vDev->GetUacN();

	//ʵ��ֵ
	pmcProfile->pmcStaData[vK].Uac = vDev->GetUac();

}


void CmcCalAcSys::NodeSort(NodeMap& vNodeMap)
{

}


void CmcCalAcSys::NodeID(NodeMap& vNodeID)
{
}