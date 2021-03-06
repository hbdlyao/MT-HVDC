#pragma once


#include "CmcDevTwoDot.h"

/**
 * 主回路换流变压器
 */
class CmcDevXf2 : public CmcDevTwoDot
{

public:
	/**
	 * 变比
	 */
	double GetTk();
	/**
	 * 额定变比
	 */
	double GetTkN();
	/**
	 * 网侧交流电压
	 */
	double GetUac();
	/**
	 * 网侧额定交流电压
	 */
	double GetUacN();
	/**
	 * 短路阻抗百分比
	 */
	double GetUkp();
	/**
	 * 阻性压降百分比
	 */
	double GetUrp();
	/**
	 * 阀侧交流电压
	 */
	double GetUv();
	/**
	 * 阀侧最大交流电压
	 */
	double GetUvMax();
	/**
	 * 阀侧额定交流电压
	 */
	double GetUvN();
	/**
	 * 触发角/关断角最大值
	 */
	void SetAngleMax(double newVal);
	/**
	 * 触发角/关断角最小值
	 */
	void SetAngleMin(double newVal);
	/**
	 * 定电压参考值
	 */
	void SetFixedURef(double newVal);
	/**
	 * 定电压参考类型
	 */
	void SetFixedUType(int newVal);
	/**
	 * 变压器额定容量
	 */
	void SetSN(double newVal);
	/**
	 * 分接头控制类型
	 */
	void SetTapCtrlType(int newVal);
	/**
	 * 分接头最大档位
	 */
	void SetTapMax(int newVal);
	/**
	 * 分接头最小档位
	 */
	void SetTapMin(int newVal);
	/**
	 * 分接头额定档位
	 */
	void SetTapN(int newVal);
	/**
	 * 分解头调整步长
	 */
	void SetTapSetup(double newVal);
	/**
	 * 变比
	 */
	void SetTk(double newVal);
	/**
	 * 额定变比
	 */
	void SetTkN(double newVal);
	/**
	 * 网侧交流电压
	 */
	void SetUac(double newVal);
	/**
	 * 网侧额定交流电压
	 */
	void SetUacN(double newVal);
	/**
	 * 短路阻抗百分比
	 */
	void SetUkp(double newVal);
	/**
	 * 阻性压降百分比
	 */
	void SetUrp(double newVal);
	/**
	 * 阀侧交流电压
	 */
	void SetUv(double newVal);
	/**
	 * 阀侧最大交流电压
	 */
	void SetUvMax(double newVal);
	/**
	 * 阀侧额定交流电压
	 */
	void SetUvN(double newVal);
	/**
	 * 分接头档位
	 */
	void SetTap(int newVal);
	/**
	 * 触发角/关断角最大值
	 */
	double GetAngleMax();
	/**
	 * 触发角/关断角最小值
	 */
	double GetAngleMin();
	/**
	 * 定电压参考值
	 */
	double GetFixedURef();
	/**
	 * 定电压参考类型
	 */
	int GetFixedUType();
	/**
	 * 变压器额定容量
	 */
	double GetSN();
	/**
	 * 分接头档位
	 */
	int GetTap();
	/**
	 * 分接头控制类型
	 */
	int GetTapCtrlType();
	/**
	 * 分接头最大档位
	 */
	int GetTapMax();
	/**
	 * 分接头最小档位
	 */
	int GetTapMin();
	/**
	 * 分接头额定档位
	 */
	int GetTapN();
	/**
	 * 分解头调整步长
	 */
	double GetTapSetup();

protected:
	/**
	 * 触发角/关断角最大值
	 */
	double AngleMax;
	/**
	 * 触发角/关断角最小值
	 */
	double AngleMin;
	/**
	 * 定电压参考值
	 */
	double FixedURef;
	/**
	 * 定电压参考类型
	 */
	int FixedUType;
	/**
	 * 变压器额定容量
	 */
	double SN;
	/**
	 * 分接头档位
	 */
	int Tap;
	/**
	 * 分接头控制类型
	 */
	int TapCtrlType;
	/**
	 * 分接头最大档位
	 */
	int TapMax;
	/**
	 * 分接头最小档位
	 */
	int TapMin;
	/**
	 * 分接头额定档位
	 */
	int TapN;
	/**
	 * 分解头调整步长
	 */
	double TapSetup;
	/**
	 * 变比
	 */
	double Tk;
	/**
	 * 额定变比
	 */
	double TkN;
	/**
	 * 网侧交流电压
	 */
	double Uac;
	/**
	 * 网侧额定交流电压
	 */
	double UacN;
	/**
	 * 短路阻抗百分比
	 */
	double Ukp;
	/**
	 * 阻性压降百分比
	 */
	double Urp;
	/**
	 * 阀侧交流电压
	 */
	double Uv;
	/**
	 * 阀侧最大交流电压
	 */
	double UvMax;
	/**
	 * 阀侧额定交流电压
	 */
	double UvN;

};
