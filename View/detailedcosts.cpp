#include "detailedcosts.h"
#include <QString>
#include <iostream>
/*#include <QBarSet>
#include <QBarSeries>
#include <QLine>
#include <QtCharts>
*/
QLayout *detailedcosts::configureFinalLayout(){
    // Creazione Layout
    QBoxLayout* mainLayout = new QVBoxLayout();

    // Aggiunta dei Vari Componenti al Layout
    mainLayout->addLayout(configureDescription());
    return mainLayout;
}
QVBoxLayout *detailedcosts::configureDescription()
{
    QVBoxLayout* desc = new QVBoxLayout();

    return desc;
}

void detailedcosts::connectViewSignals() const
{
    //connect(createGarage, SIGNAL(clicked()), this, SIGNAL(newGarage()));
    //connect(openGarage, SIGNAL(clicked()), this, SIGNAL(readGarage()));
}
void detailedcosts::close(QCloseEvent *event)
{
    //Elaboro chiusura solo se intenzionata da evento esterno
        if(!event->spontaneous()) return;
        else {
            //Accetto l'evento di chiusura della finestra
            event->accept();
            //Emetto segnale di chiusura della View
            emit viewClosed();
        }
}

detailedcosts::detailedcosts(CostiViaggio* c,const QSize &s, view *parent) : view(s, parent)
{
    QBoxLayout* main = new QVBoxLayout;
    main->addLayout(configureFinalLayout());

    setLayout(main);
    setFixedSize(s);
    connectViewSignals();
    setTitle("Dettaglio Costi Viaggio");
}

 void detailedcosts::addDiagrammaCartesiano() {
    /*QLineSeries* lineseries = new QLineSeries();
     if(::barra > 0){
     lineseries->setPen(QPen(QColor(Qt::red)));
     }

    for(int i = 0; i < model->getMaxX(s1); i++){
        lineseries->append(i,model->getDati(s1)[i]);
     }
     QChart() chart = new QChart();
     chart->addSeries(lineseries);
     chart->setTitle("Risultati Campionato F1 2021");
     QBarCategoryAxis *axisX = new QBarCategoryAxis();
     for(int i = 0; i <model->getMaxX(s1); i++){
        axisX->append(QString::fromStdString(std::to_string(i+1) + ") " + model->getDescrizioni(s1)[i]));
     }
     chart->addAxis(axisX, Qt::AlignBottom);
     lineseries->attachAxis(axisX);

     QValueAxis *axisY = new QValueAxis();
     chart->addAxis(axisY, Qt::AlignLeft);
     lineseries->attachAxis(axisY);
     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);
     chart->setAnimationOptions(QChart::AllAnimations);
     chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->setRubberBand(QChartView::HorizontalRubberBand);
     mainLayout->addWidget(chartView);
     */
}
