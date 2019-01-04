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
        bg[i]->setParentItem(parent); // 부모 그래픽스뷰 아이템 지정
        bg[i]->moveBy(x, y); // 좌표설정
        bg[i]->setZValue(1);

        x += 160;

        if(i == 3){
            x = 200;
            y += 170;
        }
    }

    m_effect[0] = new QGraphicsDropShadowEffect;
    // R,G,B,Alpha - Alpha값을 지정하지 않으면 1로 설정
    m_effect[0]->setColor(QColor(63, 63, 63, 180));
    bg[1]->setGraphicsEffect(m_effect[0]); // Drop Shadow Effect를 지정할 아이템

    m_effect[1] = new QGraphicsDropShadowEffect;
    m_effect[1]->setColor(QColor(63, 63, 63, 180));
    // 그림자영역 투명효과 설정, 사용하지 않으면 디폴트 값 1이 설정됨
    m_effect[1]->setBlurRadius(15.0);
    m_effect[1]->setEnabled(true);
    bg[2]->setGraphicsEffect(m_effect[1]);

    m_effect[2] = new QGraphicsDropShadowEffect;
    m_effect[2]->setColor(QColor(63, 63, 63, 180));
    m_effect[2]->setBlurRadius(15.0);
    // 그림자가 표시될 방향, X가 양수면 오른쪽, 음수면 왼쪽, Y가 양수면 아래, 음수면 위쪽
    // 지정하지 않으면 디폴트 값 X=8, Y=8
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
