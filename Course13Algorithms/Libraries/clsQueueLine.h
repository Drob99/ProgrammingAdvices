#pragma once
#include <iostream>
#include "../Libraries/clsDate.h"
#include <queue>

using namespace std;

class clsQueueLine
{
private:
    string _prefix = "";
    short _AverageServeTime = 0;
    short _TotalTickets = 0;

    class clsTicket
    {
    private:
        short _ID = 0;
        string _Prefix;
        string _TicketTime;
        short _WaitingClients = 0;
        short _AverageServeTime = 0;
        short _ExpectedServeTime = 0;

    public:
        clsTicket(string Prefix, short ID, short WaitingClients, short AverageServeTime)
        {
            _ID = ID;
            _Prefix = Prefix;
            _TicketTime = clsDate::GetSystemDateTimeString();
            _WaitingClients = WaitingClients;
            _AverageServeTime = AverageServeTime;
        }

        string Prefix()
        {
            return _Prefix;
        }

        short ID()
        {
            return _ID;
        }

        string FullID()
        {
            return _Prefix + to_string(_ID);
        }

        string TicketTime()
        {
            return _TicketTime;
        }

        short WaitingClients()
        {
            return _WaitingClients;
        }

        short ExpectedServeTime()
        {
            return _AverageServeTime * _WaitingClients;
        }

        void Print()
        {
            cout << "\n\t\t\t  _______________________\n";
            cout << "\n\t\t\t\t    " << FullID();
            cout << "\n\t\t\t    " << TicketTime();
            cout << "\n\t\t\t    Waiting Clients = " << WaitingClients();
            cout << "\n\t\t\t      Serve Time In";
            cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
            cout << "\n\t\t\t  _______________________\n";
        }

        void Update()
        {
            _WaitingClients--;
            _ExpectedServeTime -= _AverageServeTime;
        }
    };

    queue<clsTicket> _ServedClients;
    queue<clsTicket> QueueLine;

public:
    clsQueueLine(string prefix, int AverageServeTime)
    {
        _TotalTickets = 0;
        _prefix = prefix;
        _AverageServeTime = AverageServeTime;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket Ticket(_prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
        QueueLine.push(Ticket);
    }

    int WaitingClients()
    {
        return QueueLine.size();
    }

    string WhoIsNext()
    {
        if (QueueLine.empty())
            return "No Clients Left.";
        else
            return QueueLine.front().FullID();
    }

    void PrintInfo()
    {
        cout << "\n\t\t\t_________________________________";
        cout << "\n\n\t\t\t           Queue Info";
        cout << "\n\t\t\t_________________________________\n";
        cout << "\n\t\t\t  Prefix          = " << _prefix;
        cout << "\n\t\t\t  Total Clients   = " << _TotalTickets;
        cout << "\n\t\t\t  Served Clients  = " << ServedClients();
        cout << "\n\t\t\t  Waiting Clients = " << WaitingClients();
        cout << "\n\t\t\t_________________________________\n";
    }

    void PrintTicketsLineRTL()
    {
        if (QueueLine.empty())
        {
            cout << "\n\t\tTickets: No Tickets.";
        }
        else
            cout << "\n\t\tTickets: ";

        queue<clsTicket> temp_queue = QueueLine;
        while (!temp_queue.empty())
        {
            cout << " " << temp_queue.front().FullID() << " <-- ";
            temp_queue.pop();
        }

        cout << "\n";
    }

    void PrintTicketsLineLTR()
    {
        if (QueueLine.empty())
        {
            cout << "\n\t\tTickets: No Tickets.";
        }
        else
            cout << "\n\t\tTickets: ";

        queue<clsTicket> temp_queue = QueueLine;
        string TicketLine = "";

        while (!temp_queue.empty())
        {
            TicketLine = " " + temp_queue.front().FullID() + " --> " + TicketLine;
            temp_queue.pop();
        }

        cout << TicketLine;
        cout << "\n";
    }

    void PrintAllTickets()
    {
        cout << "\n\n\t\t\t       ---Tickets---";

        if (QueueLine.empty())
            cout << "\n\n\t\t\t     ---No Tickets---\n";

        queue<clsTicket> temp_queue = QueueLine;

        while (!temp_queue.empty())
        {
            temp_queue.front().Print();
            temp_queue.pop();
        }
        cout << "\n";
    }

    bool ServeNextClient()
    {
        if (QueueLine.empty())
            return false;

        queue<clsTicket> temp_queue;

        _ServedClients.push(QueueLine.front());
        QueueLine.pop();

        // Note: In real life, it is a paper. So this just updates my database.
        while (!QueueLine.empty())
        {
            QueueLine.front().Update();
            temp_queue.push(QueueLine.front());
            QueueLine.pop();
        }
        QueueLine = temp_queue;
        return true;
    }

    short ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }
};