
#pragma once

//#include "CMath.h"

class CPower_YU_I
{
public:
	virtual ~CPower_YU_I();

	virtual void Init();
	virtual void Clear();
	virtual void Release();

public:
	double* Ur_Vect;
	double* Um_Vect;

	double* Ir_Vect;
	double* Im_Vect;

	double* Yg_Matrix;
	double* Yb_Matrix;


	
	virtual int GetYdim() { return Ydim; }; 

	virtual void InitMatrix(int vN);

	virtual void UpdateI(int iNode, double vIr, double vIm);
	virtual void UpdateI(int iNode, int jNode,double vIr, double vIm);
	
	virtual void UpdateY0(int iNode, double vYg, double vYb);
	virtual void UpdateY(int iNode, int jNode, double vYg, double vYb);

	virtual void Solve();

protected:
	int Ydim;

	virtual void doUpdateYg0(int iNode, double vY);
	virtual void doUpdateYb0(int iNode, double vY);

	virtual void doUpdateYg(int iNode, int jNode, double vY);
	virtual void doUpdateYb(int iNode, int jNode, double vY);

};