///////////////////////////////////////////////////////////
//  CxbSolveMvc.cpp
//  Implementation of the Class CxbSolveMvc
//  Created on:      05-4��-2017 18:22:37
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbSolveMvc.h"
#include "CxbDevDCF.h"


void CxbSolveMvc::Init()
{
	pSolves = new CxbSolves();
	pxbSolves = dynamic_cast<CxbSolves *> (pSolves);
	//
	pProfile = new CxbProfile();
	pxbProfile = dynamic_cast<CxbProfile *> (pProfile);

	pxbProfile->Init();

}


void CxbSolveMvc::Init(CPowerGrid* vGrid)
{
	pGrid = vGrid;

	pxbHvdc = dynamic_cast<CxbHvdcGrid *> (pGrid);

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


void CxbSolveMvc::Run(int vGNDType)
{
	pxbProfile->pxbOrder->GroundType = vGNDType;


	//
	pxbSolves->Init(pProfile, pGrid);
	//����
	//if(!GetNew3P(pxbSolves->pxvHvdc))return;//�����������ݸ������ݣ�û�м������
	//vGNDType=
	doNewSolves(vGNDType);

	//�ڵ���
	doNodeID();
	//
	doStationSort();
	//����
	pxbProfile->Flag_DCFOver = 0;

	while (!(pxbProfile->Flag_DCFOver))
	{
		doDCF();
		//
		doRun();//�������Ķ๤���ļ���

		break;
	}

}


void CxbSolveMvc::doNewSolves(int vGNDType)
{
	pxbSolves->Clear();
	pxbSolves->NewSolves(vGNDType);
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

void CxbSolveMvc::doRun()
{
	//���ǹ���(����ˮƽ)��DCFƫ�����͡�г������

	//����

	//г������1-H_CAL_NUM
	for (int i = 1; i <= H_CAL_NUM; i++)
	{
		pxbProfile->Clear();
		pxbProfile->xbHOrder = i;
		pxbSolves->Run();
	}
}

