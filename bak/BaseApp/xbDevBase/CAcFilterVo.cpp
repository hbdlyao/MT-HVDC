///////////////////////////////////////////////////////////
//  CAcFilterVo.cpp
//  Implementation of the Class CAcFilterVo
//  Created on:      04-4��-2017 7:02:53
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CAcFilterVo.h"




/**
 * �����˲������ͣ�����г/˫��г��
 */
int CAcFilterVo::GetAcfType(){

	return AcfType;
}


/**
 * ������ѹ
 */
double CAcFilterVo::GetQac(){

	return Qac;
}


/**
 * �˲����޹�
 */
double CAcFilterVo::GetQacf(){

	return Qacf;
}


/**
 * �˲�����޹�
 */
double CAcFilterVo::GetQacfN(){

	return QacfN;
}


/**
 * �������ѹ
 */
double CAcFilterVo::GetQacN(){

	return QacN;
}


/**
 * ����
 */
double CAcFilterVo::GetZc(){

	return Zc;
}


/**
 * ����
 */
double CAcFilterVo::GetZr(){

	return Zr;
}


/**
 * �翹
 */
double CAcFilterVo::GetZx(){

	return Zx;
}


/**
 * �����˲������ͣ�����г/˫��г��
 */
void CAcFilterVo::SetAcfType(int newVal){

	AcfType = newVal;
}


/**
 * ������ѹ
 */
void CAcFilterVo::SetQac(double newVal){

	Qac = newVal;
}


/**
 * �˲����޹�
 */
void CAcFilterVo::SetQacf(double newVal){

	Qacf = newVal;
}


/**
 * �˲�����޹�
 */
void CAcFilterVo::SetQacfN(double newVal){

	QacfN = newVal;
}


/**
 * �������ѹ
 */
void CAcFilterVo::SetQacN(double newVal){

	QacN = newVal;
}


/**
 * ����
 */
void CAcFilterVo::SetZc(double newVal){

	Zc = newVal;
}


/**
 * ����
 */
void CAcFilterVo::SetZr(double newVal){

	Zr = newVal;
}


/**
 * �翹
 */
void CAcFilterVo::SetZx(double newVal){

	Zx = newVal;
}


double CAcFilterVo::GetUac(){

	return Uac;
}


void CAcFilterVo::SetUac(double newVal){

	Uac = newVal;
}


double CAcFilterVo::GetUacN(){

	return UacN;
}


void CAcFilterVo::SetUacN(double newVal){

	UacN = newVal;
}