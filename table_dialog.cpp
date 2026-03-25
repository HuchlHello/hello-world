#include "table_dialog.h"
#include <QVBoxLayout>
#include <QHeaderView>

TableDialog::TableDialog(QWidget *parent)
    : QDialog(parent), m_table(new QTableWidget(50, 7, this)), m_isInserting(false)
{
    setWindowTitle("表格界面");
    resize(900, 520);

    QStringList headers;
    headers << "ID" << "名字" << "条码" << "日期" << "批号" << "瓶号" << "备注";
    m_table->setHorizontalHeaderLabels(headers);
    m_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_table->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed);
    m_table->setSelectionBehavior(QAbstractItemView::SelectItems);
    m_table->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(m_table, &QTableWidget::cellChanged, this, &TableDialog::onCellChanged);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_table);
    setLayout(layout);
}

void TableDialog::onCellChanged(int row, int /*column*/)
{
    if (m_isInserting)
        return;

    if (row == m_table->rowCount() - 1)
    {
        m_isInserting = true;
        m_table->insertRow(m_table->rowCount());
        m_isInserting = false;
    }
}