//Fixed Point Iteration Program V 1.0.0 / Programa de Iteracion de Punto Fijo V 1.0.0
#include "punto.h"
#include "ui_punto.h"

Punto::Punto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Punto)
{
    ui->setupUi(this);
    setWindowTitle("Metodo de Punto Fijo"); //Print the method's name in the window title
    //Connections from the user interface signals to slots
    connect(ui->ejecuta,SIGNAL(clicked()),this,SLOT(ejecutar()));
    connect(ui->vacia,SIGNAL(clicked()),this,SLOT(limpiar()));
}

Punto::~Punto()
{
    delete ui;
}
double Punto::g(double d){ //This function will return a valued equation
    return (5*exp(-d-1)); //Equation to valuate on this method
}

void Punto::ejecutar(){ //This slot will run the method when press the start button
    x=ui->initval->value(); //Collect the initial value provided by user and save in the x variable
    ea=ui->errora->value(); //Collect the accepted error introduced by user and save in the ea variable
    while(ei>ea){ // Cycle to control the iterations, the method will stop when error been minimal
        xr=g(x); //Valuate the function with "x" value and save it on "xr"
        ei=100*std::abs((xr-x)/xr); //Calculate the new relative error
        i++; // Sum one iteration
        x=xr; //Now "x" takes the value of the valued function, saved in "xr"
        if (i==100) //Iterations limit, if the method reaches this limit will stop
            break;
    }
    ui->Pantalla->display(x); //Show in the display the value of the found root
    ui->Iteracion->display(i); //Show the total of iterations
    ui->errormin->display(ei); //Show the minimum error found
}
void Punto::limpiar(){ //This slot will clear all fields from user interface when press the clear button
    ui->initval->setValue(0.0); //Clear the "valor inicial" spinbox
    ui->errora->setValue(0.0); //Clear the "error aceptado" spinbox
    ui->Pantalla->display(0.0); //Clear the roots display
    ui->Iteracion->display(0.0); //Clear the iterations display
    ui->errormin->display(0.0); //Clear the minimum error display
    xr=0; x=0; ea=0; i=0; // All variables goes to 0, for start over
    ei=100; // The initial error back to 100 percent, to start over the method
}
