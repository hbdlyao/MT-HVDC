///////////////////////////////////////////////////////////
//  CPowerSolveMvc.cpp
//  Implementation of the Class CPowerSolveMvc
//  Created on:      09-4��-2017 21:45:59
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerSolveMvc.h"


CPowerSolveMvc::~CPowerSolveMvc()
{
	Release();
}


void CPowerSolveMvc::Clear()
{
	pSolves->Clear();
}


void CPowerSolveMvc::Release()
{
	Clear();
	//
	delete pSolves;
	pSolves = nullptr;
}


void CPowerSolveMvc::Init()
{
	pSolves = new CPowerSolves();

}

void CPowerSolveMvc::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;

	pGrid = vGrid;
}


void CPowerSolveMvc::NodeID()
{
	//
	pSolves->Init(pProfile, pGrid);
	//
	doNewSolves();
	
	//�ڵ���
	doNodeID();
}


void CPowerSolveMvc::Run()
{
	//
	pSolves->Init(pProfile, pGrid);
	//
	doNewSolves();

	//�ڵ���
	doNodeID();

	//
	doStationSort();

	//
	doRun();
}


void CPowerSolveMvc::doRun()
{
	//
	pProfile->Clear();
	//
	pSolves->Run();
}


void CPowerSolveMvc::doNewSolves()
{
	pSolves->Clear();
	pSolves->NewSolves();
}


void CPowerSolveMvc::doNodeID()
{
	pSolves->NodeID();
}


void CPowerSolveMvc::doStationSort()
{
	pSolves->StationSort();
}

