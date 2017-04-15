///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.cpp
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4��-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDev3pVSrc.h"



//����

/**
* 3P�ĵ�Ч�絼
*/
//double CxbDev3pVSrc::GetYg(){
//
//	return Yg;
//}


/**
* 3P�ĵ�Ч�絼
*/
//void CxbDev3pVSrc::SetYg(double newVal){
//
//	Yg = newVal;
//}


/**
* 3P�ĵ�Ч����
*/
//double CxbDev3pVSrc::GetYb(){
//
//	return Yb;
//}


/**
* 3P�ĵ�Ч����
*/
//void CxbDev3pVSrc::SetYb(double newVal){
//
//	Yb = newVal;
//}

//����
/**
 * ����
 */
void CxbDev3pVSrc::SetL(double newVal) {
	L = newVal;
}
/*
*3P�ĵ�ѹʵ��
*/
double CxbDev3pVSrc::GetUre(int vhOrder) {
	return UhVect[vhOrder] * cos(PhhVect[vhOrder]);
}
/*
*3P�ĵ�ѹ�鲿
*/
double CxbDev3pVSrc::GetUim(int vhOrder) {
	return UhVect[vhOrder] * sin(PhhVect[vhOrder]);
}
/*
*3P�ĵ絼
*/
double CxbDev3pVSrc::GetYg(double vOmega) 
{
	return 0;
}
/*
*3P�ĵ���
*/
double CxbDev3pVSrc::GetYb(double vOmega) 
{
	return -1.0 /( L * vOmega);
}