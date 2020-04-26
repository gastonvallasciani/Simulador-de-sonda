#include "protocolGeneric.h"

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodo Constructor

protocolGeneric::protocolGeneric(parseState_t  parseActualState, int activeId)
{
    this->parseActualState = parseActualState;
    this->activeId         = activeId;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodo Destructor

protocolGeneric::~protocolGeneric()
{

}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Setters
void protocolGeneric::setParseActualState(parseState_t  parseActualState_)
{
    parseActualState = parseActualState_;
}

void protocolGeneric::setActiveId(int activeId)
{
    this->activeId = activeId;
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Getters

parseState_t protocolGeneric::getParseActualState(void)
{
    return(parseActualState);
}

int protocolGeneric::getActiveId(void)
{
  return(this->activeId);
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodos
parseRta_t protocolGeneric::parseReceivedData(QByteArray dataReceived)
{
    bool ok;

    switch(parseActualState)
    {
        case PARSE_P:
        if(dataReceived == "P")
        {
            parseActualState = PARSE_1;
        }
        break;
        case PARSE_1:
        if(dataReceived == "1")
        {
            parseActualState = PARSE_0;
        }
        else
        {
            parseActualState = PARSE_P;
            return(PARSE_INCOMPLETE);
        }
        break;
        case PARSE_0:
        if(dataReceived == "0")
        {
            parseActualState = PARSE_01;
        }
        else
        {
            parseActualState = PARSE_P;
            return(PARSE_INCOMPLETE);

        }
        break;
        case PARSE_01:
        if(dataReceived == "0")
        {
            parseActualState = PARSE_ID1;
        }
        else
        {
            parseActualState = PARSE_P;
            return(PARSE_INCOMPLETE);
        }
        break;

        break;
        case PARSE_ID1:
            IdReceived = dataReceived;
            parseActualState = PARSE_ID2;
            if((IdReceived.toInt(&ok) != 0) && ((IdReceived.toInt(&ok) != 1)))
            {
                parseActualState = PARSE_P;
                return(PARSE_INCOMPLETE);
            }
        break;
        case PARSE_ID2:
            IdReceived.insert(1,dataReceived);

            parseActualState = PARSE_P;
            if(IdReceived.toInt(&ok) == activeId)
            {
               return(PARSE_CORRECT);
            }
            else
            {
               return(PROBE_ID_INCORRECT);
            }
        break;
    }
    return(PARSING);
}


