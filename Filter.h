#pragma once
#include "datacache.h"

#define DATA_LEN   800
#define PI 3.1415926
struct SFilterArg
{
	int COMB_PAR;
	int COMB_N;
	int COMB_AMP;
	int COMB_DEILET_AMP;
	int BLKM_WID;
	int MID_STEP;
	double BLKM_AMP;
};


class CFilter
{
public:
	CFilter(SFilterArg *xFilterArg);
	~CFilter(void);

    double RectWindow(DataCache *xdata);    // �Ӵ�ƽ��
    double MidDfilter(DataCache *xdata);    // ��ֵ�˲�
    double BandPassFilter(DataCache *xdata);// ��ͨ�˲�
	double Compensate(double xB, double xX, double xY, double xZ, double *xishu); //��������
protected:
	double       *BlackWin;
	double       *MidArr;

	double       BandTemp;
	double       sigsave[3];

	int          bcCount;

	SFilterArg   *pFilterArg;
};
