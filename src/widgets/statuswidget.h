#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

namespace GUI
{

class StatusWidget : public QWidget
{
    Q_OBJECT
public:
    StatusWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        createWidgets();
    }

    enum class StatusType : int
    {
        UNKNOWN = 0,
        IDLE,
        ALARM,
        RUN,
        HOME,
        HOLD0,
        HOLD1,
        QUEUE,
        CHECK,
        DOOR,
        JOG,
        NOTCONNECTED,
        PORTOPEN
    };

    static StatusType statusFromString(const QString &statusStr);
    
    void reset()
    {
        setStatus(StatusType::UNKNOWN);
    }

    void setStatus(StatusType stat);

    StatusType getStatus() const noexcept
    {
        return m_status;
    }

    void setColors(const QString &bkcolor, const QString &txtcolor);

protected:
    void createWidgets();

    StatusType   m_status{StatusType::UNKNOWN};
    QLabel      *m_name{nullptr};
    QLabel      *m_statusTxt{nullptr};
    QHBoxLayout *m_layout{nullptr};
};

};