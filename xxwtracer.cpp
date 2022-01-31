#include "xxwtracer.h"

XxwTracer::XxwTracer(QCustomPlot *_plot, TracerType _type, QObject *parent)
    : QObject(parent),
      m_plot(_plot),
      m_type(_type)
{
    m_visible = true;
    m_tracer = Q_NULLPTR;// 跟踪的点
    m_label = Q_NULLPTR;// 显示的数值
    m_arrow = Q_NULLPTR;// 箭头
    if (m_plot)
    {
        QColor clrDefault(Qt::red);
        QBrush brushDefault(Qt::NoBrush);
        QPen penDefault(clrDefault);
        //        penDefault.setBrush(brushDefault);
        penDefault.setWidthF(0.5);

        m_tracer = new QCPItemTracer(m_plot);
        m_tracer->setStyle(QCPItemTracer::tsCircle);
        m_tracer->setPen(penDefault);
        m_tracer->setBrush(brushDefault);

        m_label = new QCPItemText(m_plot);
        m_label->setLayer("overlay");
        m_label->setClipToAxisRect(false);
        m_label->setPadding(QMargins(5, 5, 5, 5));
        m_label->setBrush(brushDefault);
        m_label->setPen(penDefault);
        m_label->position->setParentAnchor(m_tracer->position);
//        m_label->setFont(QFont("宋体", 8));
        m_label->setFont(QFont("Arial", 8));
        m_label->setColor(clrDefault);
        m_label->setText("");

        m_arrow = new QCPItemLine(m_plot);
        QPen  arrowPen(clrDefault, 1);
        m_arrow->setPen(penDefault);
        m_arrow->setLayer("overlay");
        m_arrow->setClipToAxisRect(false);
        m_arrow->setHead(QCPLineEnding::esSpikeArrow);//设置头部为箭头形状

        switch (m_type)
        {
        case XAxisTracer:
        {
            //m_tracer->position->setTypeX(QCPItemPosition::ptPlotCoords);
            //m_tracer->position->setTypeY(QCPItemPosition::ptAxisRectRatio);
            //m_tracer->setSize(7);
            //m_label->setPositionAlignment(Qt::AlignTop | Qt::AlignHCenter);

            //m_arrow->end->setParentAnchor(m_tracer->position);
            //m_arrow->start->setParentAnchor(m_arrow->end);
            //m_arrow->start->setCoords(0, 20);//偏移量
            break;
        }
        case YAxisTracer:
        {
            m_tracer->position->setTypeX(QCPItemPosition::ptAxisRectRatio);
            m_tracer->position->setTypeY(QCPItemPosition::ptPlotCoords);
            m_tracer->setSize(7);
            m_label->setPositionAlignment(Qt::AlignRight | Qt::AlignHCenter);

            m_arrow->end->setParentAnchor(m_tracer->position);
            m_arrow->start->setParentAnchor(m_label->position);
            m_arrow->start->setCoords(-20, 0);//偏移量
            break;
        }
        case DataTracer:
        {
            m_tracer->position->setTypeX(QCPItemPosition::ptPlotCoords);
            m_tracer->position->setTypeY(QCPItemPosition::ptPlotCoords);
            m_tracer->setSize(5);

            m_label->setColor(QColor(255,255,255));
            m_label->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);

            m_arrow->end->setParentAnchor(m_tracer->position);
            m_arrow->start->setParentAnchor(m_arrow->end);
            m_arrow->start->setCoords(20, 0);
            break;
        }
        default:
            break;
        }
        setVisible(false);
    }
}

XxwTracer::~XxwTracer()
{
    if(m_plot)
    {
        if (m_tracer)
            m_plot->removeItem(m_tracer);
        if (m_label)
            m_plot->removeItem(m_label);
        if (m_arrow)
            m_plot->removeItem(m_arrow);
    }
}

void XxwTracer::setPen(const QPen &pen)
{
    if(m_tracer)
        m_tracer->setPen(pen);
    if(m_arrow)
        m_arrow->setPen(pen);
}

void XxwTracer::setBrush(const QBrush &brush)
{
    if(m_tracer)
        m_tracer->setBrush(brush);
}

void XxwTracer::setLabelPen(const QPen &pen)
{
    if(m_label)
    {
        m_label->setPen(pen);
        m_label->setBrush(Qt::NoBrush);
        m_label->setColor(pen.color());
    }
}

void XxwTracer::setText(const QString &text)
{
    if(m_label)
        m_label->setText(text);
}

void XxwTracer::setVisible(bool vis)
{
    m_visible = vis;
    if(m_tracer)
        m_tracer->setVisible(m_visible);
    if(m_label)
        m_label->setVisible(m_visible);
    if(m_arrow)
        m_arrow->setVisible(m_visible);
}

void XxwTracer::updatePosition(double xValue, double yValue)
{
    if (!m_visible)
    {
        setVisible(true);
        m_visible = true;
    }

    if (yValue > m_plot->yAxis->range().upper)
        yValue = m_plot->yAxis->range().upper;

    switch (m_type)
    {
    case XAxisTracer:
    {
        m_tracer->position->setCoords(0, -1000);
        m_label->position->setCoords(0, -1000);
        m_arrow->start->setCoords(0, -1000);
        m_arrow->end->setCoords(0, -1000);
        //setText(QString::number(xValue));
        break;
    }
    case YAxisTracer:
    {
        m_tracer->position->setCoords(0, -1000);
        m_label->position->setCoords(0, -1000);
        m_arrow->start->setCoords(0, -1000);
        m_arrow->end->setCoords(0, -1000);
        //setText(QString::number(yValue));
        break;
    }
    case DataTracer:
    {
        m_tracer->position->setCoords(xValue, yValue);
        m_label->position->setCoords(20, 0);
        setText(QString("x:%1\ny:%2").arg(xValue).arg(yValue));
        break;
    }
    default:
        break;
    }
}
