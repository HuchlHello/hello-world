#ifndef TABLE_DIALOG_H
#define TABLE_DIALOG_H

#include <QDialog>
#include <QTableWidget>

class TableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TableDialog(QWidget *parent = nullptr);

private slots:
    void onCellChanged(int row, int /*column*/);

private:
    QTableWidget *m_table;
    bool m_isInserting;
};

#endif // TABLE_DIALOG_H