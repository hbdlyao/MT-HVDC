///////////////////////////////////////////////////////////
//  CmcCalAcFilter.cpp
//  Implementation of the Class CmcCalAcFilter
//  Created on:      02-4��-2017 14:41:26
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalAcFilter.h"


void CmcCalAcFilter::Prepare()
{
	int vK;
	CmcCalAcFilter * vDev;

	vDev = dynamic_cast<CmcCalAcFilter *>(pDevice);
	vK = StationIndex;

	//�޿���
	//�ֵ
	//pmcProfile->pmcStaDataN[vK].Qac = vDev->GetQacN();

	//ʵ��ֵ
	//pmcProfile->pmcStaData[vK].Qac = vDev->GetQac();


}


void CmcCalAcFilter::NodeSort(NodeMap& vNodeMap)
{

}


void CmcCalAcFilter::NodeID(NodeMap& vNodeID)
{
}