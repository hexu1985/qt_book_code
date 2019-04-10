﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include    <QSplitter>

//#include    <QtDataVisualization>

//using namespace QtDataVisualization;

#include    <QColorDialog>

void MainWindow::iniGraph3D()
{
    graph3D = new Q3DSurface();
    graphContainer = QWidget::createWindowContainer(graph3D); //Q3DBars继承自QWindow，必须如此创建

//创建坐标轴
    QValue3DAxis *axisX=new QValue3DAxis;   //X,东西
    axisX->setTitle("东--西");
    axisX->setTitleVisible(true);
    axisX->setLabelFormat("%.1f 米");
    axisX->setRange(-5000,5000);
    graph3D->setAxisX(axisX);


    QValue3DAxis *axisY=new QValue3DAxis; //Y，深度
    axisY->setTitle("深度");
    axisY->setTitleVisible(true);
    axisY->setAutoAdjustRange(true);
//    axisX->setRange(200,500);
//    axisX->setReversed(true);
    graph3D->setAxisY(axisY);

    QValue3DAxis *axisZ=new QValue3DAxis;   //Z, 南北
    axisZ->setTitle("南--北");
    axisZ->setLabelFormat("%.1f 米");
    axisZ->setTitleVisible(true);
    axisZ->setRange(-5000,5000);
    graph3D->setAxisZ(axisZ);

    graph3D->activeTheme()->setLabelBackgroundEnabled(false);

//创建数据代理
//    QImage heightMapImage(":/map/mountain.png");
//    QImage heightMapImage(":/map/seagray.png");
    QImage heightMapImage(":/map/sea.png");
    proxy = new QHeightMapSurfaceDataProxy(heightMapImage);
    proxy->setValueRanges(-5000, 5000, -5000, 5000);

    series = new QSurface3DSeries(proxy);
    series->setItemLabelFormat("(@xLabel, @zLabel): @yLabel");
    series->setFlatShadingEnabled(false);
    series->setMeshSmooth(true);
    series->setDrawMode(QSurface3DSeries::DrawSurface);

    graph3D->addSeries(series);

//    m_heightMapWidth = heightMapImage.width();
//    m_heightMapHeight = heightMapImage.height();


//    graph3D->axisX()->setLabelFormat("%.1f N");

//    graph3D->axisZ()->setLabelFormat("%.1f E");
//    graph3D->axisX()->setRange(34.0f, 40.0f);
//    graph3D->axisY()->setAutoAdjustRange(true);
//    graph3D->axisZ()->setRange(18.0f, 24.0f);

//    graph3D->axisX()->setTitle(QStringLiteral("纬度"));//Latitude
//    graph3D->axisY()->setTitle(QStringLiteral("高程"));
//    graph3D->axisZ()->setTitle(QStringLiteral("经度")); //Longitude

//    graph3D->activeTheme()->setLabelBackgroundEnabled(false);
//    series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
//    series->setDrawMode(QSurface3DSeries::DrawSurface);
//    graph3D->addSeries(series);

////创建数据
//    int N=41;
//    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
//    dataArray->reserve(N);

//////    //双峰，N=21
//    float x=-10,y,z;
//    int i,j;
//    for (i =1 ; i <=N; i++)
//    {
//        QSurfaceDataRow *newRow = new QSurfaceDataRow(N);
//        y=-10;
//        int index=0;
//        for (j = 1; j <=N; j++)
//        {
//            z=qSqrt(x*x+y*y);
//            if (z!=0)
//                z=10*qSin(z)/z;
//            else
//                z=10;
////            y=qSin(qSqrt(x*x+z*z));
//            (*newRow)[index++].setPosition(QVector3D(x, z, y));
//            y=y+0.5;
//        }
//        x=x+0.5;
//        dataArray->append(newRow);
//    }

////墨西哥草帽,-10:0.5:10， N=41
//    float x,y,z;
//    int i,j;

//    x=-10;
//    for (i=1 ; i <=N; i++)
//    {
//        y=-10;
//        for ( j =1; j <=N; j++)
//        {
//            z=qSqrt(x*x+y*y);
//            if (z!=0)
//                z=10*qSin(z)/z;
//            else
//                z=10;

//            ptrToDataArray->setPosition(QVector3D(x,z,y));
//            ptrToDataArray++;
//            y+=0.5;
//        }
//        x+=0.5;
//    }

//    proxy->resetArray(dataArray);
//    graph3D->axisX()->setRange(-5,5);
//    graph3D->axisY()->setRange(-5,5);
//    graph3D->axisZ()->setRange(-2,2);

}

//QVector3D MainWindow::randVector()
//{
//    return QVector3D(
//                (float)(rand() % 100) / 2.0f - (float)(rand() % 100) / 2.0f,
//                (float)(rand() % 100) / 100.0f - (float)(rand() % 100) / 100.0f,
//                (float)(rand() % 100) / 2.0f - (float)(rand() % 100) / 2.0f);
//}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLinearGradient grBtoY(0, 0, 100, 0);
    grBtoY.setColorAt(1.0, Qt::black);
    grBtoY.setColorAt(0.67, Qt::blue);
    grBtoY.setColorAt(0.33, Qt::red);
    grBtoY.setColorAt(0.0, Qt::yellow);

    QPixmap pm(160, 20);
    QPainter pmp(&pm);
    pmp.setBrush(QBrush(grBtoY));
    pmp.setPen(Qt::NoPen);
    pmp.drawRect(0, 0, 160, 20);
    ui->btnGrad1->setIcon(QIcon(pm));
    ui->btnGrad1->setIconSize(QSize(160, 20));

    QLinearGradient grGtoR(0, 0, 100, 0);
