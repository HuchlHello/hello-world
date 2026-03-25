#include "login_window.h"
#include "table_dialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent), m_usernameEdit(new QLineEdit(this)), m_passwordEdit(new QLineEdit(this)),
      m_loginButton(new QPushButton(tr("登录"), this)),
      m_userRepo(), m_loginUseCase(&m_userRepo)
{
    setWindowTitle("登录");
    resize(400, 200);

    m_passwordEdit->setEchoMode(QLineEdit::Password);

    auto *widget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(widget);

    auto *usernameLabel = new QLabel(tr("用户名"), this);
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(m_usernameEdit);

    auto *passwordLabel = new QLabel(tr("密码"), this);
    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(m_passwordEdit);

    mainLayout->addWidget(m_loginButton);

    widget->setLayout(mainLayout);
    setCentralWidget(widget);

    connect(m_loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
}

void LoginWindow::onLoginClicked()
{
    domain::UserCredentials credentials{m_usernameEdit->text(), m_passwordEdit->text()};
    bool ok = m_loginUseCase.execute(credentials);
    if (!ok)
    {
        QMessageBox::warning(this, tr("登录失败"), tr("用户名或密码错误，请重试。"));
        return;
    }

    QMessageBox::information(this, tr("登录成功"), tr("登录成功，正在打开表格界面。"));
    TableDialog dialog(this);
    dialog.exec();
}
