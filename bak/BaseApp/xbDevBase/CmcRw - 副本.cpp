///////////////////////////////////////////////////////////
//  CmcRw.cpp
//  Implementation of the Class CmcRw
//  Created on:      02-4月-2017 15:35:07
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcRw.h"
#include "gbHead_mcDevice.h"
#include "CHvdcDefs.h"
#include "CMyDefs.h"

#include "gbHead_Var.h"
#include <iostream>


void CmcRw::doLoad()
{
	doLoad_AcSys();
	doLoad_AcFilter();
	doLoad_Xf2();
	doLoad_Convertor();
	
	doLoad_DcLine();
	doLoad_MetalLine();
	doLoad_GroundLine();
	
	
	/*
	doLoad_Ground();

	doLoad_DcFilter();
	doLoad_PbDKQ();
	doLoad_ZBQ();
	doLoad_Jkzz();
	doLoad_PulseC();
	doLoad_CoupleC();
	*/
}


void CmcRw::doSave()
{

	doSave_AcSys();
	doSave_AcFilter();
	doSave_Xf2();
	doSave_Convertor();
	
	doSave_DcLine();
	doSave_MetalLine();
	doSave_GroundLine();

	
	/*
	doSave_Ground();
	doSave_DcFilter();
	doSave_PbDKQ();
	doSave_ZBQ();
	doSave_Jkzz();
	doSave_PulseC();
	doSave_CoupleC();
	*/
}


void CmcRw::InitAdo(string vDbf)
{

	dbfName = vDbf;
	
	//RwAdo = new CRwAdo_MDB();
	
	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}


