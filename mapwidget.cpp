
#include "mapwidget.h"
#include <QPainter>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QJsonDocument>
#include <QFile>
#include <QImageWriter>
#include <QBuffer> // Для использования QBuffer

MapWidget::MapWidget(QWidget *parent)
    : QWidget(parent),
    scaleFactor(1.0),  // Начальный масштаб
    isDragging(false),  // Карта не перетаскивается по умолчанию
    offset(0, 0)  // Начальное смещение
{
    setMouseTracking(true);
}

MapWidget::~MapWidget()
{
}

void MapWidget::setImage(const QImage &image)
{
    mapImage = image;
    update();  // Перерисовываем виджет
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Масштабируем картинку
    painter.scale(scaleFactor, scaleFactor);

    // Применяем смещение, чтобы перемещать карту
    painter.translate(offset);

    // Рисуем карту
    painter.drawImage(0, 0, mapImage);

    // Рисуем сетку с учетом масштаба и смещения
    drawGrid(painter);
}

void MapWidget::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
        zoomIn();
    else
        zoomOut();
}

void MapWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging) {
        // Вычисляем разницу в положении мыши и обновляем смещение карты
        QPoint delta = event->pos() - lastMousePos;
        offset += delta;
        update();  // Перерисовываем виджет, чтобы отобразить перемещённую карту
    }
    lastMousePos = event->pos();
}

void MapWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        lastMousePos = event->pos();
    }
}

void MapWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
    }
}

void MapWidget::drawGrid(QPainter &painter)
{
    // Рассчитываем размер ячеек в зависимости от масштаба
    int baseGridSize = 50;  // Базовый размер ячейки
    int gridSize = baseGridSize * scaleFactor;  // Умножаем на масштаб

    painter.setPen(QPen(Qt::black, 1, Qt::DotLine));

    // Вычисляем сколько линий помещается по ширине и высоте с учетом масштаба
    int numHorizontalLines = mapImage.height() * scaleFactor / gridSize;
    int numVerticalLines = mapImage.width() * scaleFactor / gridSize;

    // Рисуем вертикальные линии
    for (int i = 0; i <= numVerticalLines; ++i) {
        int x = i * gridSize;
        painter.drawLine(x, 0, x, mapImage.height() * scaleFactor);
    }

    // Рисуем горизонтальные линии
    for (int i = 0; i <= numHorizontalLines; ++i) {
        int y = i * gridSize;
        painter.drawLine(0, y, mapImage.width() * scaleFactor, y);
    }
}



void MapWidget::updateScale(double scale)
{
    scaleFactor = scale;
    update();
}

void MapWidget::zoomIn()
{
    updateScale(scaleFactor * 1.1);
}

void MapWidget::zoomOut()
{
    updateScale(scaleFactor / 1.1);
}

QJsonObject MapWidget::imageToJson(const QImage &image)
{
    QJsonObject imageObject;

    // Сохраняем размеры изображения
    imageObject["width"] = image.width();
    imageObject["height"] = image.height();

    // Преобразуем изображение в формат Base64 для хранения в JSON
    QByteArray byteArray;
    QBuffer buffer(&byteArray);   // Используем QBuffer для записи в QByteArray
    buffer.open(QIODevice::WriteOnly);

    QImageWriter writer(&buffer, "PNG");
    writer.write(image);   // Записываем изображение в буфер

    QString base64Image = byteArray.toBase64();  // Кодируем в Base64

    imageObject["image"] = base64Image;

    return imageObject;
}


void MapWidget::saveImageAsJson(const QString &filePath)
{
    if (mapImage.isNull()) {
        return;
    }

    // Преобразуем изображение в JSON
    QJsonObject json = imageToJson(mapImage);

    // Сохраняем JSON в файл
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(json);
        file.write(doc.toJson());
        file.close();
    }
}
