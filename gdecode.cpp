#include "gdecode.h"
#define DATACODECHAR1  0x00    //2字节编码
#define DATACODECHAR2  0x04    //2.5字节编码
#define DATACODECHAR3  0x08    //2.5字节编码
#define DATACODECHAR4  0x0C    //2.5字节编码
//0				1			2			3			4			5			6			7			8			9			10
//0.0005		0.001		0.002		0.004		0.008		0.016		0.032		0.064		0.128		0.256		0.512


//				11			12			13			14			15			16			17			18			19			20
//				1.024		2.048		4.096		8.192		16.384		32.768		65.536		131.072		262.144		524.288

//				21			22			23			24			25			26			27			28
//				1048.576	2097.152	4194.304	8388.608	16777.216	33554.432	67108.864	134217.728



double mtable[] = {0.0005,0.001,0.002,0.004,0.008,0.016,0.032,0.064,0.128,0.256,0.512,1.024,2.048,4.096,8.192,16.384,32.768,65.536,131.072,262.144,524.288
,1048.576,2097.152,4194.304,8388.608,16777.216,33554.432,67108.864,134217.728};


GDeCode::GDeCode(QObject *parent) :
    QObject(parent)
{
}
int GDeCode::hextodec(char c)
{
    if(c >= 'a')
        return c - 87;
    if(c >= 'A')
        return c - 55;
    else if (c >= '0')
        return c - 48;
    else if (c == ' ')
        return 0;
    else
        return -1;
}
double GDeCode::funDeCode(char *code, unsigned char *len)
{
    double ret = 0;
    int codeTmp = 0;
    int codeID;
    int i;
    codeID = codeTmp = hextodec(code[0]);
    if((codeID & 0x0C) == DATACODECHAR1)
    {
        codeTmp <<= 4;
        codeTmp |= hextodec(code[1]);
        codeTmp <<= 4;
        codeTmp |= hextodec(code[2]);
        codeTmp <<= 4;
        codeTmp |= hextodec(code[3]);
        for( i = 0; i < 13; i++)
        {
            if((codeTmp & 0x0001) == 1)
                ret += mtable[i];
            codeTmp >>= 1;
        }
        *len = 4;
    }
    else
    {
        codeTmp <<= 4;
        codeTmp |= hextodec(code[1]);
        codeTmp <<= 4;
        codeTmp |= hextodec(code[2]);
        codeTmp <<= 4;
        codeTmp |= hextodec(code[3]);
        codeTmp <<= 4;
        codeTmp |= hextodec(code[4]);
        if((codeID & 0x0C) == DATACODECHAR2)
        {
            for( i = 0; i < 17; i++)
            {
                if((codeTmp & 0x0001) == 1)
                    ret += mtable[i];
                codeTmp >>= 1;
            }
        }
        else if((codeID & 0x0C) == DATACODECHAR3)
        {
            for( i = 4; i < 21; i++)
            {
                if((codeTmp & 0x0001) == 1)
                    ret += mtable[i];
                codeTmp >>= 1;
            }
        }
        else if((codeID & 0x0C) == DATACODECHAR4)
        {
            for( i = 11; i < 28; i++)
            {
                if((codeTmp & 0x0001) == 1)
                    ret += mtable[i];
                codeTmp >>= 1;
            }
        }
        *len = 5;
    }
    if((codeTmp & 0x0001) == 1)//符号位负
        ret = -ret;
    return ret;
}
