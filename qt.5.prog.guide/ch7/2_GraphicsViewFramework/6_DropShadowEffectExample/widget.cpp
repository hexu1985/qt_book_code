#include "widget.h"

Widget::Widget(QWidget *parent) : QGraphicsView(parent)
{
    setScene(&m_scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setupScene();

    setRenderHint(QPainter::Antialiasing, true);
    setFrameStyle(QFrame::NoFrame);
}

void Widget::setupScene()
{
    QGraphicsRectItem *parent = m_scene.addRect(0, 0, 600, 360);
    parent->setPen(Qt::NoPen);
    parent->setZValue(0);

    QGraphicsPixmapItem *bg[7];
    qreal x = 40.0, y = 30.0;

    for(int i = 0, j = 0 ; i < 7 ; i++, j++)
    {
        bg[i] = m_scene.addPixmap(QPixmap(":/resources/lena.png"));
        bg[i]->setParentItem(parent); // �θ� �׷��Ƚ��� ������ ����
        bg[i]->moveBy(x, y); // ��ǥ����
        bg[i]->setZValue(1);

        x += 160;

        if(i == 3){
            x = 200;
            y += 170;
        }
    }

    m_effect[0] = new QGraphicsDropShadowEffect;
    // R,G,B,Alpha - Alpha���� �������� ������ 1�� ����
    m_effect[0]->setColor(QColor(63, 63, 63, 180));
    bg[1]->setGraphicsEffect(m_effect[0]); // Drop Shadow Effect�� ������ ������

    m_effect[1] = new QGraphicsDropShadowEffect;
    m_effect[1]->setColor(QColor(63, 63, 63, 180));
    // �׸��ڿ��� ����ȿ�� ����, ������� ������ ����Ʈ �� 1�� ������
    m_effect[1]->setBlurRadius(15.0);
    m_effect[1]->setEnabled(true);
    bg[2]->setGraphicsEffect(m_effect[1]);

    m_effect[2] = new QGraphicsDropShadowEffect;
    m_effect[2]->setColor(QColor(63, 63, 63, 180));
    m_effect[2]->setBlurRadius(15.0);
    // �׸��ڰ� ǥ�õ� ����, X�� ����� ������, ������ ����, Y�� ����� �Ʒ�, ������ ����
    // �������� ������ ����Ʈ �� X=8, Y=8
    m_effect[2]->setOffset(20, 20);
    m_effect[1]->setEnabled(true);
    bg[3]->setGraphicsEffect(m_effect[2]);

    m_effect[3] = new QGraphicsDropShadowEffect;
    m_effect[3]->setColor(QColor(63, 63, 63, 180));
    m_effect[3]->setBlurRadius(15.0);
    m_effect[3]->setOffset(-20, 20);
    m_effect[1]->setEnabled(true);
    bg[4]->setGraphicsEffect(m_effect[3]);

    m_effect[4] = new QGraphicsDropShadowEffect;
    m_effect[4]->setColor(QColor(63, 63, 63, 180));
    m_effect[4]->setBlurRadius(15.0);
    m_effect[4]->setOffset(-20, -20);
    m_effect[1]->setEnabled(true);
    bg[5]->setGraphicsEffect(m_effect[4]);

    m_effect[5] = new QGraphicsDropShadowEffect;
    m_effect[5]->setColor(QColor(63, 63, 63, 180));
    m_effect[5]->setBlurRadius(15.0);
    m_effect[5]->setOffset(20, -20);
    m_effect[1]->setEnabled(true);
    bg[6]->setGraphicsEffect(m_effect[5]);
}

Widget::~Widget()
{

}
