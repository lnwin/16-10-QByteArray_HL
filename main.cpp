#include <QCoreApplication>
//#include <eigen3/Eigen/Core>
#include <QVector>
#include <QDataStream>
#include <iostream>
#include <QDebug>
using namespace std;
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);


    qDebug()<<"PCLength";
   QVector<QVector<double>> mvPCpointclouds;
    QVector<double>a1 (6,1);
    QVector<double>a2 (6,2);
    QVector<double>a3 (6,3);
    QVector<double>a4 (6,4);
    QVector<double>a5 (6,5);
    QVector<double>a6 (6,6);
    QVector<double>a7 (6,7);
    QVector<double>a8 (6,8);

    mvPCpointclouds.push_back(a1);
    mvPCpointclouds.push_back(a2);
    mvPCpointclouds.push_back(a3);
    mvPCpointclouds.push_back(a4);
    mvPCpointclouds.push_back(a5);
    mvPCpointclouds.push_back(a6);
    mvPCpointclouds.push_back(a7);
    mvPCpointclouds.push_back(a8);
    int PCLength=mvPCpointclouds.size();
    cout<<"PCLength=="<<PCLength<<endl;
    bool FIRST=true;
    int UnPackCout=0;
    int BagSize=333;
    int i4PackBag;
    QByteArray PCBag;
    QDataStream stream(&PCBag, QIODevice::WriteOnly);

    int frequencypoint = 2001;
    unsigned char H8 = frequencypoint >> 8;
    unsigned char L8 = (frequencypoint <<8)>>8;
    PCBag.append(H8);
    PCBag.append(L8);
    QByteArray waveDataC1;
    waveDataC1[0]= PCBag.at(0);
    waveDataC1[1]= PCBag.at(1);
    int C1=waveDataC1.toHex().toInt(0,16);
    qDebug()<<C1;


    return a.exec();
}
