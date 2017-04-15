///////////////////////////////////////////////////////////
//  CxbSolveMvc.cpp
//  Implementation of the Class CxbSolveMvc
//  Created on:      05-4��-2017 18:22:37
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbSolveMvc.h"
#include "CxbDevDCF.h"
#include "CHvdcParams.h"


CxbSolveMvc::~CxbSolveMvc()
{
	pxbResult->Clear();

	delete pxbResult;
	pxbResult = nullptr;

}

void CxbSolveMvc::Clear()
{
	CPowerSolveMvc::Clear();

	pxbResult->Clear();

}


void CxbSolveMvc::Init()
{
	pSolves = new CxbSolves();
	pxbSolves = dynamic_cast<CxbSolves *> (pSolves);

	//
	pProfile = new CxbProfile();
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

	pxbProfile->Init();

	//
	pxbResult = new CxbResult();
	pxbResult->Init();

}


void CxbSolveMvc::Init(CPowerGrid* vGrid)
{
	pGrid = vGrid;
	pxbHvdc = dynamic_cast<CxbHvdcGrid *> (pGrid);

	//
	pxbSolves->Init(pxbProfile, pxbHvdc);

}


void CxbSolveMvc::NodeID(int vGNDType)
{
	pxbProfile->pxbOrder->GroundType = vGNDType;

	//
	pxbSolves->Init(pProfile, pGrid);
	//
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();

}



void CxbSolveMvc::doNewSolves(int vGNDType)
{
	pxbSolves->Clear();
	pxbSolves->NewSolves(vGNDType);
}


int CxbSolveMvc::StaCount()
{
	//return CHvdcParams::StationCount;

	return 3;

}

void CxbSolveMvc::doDCF()
{
	//����
	static int vCount = 1;
	int i, vDevN;
	CDeviceTBL * vTBL;
	CxbDevDCF * vDev;

	vTBL = pGrid->DeviceTBL(xb_DcF);
	vDevN = vTBL->DeviceCount();
	for (i = 0; i < vDevN; i++)
	{
		vDev = dynamic_cast<CxbDevDCF *>(vTBL->Device(i));
		switch (pxbProfile->pxbOrder->DCFDevType)
		{
		case DCF_NoneDev://��ƫ��
			vDev->set_dev(DCF_NoneDev);
			pxbProfile->Flag_DCFOver = 1;
			break;
		case DCF_ConsDev://�㶨ƫ��
			if (vCount == 1)
				vDev->set_dev(DCF_NoneDev);
			if (vCount == 2)
				vDev->set_dev(DCF_ConPDev);
			if (vCount == 3)
			{
				vDev->set_dev(DCF_ConNDev);
				pxbProfile->Flag_DCFOver = 1;
				vCount = 0;
			}

			vCount++;
			break;
		case DCF_RandDev: //����ƫ��
			vDev->set_dev(DCF_RandDev);
			if (vCount >= pxbProfile->pxbOrder->DCFRandTimes)
			{
				pxbProfile->Flag_DCFOver = 1;
				vCount = 0;
			}
			vCount++;
			break;
		}
	}
}



void CxbSolveMvc::Run()
{

	//�๤������
		
		doInitRun();
		
		//
		doRun_Ground(pxbProfile->pxbOrder->Flag_Ground);
}

void CxbSolveMvc::doRecordResult()
{

	//�޿�����
	
	//������
	static int vN = 1;
	string vCaseID = pxbProfile->pxbOrder->CreateCaseID();
	
	//pxbResult->mcResultMap[vCaseID]=
	
	cout << vCaseID;
	cout << "%";
	cout << pxbProfile->pxbOrder->PdPer;
	
	cout << "======" << vN++;
	
	cout << endl;
}


void CxbSolveMvc::doRun()
{

	pxbProfile->ReSetData();
	//
	pxbSolves->Run();
	
	//��¼���
	doRecordResult();
}


