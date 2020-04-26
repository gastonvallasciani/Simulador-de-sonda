#ifndef PROTOCOL_GENERIC_H
#define PROTOCOL_GENERIC_H

#include <QString>

#define MAX_CAN_ACTIVE_ID 18

typedef enum
{
    PARSE_P,
    PARSE_1,
    PARSE_0,
    PARSE_01,
    PARSE_ID1,
    PARSE_ID2
}parseState_t;

typedef enum
{
    PARSE_INCOMPLETE,
    PARSE_CORRECT,
    PARSING,
    PROBE_ID_INCORRECT
}parseRta_t;


class protocolGeneric
{
    // Atributos
private:
    parseState_t  parseActualState;
    QByteArray    IdReceived;
    int           activeId;

    //Metodos
public:
    // Constructor
    protocolGeneric(parseState_t  parseActualState, int activeId);
    // Destructor
    ~protocolGeneric();
    // Setters
    void setParseActualState(parseState_t  parseActualState_);
    void setActiveId(int activeId);
    // Getters
    parseState_t getParseActualState(void);
    int getActiveId(void);
    // Metodos
    parseRta_t parseReceivedData(QByteArray dataReceived);
};

#endif // PROTOCOL_GENERIC_H
