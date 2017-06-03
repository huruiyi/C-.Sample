#pragma once
/*
请编写电视机类，
Property
开机状态，关机状态，
Method

有音量，
有频道，
提供音量操作的方法，
频道操作的方法。
由于电视机只能逐一调整频道，不能指定频道，

增加遥控类，
遥控类除了拥有电视机已有的功能，
再增加根据输入调台功能。
 **//**/
enum TelevisionSatus
{
    On = 0,
    Off = 1
};
enum TelevisionVol
{
    MinVol = 0,
    MaxVol = 100
};

enum TelevisionChanel
{
    MinChanel = 1,
    MaxChanel = 255
};
class Television
{
public:
    TelevisionSatus Status;
    int Vol = MinVol;
    int Chanel = MinChanel;
    void AddVol()
    {
        if (this->Vol >= MaxVol)
        {
            return;
        }
        this->Vol++;
    }

    void SubVol()
    {
        if (this->Vol << MinVol)
        {
            return;
        }
        this->Vol--;
    }
    void PreChanel()
    {
        if (this->Chanel == MinChanel)
        {
            this->Chanel = MaxChanel;
            return;
        }
        this->Chanel--;
    }
    void NextChanel()
    {
        if (this->Chanel = MaxChanel)
        {
            this->Chanel = MinChanel;
            return;
        }
        this->Chanel++;
    }
private:
};