void CxbSolveMvc::doInitRun()
{

	//
	pxbSolves->Init(pxbProfile, pxbHvdc);
	//
	int vStaCount = StaCount();

	pxbProfile->pxbOrder->Clear();
	pxbProfile->pxbOrder->InitMatrix(vStaCount);
	
	//
	int vCaseCount = pxbProfile->pxbOrder->CaseCount();
	pxbResult->Clear();
	//pxbResult->Init(vStaCount, vCaseCount, pxbProfile->pxbOrder->PdSize);
}


void CxbSolveMvc::doInitMatrix(){

	int vN;
	
	vN = StaCount();
	
	//
	pxbProfile->InitMatrix(vN);
}


void CxbSolveMvc::doRun_Ground(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	
	//�������/��������/˫��/˫������
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			pxbProfile->pxbOrder->GroundType = mc_GndTypeArr[i];
			
			//���ݽӵ��������� mcCalculate,���豸һһ��Ӧ
			doNewSolves(mc_GndTypeArr[i]);
	
			//�ڵ���
			doNodeID();
	
			//����վ����
			doStationSort();
	
			//��ʼ�������þ���
			doInitMatrix();
		
			//
			doRun_Rd(pxbProfile->pxbOrder->Flag_Rd);
	
		}//if
	
	}//for
}


void CxbSolveMvc::doRun_Rd(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	
	//���衢����
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1') //
		{
			pxbProfile->pxbOrder->RdLevel = mc_RdLevelArr[i];
			
			//
			if (pxbProfile->pxbOrder->IsUdCustom) //ָ��Ud
				doRun_UdCustom();
			else
				doRun_Ud(pxbProfile->pxbOrder->Flag_Ud);
	
		}//if vFlag
	
	}//for
}


void CxbSolveMvc::doRun_Ud(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();
	
	//ȫѹ/80%/70%
	for (int i = 0; i < vN; i++) 
	{
		if (vFlag[i] == '1')
		{
			pxbProfile->pxbOrder->UdLevel = mc_UdLevelArr[i];
	
			if (pxbProfile->pxbOrder->IsUacSwap)
				doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0 ,vStaCount);
			else
				doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);
	
		}//if
	
	}//for
}


void CxbSolveMvc::doRun_UdCustom()
{

	int vStaCount = StaCount();
	
	pxbProfile->pxbOrder->UdLevel = Ud_Custom;
	
	//Ud����
	//�޿���......
	
	//
	if (pxbProfile->pxbOrder->IsUacSwap)
		doRun_UacSwap(pxbProfile->pxbOrder->Flag_Uac, 0, vStaCount);
	else
		doRun_Uac(pxbProfile->pxbOrder->Flag_Uac);
}


void CxbSolveMvc::doRun_Uac(string vFlag){

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();
	
	//���/�/��С/��С
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j=0;j<vStaCount;j++)
				pxbProfile->pxbOrder->UacLevel[j] = mc_UacLevelArr[i];
			//
			doRun_Pd();
		}//if
}


void CxbSolveMvc::doRun_UacSwap(string vFlag, int vIndex, int vStaCount){

	int vN = static_cast<int> (vFlag.size());
	

	//vIndex��0��ʼ,��vIndex==vStaCount,˵�����еĻ���վ��������Uac
	if (vIndex ==vStaCount)
		doRun_Pd();
	else
	{//���/�/��С/��С
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				pxbProfile->pxbOrder->UacLevel[vIndex] = mc_UacLevelArr[i];
	
				doRun_UacSwap(vFlag, vIndex +1,vStaCount);
			}//if
	
	}//else
}


void CxbSolveMvc::doRun_Pd(){

	int vPdSize;
	
	vPdSize = pxbProfile->pxbOrder->PdSize;
	
	for (int i = 0 ; i<vPdSize; i++)
	{		
		pxbProfile->pxbOrder->UpdatePdPercent(i);
	
		doRun();
	
	}//for
}