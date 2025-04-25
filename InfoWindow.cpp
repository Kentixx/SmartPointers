#include "InfoWindow.h"

InfoWindow::InfoWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Информация");
    titleLabel = new QLabel(this);
    detailsText = new QTextBrowser(this);
    closeButton = new QPushButton("Закрыть", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(detailsText);
    layout->addWidget(closeButton);
    setLayout(layout);

    connect(closeButton, &QPushButton::clicked, this, &QWidget::close);
}

void InfoWindow::setInfo(const QString& title, const QString& details) {
    titleLabel->setText(title);
    detailsText->setText(details);
    resize(400, 300);
}
