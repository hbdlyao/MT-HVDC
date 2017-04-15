#pragma once

#include "CmcHvdcGrid.h"
#include "CmcProfile.h"
#include "CmcSolves.h"
#include "CPowerSolveMvc.h"

class CmcSolveMvc : public CPowerSolveMvc
{
public:
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  Run
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.�޸ķ������ܵĶ��壺�������Order�����й���
	//            2.ȡ�����int vGNDType
	// �Ķ�ʱ��:  2017/04/12
	//************************************
	virtual void Run();

protected:

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  RecordResult
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.��һ�ε�����ˮƽ��������󽫽��������Result��
	// �Ķ�ʱ��:  2017/04/13
	//************************************
	virtual void RecordResult();

protected:
	CmcProfile* pmcProfile;
	CmcHvdcGrid* pmcHvdc;
	CmcSolves* pmcSolves;

	virtual void doNewSolves(int vGNDType);

	void doInitRun();
	virtual void doRun();

	void doRun_Ground(string vFlag);
	void doRun_Rd(string vFlag);
	void doRun_Ud(string vFlag);
	void doRun_UdCustom();
	void doRun_Uac(string vFlag);
	void doRun_UacSwap(string vFlag, int vIndex, int vStaCount);
	void doRun_Pd();


public:
	CmcResult* pmcResult;
	virtual void Init();
	virtual void Init(CPowerGrid* vGrid);
	virtual void NodeID(int vGNDType);

public:
	~CmcSolveMvc() ;

	virtual void Clear();
	virtual void Release();

};

class CmcSolvesMvcNormal : public CmcSolveMvc
{

public:
	virtual void Init();

};
