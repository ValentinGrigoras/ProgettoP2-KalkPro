#include "valoreselezionato.h"

ValoreSelezionato::ValoreSelezionato(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout;
    m_label = new QLabel(this);
    m_label->setAlignment((Qt::AlignCenter));
    m_slider = new QSlider(Qt::Horizontal,this);
    m_spinbox = new QSpinBox(this);
    layout->addWidget(m_label,0,0,1,1);
    layout->addWidget(m_slider,0,1,1,3);
    layout->addWidget(m_spinbox,0,4);
    setLayout(layout);

    connect(m_slider,SIGNAL(valueChanged(int)),m_spinbox,SLOT(setValue(int)));
    connect(m_spinbox,SIGNAL(valueChanged(int)),m_slider,SLOT(setValue(int)));
    connect(m_spinbox,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
}
QLabel* ValoreSelezionato::getLabel() const{
    return m_label;
}
QSlider* ValoreSelezionato::getSlider() const{
    return m_slider;
}
QSpinBox* ValoreSelezionato::getSpinBox() const{
    return m_spinbox;
}
void ValoreSelezionato::set(const QString& s, unsigned int i, unsigned int max) {
    m_label->setText(s);
    if(i>max)
        i=max;
    m_slider->setValue(i);
    m_slider->setMaximum(max);
    m_spinbox->setMaximum(max);
}
ValoreSelezionato::~ValoreSelezionato() {
    delete m_label;
    delete m_slider;
    delete m_spinbox;
}
