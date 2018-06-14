#include "InformedDecision.h"

InformedDecision::InformedDecision(QWidget *parent) : QWidget(parent) {
    setWindowTitle("InformedDecision");
    resize(500, 500);
    createLayout();
    setLayout(mainLayout);
}

void InformedDecision::createStudentTypeWidget() {
    QStringList list;
    list << "High School Student" << "University Freshman" << "University Sophomore";

    studentType = new QComboBox;
    studentType->addItems(list);

    studentTypeLabel = new QLabel;
    studentTypeLabel->setText("StudentType: ");
}

void InformedDecision::createGPAWidget() {
    gpaSpinBox = new QDoubleSpinBox;
    gpaSpinBox->setDecimals(1);
    gpaSpinBox->setSingleStep(0.1);
    gpaSpinBox->setRange(0,4);
    gpaSpinBox->setValue(3.0);

    gpaSpinBoxLabel = new QLabel;
    gpaSpinBoxLabel->setText("Current GPA: ");
}

void InformedDecision::createSATWidget() {
    satSlider = new QSlider(Qt::Horizontal);
    satSpinBox =  new QSpinBox;
    satSlider->setRange(400, 1600);
    satSpinBox->setRange(400, 1600);
    satSlider->setValue(1000);
    satSpinBox->setValue(1000);

    QObject::connect(satSlider, SIGNAL(valueChanged(int)), satSpinBox, SLOT(setValue(int)));
    QObject::connect(satSpinBox, SIGNAL(valueChanged(int)), satSlider, SLOT(setValue(int)));

    satLabel = new QLabel;
    satLabel->setText("SAT Score: ");
}

void InformedDecision::createFundsWidget() {
    fundsInput = new QLineEdit;
    fundsLabel = new QLabel;
    fundsLabel->setText("Available Funds: ");
}

void InformedDecision::createHobbiesWidget() {
    QStringList hobbies;
    hobbies << "3D Printing" << "Cooking" << "Dance" << "Drawing" << "Exercise" << "Camping & Hiking"
                << "Flying" << "Photography" << "Swimming";

    hobbiesList = new QListWidget;
    hobbiesList->addItems(hobbies);

    QListWidgetItem *item = 0;
    for(int i=0; i < hobbiesList->count(); i++) {
        item = hobbiesList->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

    hobbiesLabel = new QLabel;
    hobbiesLabel->setText("Hobbies");
}

void InformedDecision::createButtons() {
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");
    QObject::connect(cancelButton, SIGNAL(pressed()), this, SLOT(close()));
}

void InformedDecision::createUniversityList() {
    QFile file("universities.txt");
    file.open(QIODevice::ReadOnly);

    QStringList columnNames;
    columnNames << "University" << "GPA" << "SAT Score" << "Tuition";

    universityList = new QTableWidget;
    universityList->setColumnCount(4);
    universityList->setColumnWidth(1,"");
    universityList->setColumnWidth(2,"");
    universityList->setColumnWidth(3,"");
    universityList->setColumnWidth(0,"");
    universityList->setHorizontalHeaderLabels(columnNames);

    while(!file.atEnd()) {
        QString line = file.readLine();
        QStringList info = line.split(',');
        universityList->insertRow(universityList->rowCount());
        universityList->setItem(universityList->rowCount()-1, 0, new QTableWidgetItem(info[0]));
        universityList->setItem(universityList->rowCount()-1, 1, new QTableWidgetItem(info[1]));
        universityList->setItem(universityList->rowCount()-1, 2, new QTableWidgetItem(info[2]));
        universityList->setItem(universityList->rowCount()-1, 3, new QTableWidgetItem(info[3]));
    }
}

void InformedDecision::createLayout() {
    mainLayout = new QVBoxLayout;

    createStudentTypeWidget();
    QHBoxLayout *studentTypeLayout = new QHBoxLayout;
    studentTypeLayout->addWidget(studentTypeLabel);
    studentTypeLayout->addWidget(studentType);

    createGPAWidget();
    QHBoxLayout *gpaLayout = new QHBoxLayout;
    gpaLayout->addWidget(gpaSpinBoxLabel);
    gpaLayout->addWidget(gpaSpinBox);

    createSATWidget();
    QHBoxLayout *satLayout = new QHBoxLayout;
    satLayout->addWidget(satLabel);
    satLayout->addWidget(satSlider);
    satLayout->addWidget(satSpinBox);

    createFundsWidget();
    QHBoxLayout *fundsLayout = new QHBoxLayout;
    fundsLayout->addWidget(fundsLabel);
    fundsLayout->addWidget(fundsInput);

    QHBoxLayout *bottomRow = new QHBoxLayout;

    createHobbiesWidget();
    QHBoxLayout *hobbiesLayout = new QHBoxLayout;
    hobbiesLayout->addWidget(hobbiesLabel);
    hobbiesLayout->addWidget(hobbiesList);

    createButtons();
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    bottomRow->addLayout(hobbiesLayout);
    bottomRow->addLayout(buttonLayout);

    createUniversityList();


    mainLayout->addLayout(studentTypeLayout);
    mainLayout->addLayout(gpaLayout);
    mainLayout->addLayout(satLayout);
    mainLayout->addLayout(fundsLayout);
    mainLayout->addLayout(bottomRow);
    mainLayout->addWidget(universityList);
}