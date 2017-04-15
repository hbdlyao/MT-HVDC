///////////////////////////////////////////////////////////
//  CxbProfile.cpp
//  Implementation of the Class CxbProfile
//  Created on:      05-4��-2017 18:22:21
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbProfile.h"

CxbProfile::~CxbProfile()
{
	Release();
}


void CxbProfile::Release()
{
	Clear();

	delete pxbOrder;

}

void CxbProfile::Init()
{
	doInit();

	pxbOrder = new CxbOrder();
	pxbOrder->Init();

}

void CxbProfile::Clear()
{
	doClear();
	pxbOrder->Clear();
}


void CxbProfile::doInit()
{
	//
	Ydim = 0;

	//
	Yg_Matrix = nullptr;
	Yb_Matrix = nullptr;

	Ur_Vect = nullptr;
	Um_Vect = nullptr;

	Ir_Vect = nullptr;
	Im_Vect = nullptr;

	//������
	Ymatrix = nullptr;
	Uvect = nullptr;
	Ivect = nullptr;

}


void CxbProfile::doClear()
{

	//xbNodeMap.clear();

	delete[] Yg_Matrix;
	delete[] Yb_Matrix;

	delete[] Ur_Vect;
	delete[] Um_Vect;

	delete[] Ir_Vect;
	delete[] Im_Vect;

	//������
	delete Ymatrix;
	delete Ivect;
	delete Uvect;
	//
	Yg_Matrix = nullptr;
	Yb_Matrix = nullptr;

	Ur_Vect = nullptr;
	Um_Vect = nullptr;
	Ir_Vect = nullptr;
	Im_Vect = nullptr;

	//������
	Ymatrix = nullptr;
	Ivect	= nullptr;
	Uvect	= nullptr;
}

void CxbProfile::InitMatrix(int vN)
{
	StationNum = vN;
	Ydim = NodeCount;

	Yg_Matrix = new double[Ydim*Ydim];
	Yb_Matrix = new double[Ydim*Ydim];

	//������
	Ur_Vect = new double[Ydim  * StationNum];
	Um_Vect = new double[Ydim * StationNum];
	Ir_Vect = new double[Ydim * StationNum];
	Im_Vect = new double[Ydim * StationNum];


	//������
	Ymatrix = new CMatrix(Ydim);
	Uvect = new CMatrix(Ydim, StationNum);
	Ivect = new CMatrix(Ydim, StationNum);


}


double CxbProfile::Omega()
{
	double vX;

	vX = xbFreq * xbHOrder * 2 * PI;

	return vX;

}



void CxbProfile::UpdateYLine(int * pNode, CMatrix vY)
{//������
	int vN = Ydim;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			Yg_Matrix[pNode[i] * vN + pNode[j]] += vY._mat[i][j].real();
			Yb_Matrix[pNode[i] * vN + pNode[j]] += vY._mat[i][j].image();

			//(*Ymatrix)._mat[pNode[i]][pNode[j]] += vY._mat[i][j];
		}//for j
}

void CxbProfile::UpdateI(int iNode, double vIr, double vIm)
{
	//������
	Ir_Vect[iNode] += vIr;
	Im_Vect[iNode] += vIm;

	//������
	int vStation = iNode / Ydim;
	int vNode = iNode % Ydim;
	(*Ivect)._mat[iNode][vStation] += CComplex(vIr, vIm);
}

void CxbProfile::UpdateI(int iNode, int jNode, double vIr, double vIm)
{
	//������
	Ir_Vect[iNode] += vIr;
	Im_Vect[iNode] += vIm;

	Ir_Vect[jNode] += -vIr;
	Im_Vect[jNode] += -vIm;

	//������
	int vStation = iNode / Ydim;

	int vNode = iNode % Ydim;
	(*Ivect)._mat[vNode][vStation] += CComplex(vIr, vIm);

	vStation = jNode / Ydim;
	vNode = jNode % Ydim;
	(*Ivect)._mat[vNode][vStation] += CComplex(vIr, vIm);

}


void CxbProfile::Solve()
{
	//������
	//ʵ����⣺CPower_YU_I::Solve()
	//�������:��������

	double vYg, vYb;

	for (int i=0;i<Ydim;i++)
		for (int j = 0; j < Ydim; j++)
		{
			vYg = Yg_Matrix[i*Ydim+j];
			vYb = Yb_Matrix[i*Ydim + j];

			(*Ymatrix)._mat[i][j] = CComplex(vYg, vYb);

		}

	//
	if (Ydim!=0 )
		*Uvect = (Ymatrix->inversion()) * (*Ivect);

}