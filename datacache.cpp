#include "datacache.h"
#include "plot.h"
#include <QDebug>

DataCache::DataCache(QObject *parent, int x_len) :
    QObject(parent)
{
    _pL    = -1;
    _pF    = -1;
    _len   = x_len;
    _count = 0;

    _datas = new Data[x_len];
}

DataCache::~DataCache(void)
{
    if(_datas != NULL)
    {
        delete[] _datas;
        _datas = NULL;
    }
}

void DataCache::attach(Plot *plot)
{
    if(!_plots.contains(plot))
    {
        _plots.append(plot);
        QObject::connect(this, SIGNAL(dataChanged()), plot, SLOT(onDataChanged()));
    }
}

void DataCache::disattach(Plot *plot)
{
    if (!_plots.isEmpty())
    {
        if(_plots.contains(plot))
        {
            _plots.removeAll(plot);
            QObject::disconnect(this, SIGNAL(dataChanged()), plot, SLOT(onDataChanged()));

        }
    }
}

void DataCache::AddData(double key, double value, short flag) //添加数据
{
    if(!IsFull())
        _count++;

    // 最后一个有效数据位置
    if(_len == 0)
    {
        _pL = 0;
    }
    else
        _pL = (_pL+1)%_len;

    // 第一个有效数据位置
    if(!IsFull())
    {
        _pF = 0;
    }
    else
    {
        _pF = (_pF+1)%_len;
    }

    _datas[_pL].key = key;
    _datas[_pL].value = value;
    _datas[_pL].flag = flag;

    if(_plots.size() > 0)
        emit dataChanged();
}
double DataCache::GetData(int index)
{
    return _datas[index].value;
}

int  DataCache::GetFrist()            //循环数组头位置
{
    return _pF;
}

int  DataCache::GetNext(int pos)      //计算pos下一个点的位置;
{
    int tmppos;
    if(_count == 0)  //循环数组为空，返回 -1
        return -1;
    else if((pos > _count) || (pos < 0)) // pos不在有效数据范围内
        return -1;
    tmppos = (pos + 1) % _len;
    if(_pF < _pL)
    {
        if((tmppos > _pF) && (tmppos <= _pL))
            return tmppos;
        else
            return -1;
    }
    else
    {
        if((tmppos > _pF) || (tmppos <= _pL))
            return tmppos;
        else
            return -1;
    }
}

int  DataCache::GetNext(int pos, int n)      //计算pos下n个点的位置;
{
    int tmppos;
    if(_count == 0)  //循环数组为空，返回 -1
        return -1;
    else if((pos > _count) || (pos < 0) ||(n > _count) || (n < 0))// pos不在有效数据范围内
        return -1;
    tmppos = (pos + n) % _len;
    if(((pos + n) >= _count) && (tmppos >= _pF))    //超出有效数据范围
        return -1;
    else
    {
        return tmppos;
    }
}

int  DataCache::GetLast()            //循环数组尾位置
{
    return _pL;
}

int  DataCache::GetPre(int pos)       //计算pos上一个点的位置;
{
    if(pos <= 0)
        return _len-1;
    else
        return pos-1;
}

int  DataCache::GetPre(int pos, int n)       //计算pos上n个点的位置;
{
    int   tag;
    tag = pos;
    if(tag == GetFrist())
        return tag;
    else
    {
        for(int i = 0; i < n; i++)
        {
            tag = GetPre(tag);
            if(tag == GetFrist())
                break;
        }
    }
    return tag;
}

void DataCache::dataReset(int x_len)
{
    _pL    = -1;
    _pF    = -1;
    _len   = x_len;
    _count = 0;

    if (!_datas)
    {
        delete[] _datas;
        _datas = NULL;
        _datas = new Data[x_len];
    }
}

int  DataCache::GetCount()
{
    return _count;
}

bool DataCache::IsFull()
{
    return ((_pF==0&&_pL==_len-1) || (_pF>_pL));
}

bool DataCache::isEmpty()
{
    return (_pF==-1 && _pL==-1);
}

DataCache::iterator DataCache::first()
{
    return iterator(_pF, this);
}

DataCache::iterator DataCache::last()
{
    return iterator(_pL, this);
}
