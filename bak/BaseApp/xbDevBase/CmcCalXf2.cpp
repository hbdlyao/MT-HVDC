///////////////////////////////////////////////////////////
//  CmcCalXf2.cpp
//  Implementation of the Class CmcCalXf2
//  Created on:      02-4��-2017 14:41:57
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalXf2.h"


void CmcCalXf2::Prepare()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	//�޿���
	//�ֵ
	pmcProfile->pmcStaDataN[vK].Tap = vDev->GetTapN();

	//ʵ��ֵ
	pmcProfile->pmcStaData[vK].Tap = vDev->GetTap();

}


void CmcCalXf2::CalTap()
{

}

void CmcCalXf2::CalTapNormal()
{
	int vK = 0;
	double vX;

	CmcDevXf2 * vDev;

	//�޿���
	vK = StationIndex;

	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);
		
	//TapN=0 ?
	pmcProfile->UpdateTapN(vK);

	vX = pmcProfile->pmcStaDataN[vK].Tap;

	vDev->SetTapN(ceil(vX)); //ȡ��

}



void CmcCalXf2::NodeSort(NodeMap& vNodeMap)
{

}


void CmcCalXf2::NodeID(NodeMap& vNodeID)
{
}