#ifndef DATACACHE_H
#define DATACACHE_H

#include <QObject>
#include <QList>
class Plot;
class datacache_iterator;

#define TIME_LEN 13

struct Data
{
   double key;
   double value;
   short flag;
};

class DataCache : public QObject
{
    Q_OBJECT
public:
    friend class datacache_iterator;
    typedef datacache_iterator iterator;

    explicit DataCache(QObject *parent, int x_len);
    ~DataCache();

    void attach(Plot *plot);
    void disattach(Plot *plot);

    void AddData(double key, double value, short flag = 0x00);  // 添加数据
    double GetData(int index);
    iterator first();
    iterator last();

signals:
    void dataChanged();

public:
    int  GetCount();   // 返回循环数组有效数据的个数
    bool IsFull();
    bool isEmpty();
    int  GetFrist();                // 循环数组头位置
    int  GetNext(int pos);          // 计算pos下一个点的位置;
    int  GetNext(int pos, int n);   // 计算pos下n个点的位置
    int  GetLast();                 // 循环数组尾位置
    int  GetPre(int pos);           // 计算pos上一个点的位置;
    int  GetPre(int pos, int n);    // 计算pos上n个点的位置;

    void dataReset(int x_len);

private:
    Data *_datas;   // 数据缓存区;
    int    _pL;     // 最后一个有效数据位置
    int    _pF;     // 最早一个有效数据位置
    int    _len;    // 数据长度
    int    _count;  // 有效数据个数

    QList<Plot*> _plots;
};

class datacache_iterator
{
public:
    datacache_iterator() :_index(-1), _container(NULL) {}
    datacache_iterator(int index, DataCache* container) : _index(index), _container(container) {}

    Data& operator*()
    {
        return _container->_datas[_index];
    }
    friend bool operator==(const datacache_iterator &lhs, const datacache_iterator& rhs)
    {
        return ((lhs._index == rhs._index) && (lhs._container == rhs._container));
    }
    friend bool operator!=(const datacache_iterator &lhs, const datacache_iterator& rhs)
    {
        return !(lhs==rhs);
    }

    datacache_iterator& operator++()
    {
        _index = _container->GetNext(_index);
        return *this;
    }
    datacache_iterator operator++(int)
    {
        datacache_iterator ret(*this);
        _index = _container->GetNext(_index);
        return ret;
    }

    datacache_iterator operator+(int n)
    {
        datacache_iterator ret(*this);
        ret._index = _container->GetNext(ret._index, n);
        return ret;
    }

    datacache_iterator operator-(int n)
    {
        datacache_iterator ret(*this);
        ret._index = _container->GetPre(ret._index, n);
        return ret;
    }
    friend bool  operator> (const datacache_iterator &lhs, int n)
    {
        return lhs._index > n;
    }
    int operator%(int n)
    {
        return _index % n;
    }


    int _index;
private:

    DataCache* _container;
};

#endif // DATACACHE_H
