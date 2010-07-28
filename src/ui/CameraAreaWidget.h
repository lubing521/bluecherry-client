#ifndef CAMERAAREAWIDGET_H
#define CAMERAAREAWIDGET_H

#include <QWidget>
#include <QList>

class QGridLayout;

class CameraAreaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CameraAreaWidget(QWidget *parent = 0);

    int rows() const { return m_rowCount; }
    int columns() const { return m_columnCount; }
    void setGridSize(int rows, int columns);

public slots:
    void setRows(int rows) { setGridSize(rows, m_columnCount); }
    void addRow() { setGridSize(m_rowCount+1, m_columnCount); }
    void removeRow() { setGridSize(m_rowCount-1, m_columnCount); }

    void setColumns(int columns) { setGridSize(m_rowCount, columns); }
    void addColumn() { setGridSize(m_rowCount, m_columnCount+1); }
    void removeColumn() { setGridSize(m_rowCount, m_columnCount-1); }

signals:
    void gridSizeChanged(int rows, int columns);

private:
    QList<QWidget*> m_cameraWidgets;
    QGridLayout *mainLayout;
    int m_rowCount, m_columnCount;
};

#endif // CAMERAAREAWIDGET_H