//    grGtoR.setColorAt(0.0, Qt::darkGreen);
//    grGtoR.setColorAt(0.2, Qt::yellow);
//    grGtoR.setColorAt(0.5, Qt::red);
//    grGtoR.setColorAt(1.0, Qt::darkRed);
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);
    pmp.setBrush(QBrush(grGtoR));
    pmp.drawRect(0, 0, 160, 20);
    ui->btnGrad2->setIcon(QIcon(pm));
    ui->btnGrad2->setIconSize(QSize(160, 20));


    iniGraph3D();

    QSplitter   *splitter=new QSplitter(Qt::Horizontal);
    splitter->addWidget(ui->groupBox);
    splitter->addWidget(graphContainer);

    this->setCentralWidget(splitter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chkBoxGrid_clicked(bool checked)
{ //图表的网格
    graph3D->activeTheme()->setGridEnabled(checked);
}

void MainWindow::on_chkBoxSmooth_clicked(bool checked)
{ //柱状图的光滑性
    series->setMeshSmooth(checked);
}

void MainWindow::on_chkBoxReflection_clicked(bool checked)
{//反射
    graph3D->setReflection(checked);
}

void MainWindow::on_chkBoxAxisTitle_clicked(bool checked)
{//轴标题
    graph3D->axisX()->setTitleVisible(checked);
    graph3D->axisY()->setTitleVisible(checked);
    graph3D->axisZ()->setTitleVisible(checked);
}

void MainWindow::on_chkBoxAxisBackground_clicked(bool checked)
{//轴标题背景
    graph3D->activeTheme()->setLabelBackgroundEnabled(checked);
}

void MainWindow::on_chkBoxReverse_clicked(bool checked)
{//Z轴反向
    graph3D->axisY()->setReversed(checked);
}

void MainWindow::on_chkBoxBackground_clicked(bool checked)
{//图表的背景
    graph3D->activeTheme()->setBackgroundEnabled(checked);
}

void MainWindow::on_spinFontSize_valueChanged(int arg1)
{//轴标签字体大小
    QFont font = graph3D->activeTheme()->font();
    font.setPointSize(arg1);
    graph3D->activeTheme()->setFont(font);
}

void MainWindow::on_cBoxTheme_currentIndexChanged(int index)
{//设置主题
    Q3DTheme *currentTheme = graph3D->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(index));
}

void MainWindow::on_btnBarColor_clicked()
{ //设置序列柱状图的颜色
    QColor  color=series->baseColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
    {
        series->setBaseColor(color);
        series->setColorStyle(Q3DTheme::ColorStyleUniform);
    }
}

void MainWindow::on_chkBoxItemLabel_clicked(bool checked)
{ //项的标签
    series->setItemLabelVisible(checked);
}

void MainWindow::on_cBoxBarStyle_currentIndexChanged(int index)
{ //棒图的样式
    QAbstract3DSeries::Mesh aMesh;
    aMesh=QAbstract3DSeries::Mesh(index+1);
    series->setMesh(aMesh);
}

void MainWindow::on_cBoxSelectionMode_currentIndexChanged(int index)
{//选择模式
//    graph3D->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow | QAbstract3DGraph::SelectionSlice);

    switch(index)
    {
     case 0:    //none
        graph3D->setSelectionMode(QAbstract3DGraph::SelectionNone);
        break;
     case 1:    //Item
        graph3D->setSelectionMode(QAbstract3DGraph::SelectionItem);
        break;
     case 2:    //Row Slice
        graph3D->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow
                                  | QAbstract3DGraph::SelectionSlice);
        break;
     case 3:    //Column Slice
        graph3D->setSelectionMode(QAbstract3DGraph::SelectionItemAndColumn
                                 | QAbstract3DGraph::SelectionSlice);
    default:
        break;

    }
}


void MainWindow::on_chkBoxShadow_clicked(bool checked)
{
    if (checked)
       graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityMedium);
    else
       graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    graph3D->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPreset(index));
}

void MainWindow::on_sliderH_valueChanged(int value)
{
    Q_UNUSED(value);
    int xRot =ui->sliderH->value();
    int yRot=ui->sliderV->value();
    int zoom=ui->sliderZoom->value(); //缩放
    graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot,zoom);
//    graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot);
}

void MainWindow::on_sliderV_valueChanged(int value)
{
    on_sliderH_valueChanged(value);
}

void MainWindow::on_comboDrawMode_currentIndexChanged(int index)
{
    if (index==0)
        series->setDrawMode(QSurface3DSeries::DrawWireframe);
    else if (index==1)
        series->setDrawMode(QSurface3DSeries::DrawSurface);
    else
        series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
}

void MainWindow::on_btnGrad1_clicked()
{
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);

    series->setBaseGradient(gr);
    series->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
//    series->setColorStyle(Q3DTheme::ColorStyleUniform);
}

void MainWindow::on_btnGrad2_clicked()
{
    QLinearGradient grGtoR;
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);

    series->setBaseGradient(grGtoR);
    series->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

void MainWindow::on_sliderZoom_valueChanged(int value)
{
    on_sliderH_valueChanged(value);
}
