#include "detailedcosts.h"
#include <QString>
#include <iostream>

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

detailedcosts::detailedcosts(CostiViaggio* cost,const QSize &s, view *parent) : view(s, parent)
{
    c = cost;
    QBoxLayout* main = new QVBoxLayout;

    QVBoxLayout* chart = new QVBoxLayout;
    chart->addLayout(addDiagrammaCartesiano());
    main->addLayout(chart);
    setLayout(main);
    setFixedSize(s);
    setTitle("Dettaglio Costi Viaggio");
}

 QVBoxLayout* detailedcosts::addDiagrammaCartesiano() {
     QVBoxLayout* layout = new QVBoxLayout;
    QLineSeries* lineseries = new QLineSeries();


        for(int i = 0; i < c->getV().size(); i++){
            lineseries->append(i,c->getCosti()[i]);
         }
         QChart* chart = new QChart();
         chart->addSeries(lineseries);
         chart->setTitle("Risultati Campionato F1 2021");
         QBarCategoryAxis *axisX = new QBarCategoryAxis();
         for(int i = 0; i < c->getV().size(); i++){
            axisX->append(QString::fromStdString(std::to_string(i+1) + ") " +c->getV()[i]->getTarga()));
         }
         chart->addAxis(axisX, Qt::AlignBottom);
         lineseries->attachAxis(axisX);

         QValueAxis *axisY = new QValueAxis();
         chart->addAxis(axisY, Qt::AlignLeft);
         lineseries->attachAxis(axisY);
         chart->legend()->setVisible(true);
         chart->legend()->setAlignment(Qt::AlignBottom);
         chart->setAnimationOptions(QChart::AllAnimations);
         QChartView* chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->setRubberBand(QChartView::HorizontalRubberBand);
         layout->addWidget(chartView);
     return layout;

}