void CmcRw::doLoad_AcSys()
{

	CDeviceTBL * vTBL;
	CmcDevAcSys * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_AcSys;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_AcSys);
			vDev = dynamic_cast<CmcDevAcSys *>(vTBL->NewDevice(mc_AcSys));

			//
			RwAdo->GetFieldValue("DeviceID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetDeviceID(vStr);
			};

			RwAdo->GetFieldValue("DeviceName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue;
				vDev->SetDeviceName(vStr);
			};

			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetDeviceType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Pac", vValue);

			if (vValue.vt != VT_NULL)
			{
				vDev->SetPac(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Qac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQac(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("QacN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQacN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("PacN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetPacN(vValue.dblVal);
			};

			RwAdo->GetFieldValue("Sac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetSac(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("SacN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetSacN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Uac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUac(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UacN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUacN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Qinmax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQinMax(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Qoutmax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQinMax(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UacExMin", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUacExMin(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UacMax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUacMin(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UacMin", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUacMin(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UacLevel", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUacLevel(vValue.iVal); //双精度
			};

			RwAdo->GetFieldValue("APhase", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAPhase(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zr", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZr(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("dotCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdotCount(vValue.iVal);
			};

			RwAdo->GetFieldValue("StationName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName(vStr);
			};

			RwAdo->GetFieldValue("NodeName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(0, vStr);
			};

			RwAdo->GetFieldValue("NodeID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(0, vValue.iVal);//整型
			};
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

		

	}//if

	RwAdo->CloseTBL();

}//void


void CmcRw::doLoad_AcFilter()
{

	CDeviceTBL * vTBL;
	CmcDevAcFilter * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_AcF;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;
		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_AcF);
			vDev = dynamic_cast<CmcDevAcFilter *>(vTBL->NewDevice(mc_AcF));

			//
			RwAdo->GetFieldValue("DeviceID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetDeviceID(vStr);
			};

			RwAdo->GetFieldValue("DeviceName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue;
				vDev->SetDeviceName(vStr);
			};

			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetDeviceType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("AcfType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAcfType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Qacf", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQacf(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("QacfN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQacfN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Qac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQac(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("QacN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQacN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zr", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZr(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zc", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZc(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("dotCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdotCount(vValue.iVal);
			};

			RwAdo->GetFieldValue("StationName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName(vStr);
			};

			RwAdo->GetFieldValue("NodeName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(0, vStr);
			};

			RwAdo->GetFieldValue("NodeID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(0, vValue.iVal);//整型
			};
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}//void

void CmcRw::doLoad_Xf2()
{

	CDeviceTBL * vTBL;
	CmcDevXf2 * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_Xf2;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_Xf2);
			vDev = dynamic_cast<CmcDevXf2 *>(vTBL->NewDevice(mc_Xf2));

			//
			RwAdo->GetFieldValue("DeviceID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetDeviceID(vStr);
			};

			RwAdo->GetFieldValue("DeviceName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue;
				vDev->SetDeviceName(vStr);
			};

			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetDeviceType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("AngleMax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAngleMax(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("AngleMin", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAngleMin(vValue.dblVal);
			};

			RwAdo->GetFieldValue("TapCtrlType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTapCtrlType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("FixedURef", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetFixedURef(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("FixedUType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetFixedUType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("SN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetSN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Tap", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTap(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("TapMax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTapMax(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("TapMin", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTapMin(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("TapN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTapN(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Tk", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTk(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("TkN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTkN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UacN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUacN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Uac", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUac(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Uv", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUv(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UvMax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUvMax(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UvN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUvN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Ukp", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUkp(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zr", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZr(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("TapSetup", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetTapSetup(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("L_deltaA", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetL_DeltaA(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("L_deltaB", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetL_DeltaB(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("L_deltaC", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetL_DeltaC(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zc", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZc(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("ZL", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZL(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("L_deltaPMax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetL_DeltaPMax(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("L_deltaType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetL_DeltaType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("ZL", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZL(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("dotCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdotCount(vValue.iVal);
			};

			RwAdo->GetFieldValue("NodeName2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(1, vStr);
			};

			RwAdo->GetFieldValue("NodeName1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(0, vStr);
			};

			RwAdo->GetFieldValue("NodeID2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(1, vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("NodeID1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(0, vValue.iVal);//整型
			};

			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}//void


void CmcRw::doLoad_Convertor()
{

	CDeviceTBL * vTBL;
	CmcDevConvertor * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_Convertor;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;
		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_Convertor);
			vDev = dynamic_cast<CmcDevConvertor *>(vTBL->NewDevice(mc_Convertor));

			//
			RwAdo->GetFieldValue("DeviceID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetDeviceID(vStr);
			};

			RwAdo->GetFieldValue("DeviceName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue;
				vDev->SetDeviceName(vStr);
			};

			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetDeviceType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Alhpa_gama", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAlhpa_gama(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Alpha_gamaN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAlpha_gamaN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("AngleMax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAngleMax(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("AngleMin", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAngleMin(vValue.dblVal);
			};

			RwAdo->GetFieldValue("StationType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetStationType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("StationCtrlType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetStationCtrlType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("drN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdrN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("dxN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdxN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("LengthToSide", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetLengthToSide(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Pd", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetPd(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("PdN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetPdN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Ud", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUd(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UdN", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUdN(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("UT", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetUT(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Valvor12Count", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetValvor12Count(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Qmin", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetQmin(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Angle_DeltaType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAngle_DeltaType(vValue.iVal); //双精度
			};

			RwAdo->GetFieldValue("AngleDeltaPMax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetAngleDeltaPMax(vValue.dblVal); //双精度
			};

			//RwAdo->GetFieldValue("AngleDeltaVect", vValue);
			if (vValue.vt != VT_NULL)
			{
				//vDev->SetAngleDeltaVect(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("IsGround", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetIsGround(vValue.iVal); //双精度
			};

			RwAdo->GetFieldValue("Id", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetId(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("dotCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdotCount(vValue.iVal);
			};

			RwAdo->GetFieldValue("NodeName2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(1, vStr);
			};

			RwAdo->GetFieldValue("NodeName1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(0, vStr);
			};

			RwAdo->GetFieldValue("NodeID2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(1, vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("NodeID1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(0, vValue.iVal);//整型
			};
			//
			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}//void

void CmcRw::doLoad_DcLine()
{

	CDeviceTBL * vTBL;
	CmcDevDcLine * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_DcLine;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;
		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_DcLine);
			vDev = dynamic_cast<CmcDevDcLine *>(vTBL->NewDevice(mc_DcLine));

			doLoad_Branch(vDev);

			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}//void


void CmcRw::doLoad_MetalLine()
{

	CDeviceTBL * vTBL;
	CmcDevMetalLine * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_MetalLine;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_MetalLine);
			vDev = dynamic_cast<CmcDevMetalLine *>(vTBL->NewDevice(mc_MetalLine));

			doLoad_Branch(vDev);

			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}//void

void CmcRw::doLoad_GroundLine()
{

	CDeviceTBL * vTBL;
	CmcDevGroundLine * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_GroundLine;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;

		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_GroundLine);
			vDev = dynamic_cast<CmcDevGroundLine *>(vTBL->NewDevice(mc_GroundLine));

			RwAdo->GetFieldValue("DeviceID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetDeviceID(vStr);
			};

			RwAdo->GetFieldValue("DeviceName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue;
				vDev->SetDeviceName(vStr);
			};

			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetDeviceType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("dotCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdotCount(vValue.iVal);
			};

			RwAdo->GetFieldValue("StationName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName(vStr);
			};

			RwAdo->GetFieldValue("NodeName1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(0, vStr);
			};

			RwAdo->GetFieldValue("NodeID1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(0, vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Zr", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZr(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Z_L", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZ_L(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Z_C", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZ_C(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx_L", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx_L(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx_C", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx_C(vValue.dblVal); //双精度
			};


			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}//void


void CmcRw::doLoad_Ground()
{

	CDeviceTBL * vTBL;
	CmcDevGround * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;
	bool vOk;

	vtblName = CHvdcParams::tbl_Ground;

	vSQL = "select * from " + vtblName;
	vOk = RwAdo->OpenSQL(vSQL);

	if (vOk)
	{
		cout << "Load---" + vtblName + "---" << endl;
		while (!RwAdo->IsEOF())
		{
			vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_Ground);
			vDev = dynamic_cast<CmcDevGround *>(vTBL->NewDevice(mc_Ground));

			//
			RwAdo->GetFieldValue("DeviceID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetDeviceID(vStr);
			};

			RwAdo->GetFieldValue("DeviceName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue;
				vDev->SetDeviceName(vStr);
			};

			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetDeviceType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("dotCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdotCount(vValue.iVal);
			};

			RwAdo->GetFieldValue("StationName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName(vStr);
			};

			RwAdo->GetFieldValue("NodeName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(0, vStr);
			};

			RwAdo->GetFieldValue("NodeID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(0, vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Zr", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZr(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Z_L", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZ_L(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Z_C", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZ_C(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx_L", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx_L(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx_C", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx_C(vValue.dblVal); //双精度
			};

			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;

		}//while

	}//if

	RwAdo->CloseTBL();

}//void

void CmcRw::doLoad_Branch(CmcDevDcLine * vDev)
{
	string vStr;
	_variant_t vValue;

			RwAdo->GetFieldValue("DeviceID", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetDeviceID(vStr);
			};

			RwAdo->GetFieldValue("DeviceName", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue;
				vDev->SetDeviceName(vStr);
			};

			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetDeviceType(vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("StationName1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName1(vStr);
			};

			RwAdo->GetFieldValue("StationName2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetStationName2(vStr);
			};

			RwAdo->GetFieldValue("ZrType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZrType(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("dotCount", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetdotCount(vValue.iVal);
			};

			RwAdo->GetFieldValue("NodeName1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(0, vStr);
			};

			RwAdo->GetFieldValue("NodeName2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vStr = (LPCTSTR)(_bstr_t)vValue; //字符型
				vDev->SetNodeName(1, vStr);
			};

			RwAdo->GetFieldValue("NodeID1", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(0, vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("NodeID2", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetNodeID(1, vValue.iVal);//整型
			};

			RwAdo->GetFieldValue("Zr", vValue);

			if (vValue.vt != VT_NULL)
			{
				vDev->SetZr(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zrmax", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZrMax(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zrmin", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZrMin(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Z_L", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZ_L(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Z_C", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZ_C(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx_L", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx_L(vValue.dblVal); //双精度
			};

			RwAdo->GetFieldValue("Zx_C", vValue);
			if (vValue.vt != VT_NULL)
			{
				vDev->SetZx_C(vValue.dblVal); //双精度
			};

			RwAdo->Record_MoveNext();

			cout << "   --" << vDev->GetDeviceName() << endl;


}//void
/////////////

void CmcRw::doSave_AcSys()
{
	CDeviceTBL * vTBL;
	CmcDevAcSys * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_AcSys;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;

		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_AcSys);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{
		
			vDev = dynamic_cast<CmcDevAcSys *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			//
			vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
			RwAdo->SetFieldValue("DeviceID", vValue);

			vValue = _variant_t(vDev->GetDeviceName().c_str());
			RwAdo->SetFieldValue("DeviceName", vValue);

			vValue = _variant_t(vDev->GetDeviceType());
			RwAdo->SetFieldValue("DeviceType", vValue);

			vValue = _variant_t(vDev->GetStationName().c_str());//文本型
			RwAdo->SetFieldValue("StationName", vValue);

			vValue = _variant_t(vDev->GetNodeID(0));
			RwAdo->SetFieldValue("NodeID", vValue);

			vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
			RwAdo->SetFieldValue("NodeName", vValue);

			vValue = _variant_t(vDev->GetPac());
			RwAdo->SetFieldValue("Pac", vValue);


			vValue = _variant_t(vDev->GetPacN()); //
			RwAdo->SetFieldValue("PacN", vValue); //

			vValue = _variant_t(vDev->GetQac()); //
			RwAdo->SetFieldValue("Qac", vValue); //

			vValue = _variant_t(vDev->GetQacN()); //
			RwAdo->SetFieldValue("QacN", vValue); //

			vValue = _variant_t(vDev->GetSac()); //
			RwAdo->SetFieldValue("Sac", vValue); //

			vValue = _variant_t(vDev->GetSacN()); //
			RwAdo->SetFieldValue("SacN", vValue); //

			vValue = _variant_t(vDev->GetUac()); //
			RwAdo->SetFieldValue("Uac", vValue); //

			vValue = _variant_t(vDev->GetUacN()); //
			RwAdo->SetFieldValue("UacN", vValue); //

			vValue = _variant_t(vDev->GetQinMax()); //
			RwAdo->SetFieldValue("QinMax", vValue); //

			vValue = _variant_t(vDev->GetQoutMax()); //
			RwAdo->SetFieldValue("QoutMax", vValue); //

			vValue = _variant_t(vDev->GetUacExMin()); //
			RwAdo->SetFieldValue("UacExMin", vValue); //

			vValue = _variant_t(vDev->GetUacMax()); //
			RwAdo->SetFieldValue("UacMax", vValue); //

			vValue = _variant_t(vDev->GetUacLevel()); //
			RwAdo->SetFieldValue("UacLevel", vValue); //

			vValue = _variant_t(vDev->GetUacMin()); //
			RwAdo->SetFieldValue("UacMin", vValue); //

			vValue = _variant_t(vDev->GetAPhase()); //
			RwAdo->SetFieldValue("APhase", vValue); //

			vValue = _variant_t(vDev->GetZr()); //
			RwAdo->SetFieldValue("Zr", vValue); //

			vValue = _variant_t(vDev->GetZx()); //
			RwAdo->SetFieldValue("Zx", vValue); //

			vValue = _variant_t(vDev->GetdotCount()); //
			RwAdo->SetFieldValue("dotCount", vValue); //

			//
			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_AcFilter()
{
	CDeviceTBL * vTBL;
	CmcDevAcFilter * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_AcF;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;

		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_AcF);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{
			vDev = dynamic_cast<CmcDevAcFilter *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			//
			vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
			RwAdo->SetFieldValue("DeviceID", vValue);

			vValue = _variant_t(vDev->GetDeviceName().c_str());
			RwAdo->SetFieldValue("DeviceName", vValue);

			vValue = _variant_t(vDev->GetDeviceType());
			RwAdo->SetFieldValue("DeviceType", vValue);

			vValue = _variant_t(vDev->GetAcfType());
			RwAdo->SetFieldValue("AcfType", vValue);

			vValue = _variant_t(vDev->GetQacf()); //
			RwAdo->SetFieldValue("Qacf", vValue); //

			vValue = _variant_t(vDev->GetQacfN()); //
			RwAdo->SetFieldValue("QacfN", vValue); //

			vValue = _variant_t(vDev->GetZc()); //
			RwAdo->SetFieldValue("Zc", vValue); //

			vValue = _variant_t(vDev->GetZr()); //
			RwAdo->SetFieldValue("Zr", vValue); //

			vValue = _variant_t(vDev->GetZx()); //
			RwAdo->SetFieldValue("Zx", vValue); //

			vValue = _variant_t(vDev->GetUac()); //
			RwAdo->SetFieldValue("Uac", vValue); //

			vValue = _variant_t(vDev->GetUacN()); //
			RwAdo->SetFieldValue("UacN", vValue); //

			vValue = _variant_t(vDev->GetQac()); //
			RwAdo->SetFieldValue("Qac", vValue); //

			vValue = _variant_t(vDev->GetQacN()); //
			RwAdo->SetFieldValue("QacN", vValue); //

			vValue = _variant_t(vDev->GetdotCount()); //
			RwAdo->SetFieldValue("dotCount", vValue); //

			vValue = _variant_t(vDev->GetStationName().c_str());//文本型
			RwAdo->SetFieldValue("StationName", vValue);

			vValue = _variant_t(vDev->GetNodeID(0));
			RwAdo->SetFieldValue("NodeID", vValue);

			vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
			RwAdo->SetFieldValue("NodeName", vValue);
			//
			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_Xf2()
{
	CDeviceTBL * vTBL;
	CmcDevXf2 * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_Xf2;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;

		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_Xf2);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{

			vDev = dynamic_cast<CmcDevXf2 *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			//
			vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
			RwAdo->SetFieldValue("DeviceID", vValue);

			vValue = _variant_t(vDev->GetDeviceName().c_str());
			RwAdo->SetFieldValue("DeviceName", vValue);

			vValue = _variant_t(vDev->GetDeviceType());
			RwAdo->SetFieldValue("DeviceType", vValue);

			vValue = _variant_t(vDev->GetStationName().c_str());//文本型
			RwAdo->SetFieldValue("StationName", vValue);


			vValue = _variant_t(vDev->GetNodeID(0)); //
			RwAdo->SetFieldValue("NodeID1", vValue); //

			vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
			RwAdo->SetFieldValue("NodeName1", vValue);


			vValue = _variant_t(vDev->GetNodeID(1)); //
			RwAdo->SetFieldValue("NodeID2", vValue); //

			vValue = _variant_t(vDev->GetNodeName(1).c_str());//文本型
			RwAdo->SetFieldValue("NodeName2", vValue);

			vValue = _variant_t(vDev->GetAngleMax()); //
			RwAdo->SetFieldValue("AngleMax", vValue); //

			vValue = _variant_t(vDev->GetAngleMin()); //
			RwAdo->SetFieldValue("AngleMin", vValue); //

			vValue = _variant_t(vDev->GetTapCtrlType()); //
			RwAdo->SetFieldValue("TapCtrlType", vValue); //

			vValue = _variant_t(vDev->GetFixedURef()); //
			RwAdo->SetFieldValue("FixedURef", vValue); //

			vValue = _variant_t(vDev->GetFixedUType()); //
			RwAdo->SetFieldValue("FixedUType", vValue); //

			vValue = _variant_t(vDev->GetSN()); //
			RwAdo->SetFieldValue("SN", vValue); //

			vValue = _variant_t(vDev->GetTap()); //
			RwAdo->SetFieldValue("Tap", vValue); //

			vValue = _variant_t(vDev->GetTapMax()); //
			RwAdo->SetFieldValue("TapMax", vValue); //

			vValue = _variant_t(vDev->GetTapMin()); //
			RwAdo->SetFieldValue("TapMin", vValue); //

			vValue = _variant_t(vDev->GetTapN()); //
			RwAdo->SetFieldValue("TapN", vValue); //

			vValue = _variant_t(vDev->GetTk()); //
			RwAdo->SetFieldValue("Tk", vValue); //

			vValue = _variant_t(vDev->GetTkN()); //
			RwAdo->SetFieldValue("TkN", vValue); //

			vValue = _variant_t(vDev->GetUac()); //
			RwAdo->SetFieldValue("Uac", vValue); //

			vValue = _variant_t(vDev->GetUacN()); //
			RwAdo->SetFieldValue("UacN", vValue); //

			vValue = _variant_t(vDev->GetUv()); //
			RwAdo->SetFieldValue("Uv", vValue); //

			vValue = _variant_t(vDev->GetUvMax()); //
			RwAdo->SetFieldValue("UvMax", vValue); //

			vValue = _variant_t(vDev->GetUvN()); //
			RwAdo->SetFieldValue("UvN", vValue); //

			vValue = _variant_t(vDev->GetUkp()); //
			RwAdo->SetFieldValue("Ukp", vValue); //

			vValue = _variant_t(vDev->GetUrp()); //
			RwAdo->SetFieldValue("Urp", vValue); //

			vValue = _variant_t(vDev->GetZr()); //
			RwAdo->SetFieldValue("Zr", vValue); //

			vValue = _variant_t(vDev->GetZx()); //
			RwAdo->SetFieldValue("Zx", vValue); //

			vValue = _variant_t(vDev->GetTapSetup()); //
			RwAdo->SetFieldValue("TapSetup", vValue); //

			vValue = _variant_t(vDev->GetL_DeltaA()); //
			RwAdo->SetFieldValue("L_DeltaA", vValue); //

			vValue = _variant_t(vDev->GetL_DeltaB()); //
			RwAdo->SetFieldValue("L_DeltaB", vValue); //

			vValue = _variant_t(vDev->GetL_DeltaC()); //
			RwAdo->SetFieldValue("L_DeltaC", vValue); //

			vValue = _variant_t(vDev->GetL_DeltaPMax()); //
			RwAdo->SetFieldValue("L_DeltaPMax", vValue); //

			vValue = _variant_t(vDev->GetL_DeltaType()); //
			RwAdo->SetFieldValue("L_DeltaType", vValue); //

			vValue = _variant_t(vDev->GetZc()); //
			RwAdo->SetFieldValue("Zc", vValue); //

			vValue = _variant_t(vDev->GetZL()); //
			RwAdo->SetFieldValue("ZL", vValue); //

			vValue = _variant_t(vDev->GetdotCount()); //
			RwAdo->SetFieldValue("dotCount", vValue); //

			
			//
			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_Convertor()
{
	CDeviceTBL * vTBL;
	CmcDevConvertor * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_Convertor;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;
		
		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_Convertor);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{
			vDev = dynamic_cast<CmcDevConvertor *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			//
			vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
			RwAdo->SetFieldValue("DeviceID", vValue);

			vValue = _variant_t(vDev->GetDeviceName().c_str());
			RwAdo->SetFieldValue("DeviceName", vValue);

			vValue = _variant_t(vDev->GetDeviceType());
			RwAdo->SetFieldValue("DeviceType", vValue);

			vValue = _variant_t(vDev->GetAlhpa_gama());
			RwAdo->SetFieldValue("Alhpa_gama", vValue);


			vValue = _variant_t(vDev->GetAlpha_gamaN()); //
			RwAdo->SetFieldValue("Alpha_gamaN", vValue); //

			vValue = _variant_t(vDev->GetAngleMax()); //
			RwAdo->SetFieldValue("AngleMax", vValue); //

			vValue = _variant_t(vDev->GetAngleMin()); //
			RwAdo->SetFieldValue("AngleMin", vValue); //

			vValue = _variant_t(vDev->GetStationType()); //
			RwAdo->SetFieldValue("StationType", vValue); //

			vValue = _variant_t(vDev->GetStationCtrlType()); //
			RwAdo->SetFieldValue("StationCtrlType", vValue); //

			vValue = _variant_t(vDev->GetdrN()); //
			RwAdo->SetFieldValue("drN", vValue); //

			vValue = _variant_t(vDev->GetdxN()); //
			RwAdo->SetFieldValue("dxN", vValue); //

			vValue = _variant_t(vDev->GetLengthToSide()); //
			RwAdo->SetFieldValue("LengthToSide", vValue); //

			vValue = _variant_t(vDev->GetPd()); //
			RwAdo->SetFieldValue("Pd", vValue); //

			vValue = _variant_t(vDev->GetPdN()); //
			RwAdo->SetFieldValue("PdN", vValue); //

			vValue = _variant_t(vDev->GetUd()); //
			RwAdo->SetFieldValue("Ud", vValue); //

			vValue = _variant_t(vDev->GetUdN()); //
			RwAdo->SetFieldValue("UdN", vValue); //

			vValue = _variant_t(vDev->GetUT()); //
			RwAdo->SetFieldValue("UT", vValue); //

			vValue = _variant_t(vDev->GetValvor12Count()); //
			RwAdo->SetFieldValue("Valvor12Count", vValue); //

			vValue = _variant_t(vDev->GetQmin()); //
			RwAdo->SetFieldValue("Qmin", vValue); //

			vValue = _variant_t(vDev->GetAngle_DeltaType()); //
			RwAdo->SetFieldValue("Angle_DeltaType", vValue); //

			vValue = _variant_t(vDev->GetAngleDeltaPMax()); //
			RwAdo->SetFieldValue("AngleDeltaPMax", vValue); //

			//vValue = _variant_t(vDev->GetAngleDeltaVect()); //
			//RwAdo->SetFieldValue("AngleDeltaVect", vValue); //

			vValue = _variant_t(vDev->GetIsGround()); //
			RwAdo->SetFieldValue("IsGround", vValue); //

			vValue = _variant_t(vDev->GetId()); //
			RwAdo->SetFieldValue("Id", vValue); //

			vValue = _variant_t(vDev->GetAngleDeltaPMax()); //
			RwAdo->SetFieldValue("AngleDeltaPMax", vValue); //

			vValue = _variant_t(vDev->GetdotCount()); //
			RwAdo->SetFieldValue("dotCount", vValue); //


			//vValue = _variant_t(vDev->GetStationName().c_str());//文本型
			//RwAdo->SetFieldValue("StationName", vValue);

			vValue = _variant_t(vDev->GetNodeID(0)); //
			RwAdo->SetFieldValue("NodeID1", vValue); //

			vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
			RwAdo->SetFieldValue("NodeName1", vValue);

			vValue = _variant_t(vDev->GetNodeID(1)); //
			RwAdo->SetFieldValue("NodeID2", vValue); //

			vValue = _variant_t(vDev->GetNodeName(1).c_str());//文本型
			RwAdo->SetFieldValue("NodeName2", vValue);
			//
			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_DcLine()
{
	CDeviceTBL * vTBL;
	CmcDevDcLine * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_DcLine;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;

		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_DcLine);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{

			vDev = dynamic_cast<CmcDevDcLine *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			doSave_Branch(vDev);

												  //
			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_MetalLine()
{
	CDeviceTBL * vTBL;
	CmcDevMetalLine * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_MetalLine;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;

		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_MetalLine);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{

			vDev = dynamic_cast<CmcDevMetalLine *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			doSave_Branch(vDev);

												  //
			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_GroundLine()
{
	CDeviceTBL * vTBL;
	CmcDevGroundLine * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_GroundLine;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;

		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_GroundLine);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{

			vDev = dynamic_cast<CmcDevGroundLine *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			//
			vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
			RwAdo->SetFieldValue("DeviceID", vValue);

			vValue = _variant_t(vDev->GetDeviceName().c_str());
			RwAdo->SetFieldValue("DeviceName", vValue);

			vValue = _variant_t(vDev->GetDeviceType());
			RwAdo->SetFieldValue("DeviceType", vValue);

			vValue = _variant_t(vDev->GetZr()); //
			RwAdo->SetFieldValue("Zr", vValue); //

			vValue = _variant_t(vDev->GetStationName().c_str());//文本型
			RwAdo->SetFieldValue("StationName", vValue);

			vValue = _variant_t(vDev->GetdotCount()); //
			RwAdo->SetFieldValue("dotCount", vValue); //

			vValue = _variant_t(vDev->GetNodeID(0));
			RwAdo->SetFieldValue("NodeID1", vValue);

			vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
			RwAdo->SetFieldValue("NodeName1", vValue);


			vValue = _variant_t(vDev->GetZr()); //
			RwAdo->SetFieldValue("Zr", vValue); //

			vValue = _variant_t(vDev->GetZ_L()); //
			RwAdo->SetFieldValue("Z_L", vValue); //

			vValue = _variant_t(vDev->GetZ_C()); //
			RwAdo->SetFieldValue("Z_C", vValue); //

			vValue = _variant_t(vDev->GetZx_L()); //
			RwAdo->SetFieldValue("Zx_L", vValue); //

			vValue = _variant_t(vDev->GetZx_C()); //
			RwAdo->SetFieldValue("Zx_C", vValue); //

			

			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_Ground()
{
	CDeviceTBL * vTBL;
	CmcDevGround * vDev;

	string vtblName, vSQL, vStr;
	_variant_t vValue;

	bool vOk = S_FALSE;
	int i;

	vtblName = CHvdcParams::tbl_Ground;

	vSQL = "delete * from " + vtblName;
	vOk = RwAdo->ExecSQL(vSQL);


	vSQL = "select * from " + vtblName;
	if (vOk)
		vOk = vOk && (RwAdo->OpenSQL(vSQL));

	if (vOk)
	{
		cout << "Save---" + vtblName + "---" << endl;

		vTBL = CHvdcVars::pmcHvdcGrid->DeviceTBL(mc_Ground);
		for (i = 0; i<vTBL->GetItemCount(); i++)
		{

			vDev = dynamic_cast<CmcDevGround *>(vTBL->Device(i));
			//
			RwAdo->Record_AddNew();

			//
			vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
			RwAdo->SetFieldValue("DeviceID", vValue);

			vValue = _variant_t(vDev->GetDeviceName().c_str());
			RwAdo->SetFieldValue("DeviceName", vValue);

			vValue = _variant_t(vDev->GetDeviceType());
			RwAdo->SetFieldValue("DeviceType", vValue);

			vValue = _variant_t(vDev->GetZr()); //
			RwAdo->SetFieldValue("Zr", vValue); //

			vValue = _variant_t(vDev->GetStationName().c_str());//文本型
			RwAdo->SetFieldValue("StationName", vValue);

			vValue = _variant_t(vDev->GetdotCount()); //
			RwAdo->SetFieldValue("dotCount", vValue); //

			vValue = _variant_t(vDev->GetNodeID(0));
			RwAdo->SetFieldValue("NodeID", vValue);

			vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
			RwAdo->SetFieldValue("NodeName", vValue);

			vValue = _variant_t(vDev->GetZ_L()); //
			RwAdo->SetFieldValue("Z_L", vValue); //

			vValue = _variant_t(vDev->GetZ_C()); //
			RwAdo->SetFieldValue("Z_C", vValue); //

			vValue = _variant_t(vDev->GetZx_L()); //
			RwAdo->SetFieldValue("Zx_L", vValue); //

			vValue = _variant_t(vDev->GetZx_C()); //
			RwAdo->SetFieldValue("Zx_C", vValue); //

												  //
			RwAdo->Record_Update();
			//
		}//for

	}//if

	RwAdo->CloseTBL();
}

void CmcRw::doSave_Branch(CmcDevDcLine * vDev)
{	
	string vStr;
	_variant_t vValue;


			//
			RwAdo->Record_AddNew();

			//
			vValue = _variant_t(vDev->GetDeviceID().c_str());//文本型
			RwAdo->SetFieldValue("DeviceID", vValue);

			vValue = _variant_t(vDev->GetDeviceName().c_str());
			RwAdo->SetFieldValue("DeviceName", vValue);

			vValue = _variant_t(vDev->GetDeviceType());
			RwAdo->SetFieldValue("DeviceType", vValue);

			vValue = _variant_t(vDev->GetStationName().c_str());//文本型
			RwAdo->SetFieldValue("StationName", vValue);

			vValue = _variant_t(vDev->GetZrMax()); //
			RwAdo->SetFieldValue("ZrMax", vValue); //

			vValue = _variant_t(vDev->GetZrMin()); //
			RwAdo->SetFieldValue("ZrMin", vValue); //

			vValue = _variant_t(vDev->GetZrType()); //
			RwAdo->SetFieldValue("ZrType", vValue); //

			vValue = _variant_t(vDev->GetStationName1().c_str());//文本型
			RwAdo->SetFieldValue("StationName1", vValue);

			vValue = _variant_t(vDev->GetStationName2().c_str());//文本型
			RwAdo->SetFieldValue("StationName2", vValue);

			vValue = _variant_t(vDev->GetdotCount()); //
			RwAdo->SetFieldValue("dotCount", vValue); //

			vValue = _variant_t(vDev->GetNodeID(0));
			RwAdo->SetFieldValue("NodeID1", vValue);

			vValue = _variant_t(vDev->GetNodeName(0).c_str());//文本型
			RwAdo->SetFieldValue("NodeName1", vValue);

			vValue = _variant_t(vDev->GetNodeID(1));
			RwAdo->SetFieldValue("NodeID2", vValue);

			vValue = _variant_t(vDev->GetNodeName(1).c_str());//文本型
			RwAdo->SetFieldValue("NodeName2", vValue);


			vValue = _variant_t(vDev->GetZr()); //
			RwAdo->SetFieldValue("Zr", vValue); //

			vValue = _variant_t(vDev->GetZ_L()); //
			RwAdo->SetFieldValue("Z_L", vValue); //

			vValue = _variant_t(vDev->GetZ_C()); //
			RwAdo->SetFieldValue("Z_C", vValue); //

			vValue = _variant_t(vDev->GetZx_L()); //
			RwAdo->SetFieldValue("Zx_L", vValue); //

			vValue = _variant_t(vDev->GetZx_C()); //
			RwAdo->SetFieldValue("Zx_C", vValue); //

												  //
}