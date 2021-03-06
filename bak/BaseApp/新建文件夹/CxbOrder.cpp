///////////////////////////////////////////////////////////
//  CxbOrder.cpp
//  Implementation of the Class CxbOrder
//  Created on:      05-4月-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbOrder.h"
#include "gbHead_Def.h"


void CxbOrder::Init()
{

	StaCount = 0;
	
	//
	nValNum = 2;
	
	Flag_Ground = "1111";  //单极大地/金属回线/双极/双极并联
	Flag_Ud = "111";  //全压/80%/70%
	Flag_Rd = "11";    //高阻/低阻
	Flag_Uac = "1111";  //最大/额定/最小/极小
	
	IsUdCustom = false;//直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
	IsUacSwap = true;// 是否交流电压交叉
	IsUdToGround = false;//直流电压对地或对中性线
					 //string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
	PdStartPer = 10;//起始功率水平
	PdIncrePer = 5;//功率水平增量
	PdSize = 1;//功率水平数
}


/**
 * 南方电网主回路及谐波计算软件* 改动对象:  CreateCaseID 改动者:    崔康生 改动类型:  新增 改动内容:  1.
 * 根据Order里保存的单工况生成工况代码 改动时间:  2017/04/13
 */
string CxbOrder::CreateCaseID() {

	//char buff[1];

	string CaseID = "";

	//阀组数:
	switch (nValNum)
	{
	case 1:
		CaseID.append("S");
		break;
	case 2:
		CaseID.append("D");
		break;
	}

	//接地:单极大地，单极金属，双极，双极并联
	switch (GroundType)
	{
	case mc_Ground20:
		CaseID.append("B");
		break;
	case mc_Ground11:
		CaseID.append("M");
		break;
	case mc_Ground10:
		CaseID.append("G");
		break;
	case mc_Ground21:
		CaseID.append("P");
		break;
	default:
		break;
	}

	//Ud:全压,80%,70%
	switch (UdLevel)
	{
	case Ud_Full:
		CaseID.append("F");
		break;
	case Ud_Per80:
		CaseID.append("R");
		break;
	case Ud_Per70:
		CaseID.append("S");
		break;

	case Ud_Custom:
		CaseID.append("C");
		break;

	default:
		break;
	}

	//Rd:高阻、低阻
	switch (RdLevel)
	{
	case Rd_High:
		CaseID.append("H");
		break;
	case Rd_Low:
		CaseID.append("L");
		break;
	default:
		break;
	}

	//交流Uac
	if (StaCount > 0)
	{	
		for (int i = 0; i < UacLevel.size(); i++)
			CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));
	}//if
	//
	return CaseID;
}