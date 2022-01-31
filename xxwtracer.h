#ifndef XXWTRACER_H
#define XXWTRACER_H

#include <QObject>
#include "qcustomplot.h"


///
/// \brief The XxwTracer class:在图表中显示鼠标所在位置的x,y值的追踪显示器
///
class XxwTracer : public QObject
{
    Q_OBJECT

public:
enum TracerType
{
    XAxisTracer,//依附在x轴上显示x值
    YAxisTracer,//依附在y轴上显示y值
    DataTracer//在图中显示x,y值
};
    explicit XxwTracer(QCustomPlot *_plot, TracerType _type, QObject *parent = Q_NULLPTR);
    ~XxwTracer();
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setText(const QString &text);
    void setLabelPen(const QPen &pen);
    void updatePosition(double xValue, double yValue);
    void setVisible(bool m_visible);

protected:
    bool m_visible;//是否可见
    TracerType m_type;//类型
    QCustomPlot *m_plot;//图表
    QCPItemTracer *m_tracer;//跟踪的点
    QCPItemText *m_label;//显示的数值
    QCPItemLine *m_arrow;//箭头
};

#endif // XXWTRACER_H
