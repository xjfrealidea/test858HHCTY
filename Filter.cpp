#include "qmath.h"
#include "Filter.h"

CFilter::CFilter(SFilterArg* xFilterArg)
{
	BandTemp   = 0;
	bcCount    = 0;
	pFilterArg = xFilterArg;
    BlackWin   =(double *)calloc(pFilterArg->BLKM_WID,sizeof(double));
    MidArr     = (double *)calloc(pFilterArg->MID_STEP,sizeof(double));
	for (int i=0;i<pFilterArg->BLKM_WID;i++)
	{
       BlackWin[i] = 0.42-0.5*qCos(2*PI*i/(pFilterArg->BLKM_WID-1))+0.08*qCos(4*PI*i/(pFilterArg->BLKM_WID-1)); // 窗口函数;
	}
}

CFilter::~CFilter(void)
{
	if(BlackWin != NULL)
		free(BlackWin);
}

double CFilter::RectWindow(DataCache *xdata) // 加窗平滑
{
	double temp1 = 0;
	int    pos;
	pos   = xdata->GetFrist();
	for(int i=0; i<pFilterArg->BLKM_WID; i++)
	{
        temp1 = temp1 + xdata->GetData(pos) * BlackWin[i];
		pos   = xdata->GetNext(pos);
	}
    return temp1/pFilterArg->BLKM_AMP;
}

double CFilter::MidDfilter(DataCache *xdata)  // 中值滤波
{
	double temp1 = 0;
	int    pos   = xdata->GetFrist();
	for(int i=0; i<pFilterArg->MID_STEP; i++)
	{
        MidArr[i]= xdata->GetData(pos);
		pos   = xdata->GetNext(pos);
	}
	pos = pFilterArg->MID_STEP;
	for(int t=0; t < (pFilterArg->MID_STEP-1); t++)        //冒泡法排序
	{
		for(int j = 0; j < (pos - 1); j++)
		{
			if(MidArr[j] > MidArr[j+1])
			{
				temp1       = MidArr[j];
				MidArr[j]   = MidArr[j+1];
				MidArr[j+1] = temp1;
			}
		}
		pos--;
	}
	return MidArr[(pFilterArg->MID_STEP-1)/2];
}

double CFilter::BandPassFilter(DataCache *xdata) // 带通滤波
{
	int tmp1,tmp2,tmp3,tmp4,k2,N,pos;

	k2   = pFilterArg->COMB_PAR + 1;
	N    = pFilterArg->COMB_N;
	pos  = xdata->GetLast();
	tmp1 = pos - k2;
	if (tmp1 < 0)
	{
		tmp1 = tmp1 + N;
	}
	tmp2 = pos - 2 * k2;
	if (tmp2 < 0)
	{
		tmp2 = tmp2 + N;
	}
	tmp3 = pos - 3 * k2;
	if (tmp3 < 0)
	{
		tmp3 = tmp3 + N;
	}
	tmp4 = pos-4 * k2;
	if (tmp4 < 0)
	{
		tmp4 = tmp4 + N;
	}	
    return (xdata->GetData(pos) - 4 * xdata->GetData(tmp1) + 6 * xdata->GetData(tmp2)
            - 4 * xdata->GetData(tmp3) + xdata->GetData(tmp4)) / pFilterArg->COMB_AMP;
}
