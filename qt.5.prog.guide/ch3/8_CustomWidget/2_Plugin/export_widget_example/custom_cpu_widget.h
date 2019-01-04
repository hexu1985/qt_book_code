#ifndef CUSTOM_CPU_WIDGET_H
#define CUSTOM_CPU_WIDGET_H

#include <QtGui/QWidget>
#include <QtDesigner/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT custom_cpu_widget : public QWidget
{
    Q_OBJECT

public:
    custom_cpu_widget(QWidget *parent = 0); // CPU 위젯 클래스 생성자
    void cpu_set_widget_level(int level); // CPU 사용레벨을 설정

private:
    int w_width; // 위젯의 가로크기
    int w_height; // 위젯의 세로크기
    int cpu_used_level; // CPU 사용율을 변수에 저장

protected:
    // CPU 사용율을 그리는 함수
    virtual void paintEvent(QPaintEvent *event);
};

#endif
