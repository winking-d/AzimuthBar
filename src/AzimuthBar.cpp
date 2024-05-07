//
// Created by dyh on 2024/5/6.
//

#include "AzimuthBar.h"
#include <QPainter>

AzimuthBar::AzimuthBar(QWidget *parent) {

}

void AzimuthBar::onChangeAzimuth(int azimuth) {
    m_currentAzimuth = azimuth;
    update();
}

int transformAzimuth(int azimuth) {
    if (azimuth < 0) {
        return azimuth + 360;
    } else if (azimuth >= 360) {
        return azimuth - 360;
    }
    return azimuth;
}

QString convertAzimuthE(int azimuth) {
    switch (azimuth) {
        case 0:
            return "N";
        case 45:
            return "EN";
        case 90:
            return "E";
        case 135:
            return "ES";
        case 180:
            return "S";
        case 225:
            return "WS";
        case 270:
            return "W";
        case 315:
            return "WN";
        default:
            return QString::number(azimuth);
    }
}

QString convertAzimuthC(int azimuth) {
    switch (azimuth) {
        case 0:
            return "北";
        case 45:
            return "东北";
        case 90:
            return "东";
        case 135:
            return "东南";
        case 180:
            return "南";
        case 225:
            return "西南";
        case 270:
            return "西";
        case 315:
            return "西北";
        default:
            return QString::number(azimuth);
    }
}

void AzimuthBar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    // 01.绘制三角形
    //  a.初始化画笔
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(32, 32, 32));
    //  b.计算中心点
    int centerX = width() / 2;
    QPolygonF polygon;
    polygon << QPointF(centerX - 12, 0);
    polygon << QPointF(centerX + 12, 0);
    polygon << QPointF(centerX, 20);
    //  c.绘制
    painter.drawPolygon(polygon);
    // 02.绘制当前方位
    painter.setPen(QColor(32, 32, 32));
    QFont font;
    font.setPointSize(10);
    painter.setFont(font);

    QRectF rect(centerX - 36, 50, 72, 30); // 设置绘制文字的矩形区域，根据需要调整大小
    painter.drawText(rect, Qt::AlignCenter, convertAzimuthC(m_currentAzimuth));
    // 03.绘制左侧方位
    QPen pen(QColor(32, 32, 32)); // 创建一个画笔对象，并设置颜色为黑色
    pen.setWidth(1); // 设置线宽为1
    painter.setPen(pen); // 将画笔设置给QPainter对象

    // 计算最左侧方位角
    int slidAzimuth = transformAzimuth(m_currentAzimuth - centerX / 3);
    int slidX = 0;
    while (slidAzimuth % 15) {
        slidAzimuth++;
        slidX += 3;
    }
    while (slidX < width()) {
        bool isSpecial = slidAzimuth % 45 == 0;
        // 绘制标记
        if (isSpecial) {
            auto pen_s = painter.pen();
            pen_s.setWidth(3);
            painter.setPen(pen_s);

            painter.drawLine(slidX, 24, slidX, 48);
        } else {
            auto pen_s = painter.pen();
            pen_s.setWidth(1);
            painter.setPen(pen_s);
            painter.drawLine(slidX, 28, slidX, 44);
        }
        // 绘制坐标值
        int offset = slidX - centerX;
        if (offset > 35 || offset < -35) {
            auto pen_s = painter.pen();
            pen_s.setWidth(1);
            painter.setPen(pen_s);
            if (isSpecial)
                font.setPointSize(8);
            else
                font.setPointSize(6);
            painter.setFont(font);

            QRectF tRect(slidX - 36, 50, 72, 24); // 设置绘制文字的矩形区域，根据需要调整大小
            painter.drawText(tRect, Qt::AlignCenter, convertAzimuthC(slidAzimuth));
        }
        slidX += 45;
        slidAzimuth = transformAzimuth(slidAzimuth + 15);
    }
}

AzimuthBar::~AzimuthBar() = default;
