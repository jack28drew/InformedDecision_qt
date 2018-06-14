#ifndef INFORMEDDECISION_H_
#define INFORMEDDECISION_H_ 

#include <QApplication>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QFile>
#include <QList>
#include <QTableWidget>
#include <QObject>

class InformedDecision : public QWidget {
    Q_OBJECT
public:
    explicit InformedDecision(QWidget *parent = 0);

public slots:
    void createOutputWidget(QString);

private:
    QVBoxLayout *mainLayout;
    QComboBox *studentType;
    QLabel *studentTypeLabel;
    QDoubleSpinBox *gpaSpinBox;
    QLabel *gpaSpinBoxLabel;
    QSlider *satSlider;
    QSpinBox *satSpinBox;
    QLabel *satLabel;
    QLineEdit *fundsInput;
    QLabel *fundsLabel;
    QListWidget *hobbiesList;
    QLabel *hobbiesLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTableWidget *universityList;
    QListWidget *majorsList;
    QLabel *majorsLabel;

    void createStudentTypeWidget();
    void createGPAWidget();
    void createSATWidget();
    void createFundsWidget();
    void createHobbiesWidget();
    void createButtons();
    void createUniversityList();
    void createMajorsList();
    void okButtonPressed();

    void createLayout();
};
#endif //INFORMEDDECISION_H_