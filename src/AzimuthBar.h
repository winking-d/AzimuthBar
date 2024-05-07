//
// Created by dyh on 2024/5/6.
//

#ifndef AZIMUTHBAR_AZIMUTHBAR_H
#define AZIMUTHBAR_AZIMUTHBAR_H

#include <QWidget>

class AzimuthBar : public QWidget {
Q_OBJECT
public:
    explicit AzimuthBar(QWidget *parent = nullptr);

    ~AzimuthBar() override;

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void onChangeAzimuth(int azimuth);

private:
    int m_currentAzimuth = 0;
};


#endif //AZIMUTHBAR_AZIMUTHBAR_H
