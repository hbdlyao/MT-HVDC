///////////////////////////////////////////////////////////
//  CxbCalShunt.cpp
//  Implementation of the Class CxbCalShunt
//  Created on:      05-4��-2017 18:32:21
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalShunt.h"
#include "CxbDevShunt.h"

void CxbCalShunt::UpdateY()
{
	int iNode;
	double vYg, vYb;

	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(pDevice);

	iNode = vDev->GetNodeID(0);
	//jNode = vDev->GetNodeID(1);
	
	//����
	double vOmega = pxbProfile->Omega();
	vYg = vDev->GetYg(vOmega);
	vYb = vDev->GetYb(vOmega);

	//�����0��ʼ
	pxbProfile->UpdateY0(iNode, vYg, vYb);

}