#include "xxwcustomplot.h"

XxwCustomPlot::XxwCustomPlot(QWidget *parent)
    :QCustomPlot(parent)
    ,m_isShowTracer(false)
    ,m_xTracer(Q_NULLPTR)
    ,m_yTracer(Q_NULLPTR)
    ,m_dataTracers(QList<XxwTracer *>())
{
    // 设置x/y轴文本色、轴线色、字体等
    QBrush qBrush(QColor(130,130,130));
    this->setBackground(qBrush);
}

void XxwCustomPlot::mouseMoveEvent(QMouseEvent *event)
{
    QCustomPlot::mouseMoveEvent(event);

    if(m_isShowTracer)
    {
        //当前鼠标位置（像素坐标）
        int x_pos = event->pos().x();
        int y_pos = event->pos().y();

        //像素坐标转成实际的x,y轴的坐标
        float x_val = this->xAxis->pixelToCoord(x_pos);
        float y_val = this->yAxis->pixelToCoord(y_pos);

        if(Q_NULLPTR == m_xTracer)
            m_xTracer = new XxwTracer(this, XxwTracer::XAxisTracer);//x轴
        m_xTracer->updatePosition(x_val, y_val);

        if(Q_NULLPTR == m_yTracer)
            m_yTracer = new XxwTracer(this, XxwTracer::YAxisTracer);//y轴
        m_yTracer->updatePosition(x_val, y_val);

        int nTracerCount = m_dataTracers.count();
        int nGraphCount = graphCount();
        if(nTracerCount < nGraphCount)
        {
            for(int i = nTracerCount; i < nGraphCount; ++i)
            {
                XxwTracer *tracer = new XxwTracer(this, XxwTracer::DataTracer);
                m_dataTracers.append(tracer);
            }
        }
        else if(nTracerCount > nGraphCount)
        {
            for(int i = nGraphCount; i < nTracerCount; ++i)
            {
                XxwTracer *tracer = m_dataTracers[i];
                if(tracer)
                {
                    tracer->setVisible(false);
                }
            }
        }
        for (int i = 0; i < nGraphCount; ++i)
        {
            XxwTracer *tracer = m_dataTracers[i];
            if(!tracer)
                tracer = new XxwTracer(this, XxwTracer::DataTracer);
            tracer->setVisible(true);
            tracer->setPen(this->graph(i)->pen());
            tracer->setBrush(Qt::NoBrush);
            tracer->setLabelPen(this->graph(i)->pen());
            auto iter = this->graph(i)->data()->findBegin(x_val);
            double value = iter->mainValue();
//            double value = this->graph(i)->data()->findBegin(x_val)->value;
            tracer->updatePosition(x_val, value);
        }



        this->replot();//曲线重绘
    }
}

