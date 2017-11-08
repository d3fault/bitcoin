#include "base58checktranscoderwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QCheckBox>

#include "base58checktranscoder.h"

Base58CheckTranscoderWidget::Base58CheckTranscoderWidget(QWidget *parent)
    : QWidget(parent)
{
    setupGui();
}
void Base58CheckTranscoderWidget::setupGui()
{
    QVBoxLayout *backgroundLayout = new QVBoxLayout(this);
    m_ClearSourceCheckbox = new QCheckBox(tr("Clear Source On Click"));
    m_ClearSourceCheckbox->setChecked(true);
    backgroundLayout->addWidget(m_ClearSourceCheckbox, 0, Qt::AlignHCenter);

    QHBoxLayout *centerLayout = new QHBoxLayout();

    QVBoxLayout *lhs_Plaintext_Layout = new QVBoxLayout();
    lhs_Plaintext_Layout->addWidget(new QLabel(tr("Plain Text:")));
    m_Lhs_Plaintext_Edit = new QPlainTextEdit();
    lhs_Plaintext_Layout->addWidget(m_Lhs_Plaintext_Edit, 1);

    QVBoxLayout *mid_encodeDecodeButtons_Layout = new QVBoxLayout();
    QPushButton *encodeButton = new QPushButton(tr("-> Encode ->"));
    mid_encodeDecodeButtons_Layout->addWidget(encodeButton);
    QPushButton *decodeButton = new QPushButton(tr("<- Decode <-"));
    mid_encodeDecodeButtons_Layout->addWidget(decodeButton);

    QVBoxLayout *rhs_Base58encoded_Layout = new QVBoxLayout();
    rhs_Base58encoded_Layout->addWidget(new QLabel(tr("Base58 Check Encoded:")));
    m_Rhs_Base58encoded_Edit = new QPlainTextEdit();
    rhs_Base58encoded_Layout->addWidget(m_Rhs_Base58encoded_Edit, 1);

    centerLayout->addLayout(lhs_Plaintext_Layout);
    centerLayout->addLayout(mid_encodeDecodeButtons_Layout);
    centerLayout->addLayout(rhs_Base58encoded_Layout);

    backgroundLayout->addLayout(centerLayout);

    connect(encodeButton, &QPushButton::clicked, this, &Base58CheckTranscoderWidget::handleEncodeClicked);
    connect(decodeButton, &QPushButton::clicked, this, &Base58CheckTranscoderWidget::handleDecodeClicked);

    m_Lhs_Plaintext_Edit->setFocus();
}
void Base58CheckTranscoderWidget::handleEncodeClicked()
{
    QByteArray plaintext = m_Lhs_Plaintext_Edit->toPlainText().toUtf8();
    if(plaintext.isEmpty())
        return;
    if(m_ClearSourceCheckbox->isChecked())
        m_Lhs_Plaintext_Edit->clear();

    QByteArray encoded = Base58CheckTranscoder::encodeBase58Check(plaintext);

    m_Rhs_Base58encoded_Edit->clear();
    m_Rhs_Base58encoded_Edit->appendPlainText(QString(encoded));
}
void Base58CheckTranscoderWidget::handleDecodeClicked()
{
    QByteArray encoded = m_Rhs_Base58encoded_Edit->toPlainText().toUtf8();
    if(encoded.isEmpty())
        return;

    QByteArray decoded_aka_Plaintext;
    bool checkOk = Base58CheckTranscoder::decodeBase58Check(encoded, decoded_aka_Plaintext);

    m_Lhs_Plaintext_Edit->clear();
    if(!checkOk)
    {
        QMessageBox::critical(this, tr("Check During Decode Failed"), tr("The Checksum (The 'Check' in Base58Check) embedded in the encoded data was invalid. The encoded data was modified, so decoding has failed."));
        return;
    }
    if(m_ClearSourceCheckbox->isChecked())
        m_Rhs_Base58encoded_Edit->clear();
    m_Lhs_Plaintext_Edit->appendPlainText(QString(decoded_aka_Plaintext));
}
