#ifndef BASE58CHECKTRANSCODERWIDGET_H
#define BASE58CHECKTRANSCODERWIDGET_H

#include <QWidget>

class QCheckBox;
class QPlainTextEdit;

class Base58CheckTranscoderWidget : public QWidget
{
    Q_OBJECT
public:
    Base58CheckTranscoderWidget(QWidget *parent = 0);
private:
    void setupGui();

    QCheckBox *m_ClearSourceCheckbox;
    QPlainTextEdit *m_Lhs_Plaintext_Edit;
    QPlainTextEdit *m_Rhs_Base58encoded_Edit;
private slots:
    void handleEncodeClicked();
    void handleDecodeClicked();
};

#endif // BASE58CHECKTRANSCODERWIDGET_H
