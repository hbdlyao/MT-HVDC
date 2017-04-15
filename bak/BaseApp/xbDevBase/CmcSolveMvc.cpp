///////////////////////////////////////////////////////////
//  CmcSolveMvc.cpp
//  Implementation of the Class CmcSolveMvc
//  Created on:      09-4��-2017 23:54:44
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcSolveMvc.h"

void CmcSolveMvc::Init()
{
	pSolves = new CmcSolves();
	pmcSolves= dynamic_cast<CmcSolves *> (pSolves);
	//

}

void CmcSolveMvc::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	pGrid = vGrid;

	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
	pmcHvdc = dynamic_cast<CmcHvdcGrid *> (pGrid);

}

void CmcSolveMvc::doNewSolves(int vGNDType)
{
	pmcSolves->Clear();
	pmcSolves->NewSolves(vGNDType);
}


void CmcSolveMvc::Run(int vGNDType)
{
	pmcProfile->pmcOrder->GroundType = vGNDType;

	//
	pmcSolves->Init(pProfile, pGrid);
	//
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();
	
	//���վ����
	doStationSort();

	//
	doRun();

}


void CmcSolveMvc::NodeID(int vGNDType)
{
	pmcProfile->pmcOrder->GroundType = vGNDType;

	//
	pmcSolves->Init(pProfile, pGrid);
	//
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();
	
}


void CmcSolveMvc::doRun()
{
	//
	pmcProfile->Clear();
	//
	pmcSolves->Run();
}

////////////////////////////////
void CmcSolvesMvcNormal::Init()
{

	pSolves = new CmcSolvesNormal();
	pmcSolves = dynamic_cast<CmcSolves *> (pSolves);

}