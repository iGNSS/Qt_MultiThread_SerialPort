#ifndef XXWCUSTOMPLOT_H
#define XXWCUSTOMPLOT_H

#include "qcustomplot.h"
#include <QObject>
#include <QList>
#include "xxwtracer.h"

class XxwCustomPlot : public QCustomPlot
{
    Q_OBJECT
public:
    XxwCustomPlot(QWidget *parent = 0);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);

public:
    void showTracer(bool show)
    {
        m_isShowTracer = show;
        if(m_xTracer)
        {
            m_xTracer->setVisible(m_isShowTracer);
            foreach (XxwTracer *tracer, m_dataTracers)
            {
                if(tracer)
                    tracer->setVisible(m_isShowTracer);
            }
        }
    }

    bool isshowTracer() {return m_isShowTracer;}
    void initial_2(); //初始
    void resive_2();  //接受到数据

private:
    bool m_isShowTracer;//是否显示追踪器（鼠标在图中移动，显示对应的值）
    XxwTracer *m_xTracer;//x轴
    XxwTracer *m_yTracer;//y轴
    QList<XxwTracer *> m_dataTracers;//
    //XxwTraceLine  *m_lineTracer;//直线
};

#endif // XXWCUSTOMPLOT_H
