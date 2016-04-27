#include<iostream>
#include<stdint.h>
#include<stdio.h>
using namespace std;

class base
{
    public:
        int8_t getChannelNum();
        void printChannel();
        virtual void updateChannel() {return;}

    protected:
        int8_t channelNum;
};

class derive : public base
{
    public:
        void updateChannel();
};

int8_t base::getChannelNum()
{
    return channelNum;
}

void base::printChannel()
{
    cout << "The channelNum is " << channelNum << endl;
}

void derive::updateChannel()
{
    channelNum = 3;
}

int main()
{
    class base *ptr = new derive;
    ptr->updateChannel();
    ptr->channelNum = 10;
    int tmpVar = ptr->getChannelNum();
    printf("the channelNum is %d \n", tmpVar);
//    ptr->printChannel();
}

