#include "detailedcosts.h"
#include <QString>
#include <iostream>


void detailedcosts::connectViewSignals() const
{

}
void detailedcosts::closeEvent(QCloseEvent *event)
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
    QVBoxLayout* main = new QVBoxLayout;
    main->addLayout(addIstogramma());
    setLayout(main);
    setFixedSize(s);
    setTitle("Dettaglio Costi Viaggio");
}

 QVBoxLayout* detailedcosts::addIstogramma() {
     QVBoxLayout* layout = new QVBoxLayout;
    std::vector<QBarSet*> dati;
        for(int j = 0; j < c->getV().size(); j++){
            string desc = (c->getV()[j]->getTarga());
            QString qdesc = QString::fromStdString(desc);
            QBarSet* tmp = new QBarSet(qdesc);
            dati.push_back(tmp);
        }
        for(int j = 0; j < c->getV().size(); j++){
           *dati[j] << c->getCosti()[j];

        }
        QBarSeries *series = new QBarSeries();
        for(int j = 0; j < c->getV().size(); j++){
            series->append(dati[j]);
        }

        QChart* chart = new QChart();
        chart->addSeries(series);

        chart->setTitle("Dettaglio Costi Viaggio");
        chart->setAnimationOptions(QChart::AllAnimations);
        chart->createDefaultAxes();
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView* chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setRubberBand(QChartView::HorizontalRubberBand);

        QPalette pal = qApp->palette();
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));

        layout->addWidget(chartView);

     return layout;

}
