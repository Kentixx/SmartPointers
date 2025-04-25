#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QScreen>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QVBoxLayout>

class InfoWindow : public QWidget {
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent = nullptr);
    ~InfoWindow() {};
    void setInfo(const QString &title, const QString &text);

private:
    QLabel *titleLabel;
    QTextBrowser *detailsText;
    QPushButton *closeButton;
};

#endif //INFOWINDOW_H
