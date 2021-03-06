#include "fileply.h"
#include <QDebug>
Fileply::Fileply()
{

}

void Fileply::save_points_cloud(std::vector<cv::Point3f> points_cloud)
{
    QString lenPoint = QString::number (points_cloud.size());
    header = "ply\n";
    header += "format binary_little_endian 1.0\n";
    header += "comment Generated by Horus software\n";
    header += "element vertex ";
    header += lenPoint;
    header += "\n";
    header += "property float x\n";
    header += "property float y\n";
    header += "property float z\n";
    header += "property uchar red\n";
    header += "property uchar green\n";
    header += "property uchar blue\n";
    header += "element face 0\n";
    header += "property list uchar int vertex_indices\n";
    header += "end_header\n";
    for(cv::Point3f it:points_cloud){
        header += QString::number(it.x) + " " + QString::number(it.y) + " " + QString::number(it.z) + "\n";
    }
}

void Fileply::run()
{
    for(int i=0;i<1000000;i++){
        qDebug() << i;
    }
}
